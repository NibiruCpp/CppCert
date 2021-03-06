/*
equal_range() function is a combination of functions lower_bound() and upper_bound(). 
It returns a range containing all elements equal to the value in the sorted 
range [first, last). The range is defined by two iterators, one pointing to the 
first element that is not less than value and another, pointing to the first 
element greater than value. The first version uses the less operator (<) to compare 
the elements, the second version uses the given comparison function comp.
*/

#include <deque>
#include <string>
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

template <class T> 
void print(T start, T end) 
{
    for ( ;start != end; ++start) {
        std::cout << *start << " "; 
    }
}

int compare(int a, int b)
{
	return b < a;
}

int main()
{
	int t[]={1, 10, 8, 4, 5, 6, 3, 9, 7, 2};
	deque <int> d1(t,t+10);
	
	cout<<"Source collection:" << endl;
	cout<<"d1: "; 	
	print(d1.begin(), d1.end());
	cout<<endl;
	
	cout<<"Sorting is required - ascending order:" << endl;
	sort(d1.begin(), d1.end());
	cout<<"d1: "; 	
	print(d1.begin(), d1.end());
	cout<<endl;

	cout<<"Finding range [4,6]:" << endl;
	deque<int>::iterator it1 =lower_bound(d1.begin(), d1.end(), 4);
	deque<int>::iterator it2 = upper_bound(d1.begin(), d1.end(),6);
	print(it1,it2); 
	cout<<endl;
	
	cout<<"Finding single value range using equal_bounds" << endl;
	pair<deque<int>::iterator, deque<int>::iterator> p = equal_range(d1.begin(), d1.end(),4);
	print(p.first, p.second); 
	cout<<endl<<endl;

	cout<<"--------------------------------------------------" << endl;

	cout<<"Sorting is required - descending order:" << endl;
	sort(d1.begin(), d1.end(), compare);
	cout<<"d1: "; 	print(d1.begin(), d1.end());cout<<endl;

	cout<<"Finding range [6,4]:" << endl;
	it1 =lower_bound(d1.begin(), d1.end(), 6, compare);
	it2 = upper_bound(d1.begin(), d1.end(), 4, compare);
	print(it1,it2); cout<<endl;
	cout<<"Finding single value range using equal_bounds" << endl;
	p = equal_range(d1.begin(), d1.end(),4, compare);
	print(p.first, p.second); cout<<endl;

	return 0;
}