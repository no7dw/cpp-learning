#include <map>
#include <iostream>
#include <string>
using namespace std;

typedef map<int, string> MAP_INT_STR;
typedef MAP_INT_STR::iterator MAP_ITERATOR;
typedef MAP_INT_STR::const_iterator MAP_CONST_ITERATOR;

typedef MAP_INT_STR::reverse_iterator MAP_REVERSE_ITERATOR;
typedef MAP_INT_STR::const_reverse_iterator MAP_CONST_REVERSE_ITERATOR;

typedef pair<int, string> PAIR_INT_STR;

template <class MAP_CONST_ITERATOR>


void printf_map_item(MAP_CONST_ITERATOR &it)
{
	cout<< (*it).first << " , " << (*it).second << endl;	
}
void printf_map_item(MAP_REVERSE_ITERATOR &rit)
{
	cout<< (*rit).first << " , " << (*rit).second << endl;	
}

void display_all(const MAP_INT_STR &li)
{
	MAP_CONST_ITERATOR iter;
	for(iter = li.begin(); iter!= li.end(); iter++)
		printf_map_item(iter);
	cout << "\n";	
}

void display_all_r(const MAP_INT_STR &li)
{
	MAP_CONST_REVERSE_ITERATOR iter;
	for(iter = li.rbegin(); iter!= li.rend(); iter++)
		printf_map_item(iter);
	cout << "\n";	
}

int main(void)
{
	MAP_INT_STR c1;
	PAIR_INT_STR pairs[5] = {
		PAIR_INT_STR(1, string("one")),
		PAIR_INT_STR(2, string("two")),
		PAIR_INT_STR(3, string("three")),
		PAIR_INT_STR(4, string("four")),
		PAIR_INT_STR(5, string("five"))	
	};
	MAP_INT_STR c2(pairs, pairs+5);
	MAP_INT_STR c3(c2);
	
	if(c1.empty())
		cout << "c1 is empty" << endl;
	else
		cout << "c1 is not empty " << endl;
	
	display_all(c2);
	display_all_r(c2);
	
	//insert
	pair<MAP_ITERATOR, bool> result;
	for(int count_insert = 0; count_insert<2 ; count_insert++)
	{
		result = c1.insert(MAP_INT_STR::value_type(6, string("six")));
		if(result.second)
		{	
			cout<< "a paire of key/data was inserted in c1, *(result.first) = " ; 
			printf_map_item( (result.first) );		
		}
		else
			cout << "(6, string(\"six\") inserted fail\n" ;
	}
	
	c1.insert(pairs, pairs+5);
	c1.insert(c1.begin(), PAIR_INT_STR(0, string("zero")));
	
	//find
	MAP_ITERATOR iter1 = c1.find(6);
	if(iter1!=c1.end())
	{
		cout << "c1 contains pair: " ;
		printf_map_item(iter1);
	}
	else
	{
		cout << "c1 does NOT contains  any element with key = 6 " ;		
	}
	
	//[] assign
	c1[8] = "eight";
	c1[9] = "nine";
	c1[11] = "elevent";
	cout << "last key/data in c1 = ";
	MAP_REVERSE_ITERATOR riter1 = c1.rbegin();
	printf_map_item(riter1);
	
	cout << "max elements which c1 can hold using current cllocator " << c1.max_size() << endl;	
	cout << "c1.size() = " << c1.size() << "\t c2.size() = " << c2.size() << endl;
	
	c1.swap(c2);
	cout << "c1 :" << endl;
	display_all(c1);
	cout << "c2 :" << endl;
	display_all(c2);
	
	//get_allocator
	MAP_INT_STR::allocator_type al = c3.get_allocator();
	
	//key_comp
	MAP_INT_STR::key_compare kc = c1.key_comp();
	cout << "use function object kc to find less of(10, 4 ) " << endl;
	if(kc(10,4))
		cout << "kc(10,4) is true ,which means 10 < 4 " << endl;
	else
		cout << "kc(10,4) is false ,which means 10 > 4 " << endl;
	
	MAP_INT_STR::value_compare vc = c1.value_comp();
	cout << "pairs[0] = (" << pairs[0].first << " , " << pairs[0].second << " )\n";
	cout << "pairs[1] = (" << pairs[1].first << " , " << pairs[1].second << " )\n";
	
	if(vc(pairs[0], pairs[1]))
		cout << "pairs[0] < pairs[1]" << endl;
	else
		cout << "pairs[0] > pairs[1]" << endl;
		
	cout << "c2 :"<< endl ;
	display_all(c2);
	iter1 = c2.upper_bound(6);//find end of subsequeue that matching given key
	cout<< "first map element with key 6 > ";
	printf_map_item(iter1);	
	iter1 = c2.lower_bound(6);//find beginning of subsequeue that matching given key
	cout<< "first map element with key 6 = ";
	printf_map_item(iter1);	
	
	pair<MAP_ITERATOR, MAP_ITERATOR> pair2 = c2.equal_range(6); //find a subsequeue that matching given key
	cout << "using c2.equal_range(6) ,first map element with key > 6 ";
	printf_map_item(pair2.second);	
	
	if(c2.count(8) == 1 )
		cout << "c2 contains element with key 8 " << endl;
	else
		cout << "c2 does NOT contains element with key 8 " << endl;
	
	cout << "c1 erase  c2.size() = " << c2.size() << endl;
	c2.erase(c2.begin());
	cout << "after c2 erase begin c2.size() = " << c1.size() << endl;
	cout << "first key/data paire of c2 is : " ;
	iter1 = c2.begin();
	printf_map_item(iter1);
	
	c1.erase(c1.begin(), c1.end());
	cout << "after c1 erase  c1.size() = " << c1.size() << endl;
	for(int count_insert = 0; count_insert<2 ; count_insert++)
	{
		if(c2.erase(8)==1)//return number of element erased
			cout << " erased \n";
		else
			cout << "c2 does NOT contains element with key 8 \n";
	}	
	
}

