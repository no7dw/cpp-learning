#include <list>
#include <iostream>
using namespace std;

//display in order
void display_all(const list<int> &li)
{
	list<int>::const_iterator iter;
	for(iter = li.begin(); iter!= li.end(); iter++)
		cout << *iter << " , ";
	cout << "\n";	
}
//display in rorder
void display_all_r(const list<int> &li)
{
	list<int>::const_reverse_iterator riter;
	for(riter = li.rbegin(); riter!= li.rend(); riter++)
		cout << *riter << " , ";
	cout << "\n";	
}
int main( void)
{
	//default constructor
	list<int> c1;
	list<int> c2(10,4);
	//copy constructor
	list<int> c3(c2);
	
	int ai[]={0,1,2,3,4,5};
	int i;
	list<int> c4;
	//get_allocator
	list<int>::allocator_type a1 = c4.get_allocator();
	
	for( i = 0; i < 5;i++ )
		c4.push_back(i);
	
	//range copy constructor
	list<int> c5(c4.begin(), c4.end());
	
	cout << "c4(use begin, end) ";
	display_all(c4);
	
	cout << "\n";
	
	cout << "c4(use rbegin, rend) ";
	display_all_r(c4);		
	
	cout << "last element in c2 = " << c2.back() << "\n"; 
	cout << "first element in c2 = " << c2.front() << "\n";
	cout << "number of elements in c2 = " << c2.size() << "\n" ;	
	cout << "max number of elements c2 can hold using current allocator = " << c2.max_size() << "\n";
	
	c3.erase(c3.begin(), c3.end());
	
	c2.clear();
	
	if(c2.empty() ==  true)
		cout << "c2 is now empty" << std::endl;
	
	//resize @para1: new_size ;@para2: value
	c2.resize(10, 30);
	cout << "number of elements in c2 = " << c2.size() << "\n" ;	
	cout << "last element in c2 = " << c2.back() << "\n"; 
	cout << "first element in c2 = " << c2.front() << "\n";
		
	c2.push_front(25);
	c2.push_back(55);
	
	cout << "number of elements in c2 = " << c2.size() << "\n" ;	
	cout << "first element in c2 = " << c2.front() << "\n";
	c2.pop_back();
	cout << "number of elements in c2 = " << c2.size() << "\n" ;	
	cout << "last element in c2 = " << c2.back() << "\n"; 
	c2.pop_front();
	cout << "first element in c2 = " << c2.front() << "\n";
	
	c3.push_back(20);
	cout << "\n swap \n";	
	cout << "number of elements in c2 = " << c2.size() << "\n" ;	
	cout << "number of elements in c3 = " << c3.size() << "\n" ;
	cout << "c2 = ";
	display_all(c2);
	cout << "c3 = ";
	display_all(c3);
	c3.swap(c2);
	
	cout << "number of elements in c2 = " << c2.size() << "\n" ;	
	cout << "number of elements in c3 = " << c3.size() << "\n" ;	
	cout << "c2 = ";
	display_all(c2);
	cout << "c3 = ";
	display_all(c3);
	
	c1.insert(c1.begin(), 20);
	cout << "c1 = ";
	display_all(c1);
	
	c3.insert(c3.begin(), 4, 10);
	c3.insert(c3.end(), c5.begin(), c5.end());	
	
	c3.reverse();
	display_all(c3);
	
	c3.remove(30);
	cout << "after remove all the occurennces of 30 in c3 , c3 = ";
	display_all(c3);
	
	c2.insert(c2.begin(), 4, 10);
	c2.insert(c2.begin(), 5);
	cout<< "c2 = " ;
	display_all(c2);
	c2.remove_if(bind2nd(not_equal_to<int>(), 10) );
	cout<< "remove_if c2 = " ;
	display_all(c2);
	
	c3.insert(c3.begin(), 35);
	c3.sort();
	cout << "sort c3 = " ;
	display_all(c3);
	
	//remove duplicate elements
	c2.insert(c2.end(), 5);//insert before ,so we can insert before end()
	c2.unique();
	cout << " After unique c2 = " ;
	display_all(c2);
	
	cout << "before splice \n";
	cout << "c4 = ";
	display_all(c4);
	cout << "c3 = ";
	display_all(c3);
	cout << "c2 = ";
	display_all(c2);
	cout << "c1 = ";
	display_all(c1);
	c3.splice(c3.end(), c2);//insert the whole list
	c3.splice(c3.end(), c4, c4.begin());//insert only the pos
	c3.splice(c3.end(), c1, c1.begin(), c1.end());//insert the range
	
	cout << "after splice \n";
	cout << "c4 = ";
	display_all(c4);
	cout << "c3 = ";
	display_all(c3);
	cout << "c2 = ";
	display_all(c2);
	cout << "c1 = ";
	display_all(c1);
	
	c3.sort();
	c3.unique();
	cout << "sort and unique c3 = ";
	display_all(c3);
	
}
