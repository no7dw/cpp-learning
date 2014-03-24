#include <set>
#include <iostream>
using namespace std;
//display in order
void display_all(const multiset<int> &li)
{
	multiset<int>::const_iterator iter;
	for(iter = li.begin(); iter!= li.end(); iter++)
		cout << *iter << " , ";
	cout << "\n";	
}
//display in rorder
void display_all_r(const multiset<int> &li)
{
	multiset<int>::const_reverse_iterator riter;
	for(riter = li.rbegin(); riter!= li.rend(); riter++)
		cout << *riter << " , ";
	cout << "\n";	
}

int main()
{
	//default constructor
	multiset<int> c1;
	int ai[] = {0,0,1,1,2,2,3,4};
	//with range
	multiset<int> c2(ai ,ai+8);
	multiset<int> c3(c2);
	multiset<int>::iterator iter;	
	if(c1.empty())
		cout << "multiset c1 is empty \n" ;
	else
		cout << "multiset c1 is NOT empty \n" ;
		
	cout << "c2 (use begin ,end) = ";
	display_all(c2);
	cout << "c2 (use rbegin ,rend) = ";
	display_all_r(c2);
	
	c1.insert(ai, ai+4);
	c1.insert(1);
	cout << "Number elements in c1 that match 1 = " << c1.count(1) << endl;
	
	//find
	multiset<int>::const_iterator citer  = c1.find(3);
	if(citer != c1.end())
		cout <<"c1 contains element3, *citer = "<< *citer << "\n";
	
	cout << "c1.max_size = " << c1.max_size() << "\n";
	
	c1.insert(4);
	c2.swap(c1);
	
	cout<< "The last element of c2 = " << *(c2.rbegin()) << endl;
	
	c1.clear();
	cout << "after clear c1.size = " << c1.size() << endl;
	
	//get_allocator
	multiset<int>::allocator_type a1 = c1.get_allocator();
	
	c2.insert(7);
	c2.insert(8);	
	//key_compare
	multiset<int>::key_compare kc = c2.key_comp();
	bool result = kc(2,3);
	if(result)
		cout << "kc is function object used by c2. kc(2,3) = true \n" ;
	else
		cout << "kc is function object used by c2. kc(2,3) = false \n" ;
	
	//val_compare
	multiset<int>::value_compare vc = c2.value_comp();
	result = vc(12,3);
	if(result)
		cout << "vc is function object used by c2. vc(12,3) = true \n" ;
	else
		cout << "vc is function object used by c2. vc(12,3) = false \n" ;
	
	cout<< "*(c2.upper_bound(4))" << *(c2.upper_bound(4)) << endl;
	cout<< "*(c2.lower_bound(4))" << *(c2.lower_bound(4)) << endl;
	
	pair<multiset<int>::const_iterator , multiset<int>::const_iterator> pr1 = c2.equal_range(3) ;
	cout<< "*(pr1.first) = " << *(pr1.first) << "\t" <<  " *(pr1.second) " <<*(pr1.second) << endl;
	
	if(c3.erase(1)!= 0)
		cout << "c3 does not contain 1 anymore\n";
	else
		cout <<  "No elements in c3 match key 1";
	
	int c2begin = *(c2.begin()) ;
	cout << "*(c2.begin()) = "<< c2begin << endl;
	
	c2.erase(c2.begin());
	c2.count(c2begin);
	//if(( c2.erase(c2.begin())) != c2.end())
	if(c2.count(c2begin) == 0)
		cout << "c2 does not contain "<< c2begin<<" anymore\n";
	else
		cout <<  "No elements in c2 match key " << c2begin;
		
	c3.erase(c3.begin(), c3.end());
	cout << "after c3.erase(c3.begin(), c3.end()) c3.size() = " << c3.size() << "\n";
	
	//set does NOT allow to contain 2 same key
	set<int> si;	
	pair<set<int>::iterator, bool> prs;
	for(int inserttimes = 0; inserttimes < 2; inserttimes ++)
	{
		prs = si.insert(1);
		if(prs.second)//true ----it was actully insert
			cout << "element 1 was insert in s1 successfully" << endl;
		else
			cout << "element 1 already exists in c1 and *(prs.first) = " << *(prs.first) << endl; //first --- point to the element
	}
}