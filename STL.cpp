#include <bits/stdc++.h>

Maximum size of an array inside int main ( ) of int, double or char datatype is 10^6.
Maximum size of an array inside int main ( ) of bool datatype is 10^7.

Maximum size of an array declared globally of int, double or char datatype is 10^7.
Maximum size of an array declared globally of bool datatype is 10^8.

If this size exceeds, then we'll get segmentation error!



ARRAY

#declaration of an array
array <datatype, size> array_name;
array <int, 5> arr;

array <int, 3> arr;  -> {?, ?, ?}
array <int, 5> arr = {1};   -> {1, 0, 0, 0, 0}   
arr.fill(10); ->  {10, 10, 10, 10, 10} 
arr.at(index) to refer an element;

array <int, 5> arr = {1, 3, 4, 5, 6}; 
	
    for(auto it: arr.begin(); it!=arr.end();it++) {
		cout << *it << " "; 
	}
 
	for(auto it: arr.rbegin(); it>arr.rend();it++) {
		cout << *it << " "; 
	}
 
	for(auto it: arr.end() - 1; it>=arr.begin();it--) {
		cout << *it << " "; 
	}
 
 	for(auto it: arr) {
		cout << it << " "; 
	}

    arr.size(), arr.front(), arr.back();



VECTOR

vector <datatype> vector_name;
vector <int> vec;
vec.push_back(), vec.pop_back(), vec.emplace_back(), ;
vec.clear();  --> erase all elements at once {} ;
vec.insert(iterator, value); --> insert value at the position on which iterator is pointing
vec.emplace_back() is little bit faster than vec.push_back(). ;

vec.emplace(vec.begin(), num) is used to insert an element at the front of the vector

auto it = find (vec.begin(), vec.end(), key) will return an iterator to the key if its found. Else it will return vec.end().

vector<int> vec1(4, 0);  -> {0,0,0,0} ;
vector<int> vec2(4, 10);  -> {10,10,10,10} ;

copy the entire vec2 into vec3 ;
vector<int> vec3(vec2.begin(), vec2.end()); -> [) ;
vector<int> vec3(vec2);

vector<int> vec = {1,3,5,4};
vector<int> vec1(vec.begin(), vec.begin() + 2);   -> {1, 3}  ;

to defining 2d vectors ;
vector<vector<int>> vec; 

it is vector itself ;
for printing 2-D vector ;
for(auto vctr: vec) 
{
    for(auto it: vctr) 
    {
        cout << it << " "; 
    }
    
    cout << endl; 
}

define 10 x 20  ;
vector<vector<int>> vec(10, vector<int> (20, 0)); 

10 x 20 x 30  int arr[10][20][30]  ;
vector<vector<vector<int>>> vec(10, vector<vector<int>> vec(20, vector<int> (30, 0))) ;



SET

set <datatype> set_name;
Insertion and Deletion in set takes O(logn) time. ;

set <int> st;
st.insert(num), st.emplace(num) ;
st.emplace(num) is little bit faster than st.insert(num) ;

st.erase(iterator)  st.erase(st.begin()) ;
st.erase(startIterator, endIterator) ;
st.erase(key)  st.erase(5) ;

auto it = st.find(num) will return the iterator pointing to the number present in the set. ; 
                        If the num is not present, then it will point to st.end(). ;

Hence, if (st.find(num) != st.end()) means the number is present in the set. ;


unordered_set <datatype> set_name;
The values will be stored in random order. ;
Average time of operation = O(1) ;
Worst case = O(n) ;


multiset <datatype> set_name;
Can store duplicate values in sorted fashion ;
ms.insert(num), ms.emplace(num) ;
ms.count(num) 	gives the no .of times of occurrence of the number ;
ms.erase(num) 	all the instances will be deleted ;
auto it = ms.find(num) returns iterator pointing to the first element of num ;
ms.clear(), ms.erase(ms.begin(), ms.end())     deletes the entire set ;
ms.erase(ms.find(num)) 		This will erase only first instance of the number. ;
ms.erase(iterator)		This will erase only first instance at which the iterator is pointing


MAP

Time complexity of operations = O(logn) ;
map <datatype1, datatype2> map_name;
Map only stores unique keys. ;
It stores everything in sorted order. ;
datatype1 is the key. ;
Map is sorted always according to the keys. ;

mp["keyur"] = 25;
mp["keyur"] = 30;
As map only stores unique keys, 30 will be overwritten and now the key keyur will have 30. ;

mp.emplace(datatype1, datatype2) is slightly faster then mp[datatype1]++  ;
mp.find(key)	returns the iterator pointing to the key ;

mp.erase(key) 	deletes the key from the map ;
mp.erase(iterator), mp.erase(iterator1, iterator2) 	deletes elements in the iterator range ;
mp.clear()	deletes all the keys from the map ;

mp.empty() returns true if the map is empty ;

mp.count(key) 	will always return 1 if the key is present in the map ;

printing map 
for(auto it: mpp) {
	cout << it.first << " " << it.second << endl; 
}

for(auto it = mpp.begin(); it!=mpp.end();it++) {
	cout << it->first << " " << it->second << endl; 
}


unordered_map <datatype1, datatype2> map_name ; 
Average time complexity of operations = O(1) ;
Worst case time complexity = O(n) ;
Pair of unordered map cannot be defined ;
unordered_map <pair<int, int>, int> mp is not possible ;


multimap<datatype1, datatype2> map_name ;
It can store duplicate keys. Similar to multiset ;

Pair class
pair<int,int> pr = {1,2}; 
Elements are accessed by dot. ;
pr.first = 1 		pr.second = 2 ;
pair<pair<int,int>, pair<int,int>> pr = {{1,2},{2, 4}};
pr.first.first = 1  pr.second.second = 4 	pr.first.second = 2 ;



STACK

stack<datatype> stack_name ;
stack<int> st ;
st.push(num), st.emplace(num) ;
st.top()	prints the top element ;
st.pop()	deletes the top element ;
st.empty() 		returns true if the stack is empty ;

Always check if the stack is non-empty before using st.top() ;



QUEUE

Time complexity = O(1) 	except deletion. Deletion takes O(n) time. ;
queue<datatype> queue_name ;  
queue<int> q ;
q.push(num), q.emplace(num) ;
q.top() ;
q.front() ;
q.pop() ;
q.empty() ;

Always check if the queue is non-empty before using q.top() ;



PRIORITY QUEUE
It uses the concept of heap sort. ;
It contains all the elements in descending order. Maximum element will be first in the queue. ;

priority_queue<datatype> queue_name ;
priority_queue<int> pq ;
pq.push(num), pq.emplace(num) ;  
pq.top() ;
pq.front() ;
pq.pop() ;
pq.empty() ;

Always check if the priority queue is non-empty before using pq.top() ;

priority_queue<pair<int,int>> pq ;  
If the first element in the pair is same then it will store according to second element ;

priority_queue<int, vector<int>, greater<int>> pq ;
This is minimum priority queue. Minimum element will be first in the queue. ;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq ;



DEQUEUE

dequeue<datatype> queue_name ;
dequeue<int> dq ;

push_front(key), push_back(key), pop_front(), pop_back() ;
begin(), end(), rbegin(), rend(), size(), clear(), empty(), at(index) ;



LIST

list<datatype> list_name ;
list<int> ls; 

push_front(key), push_back(key), pop_front(), pop_back() ;
begin(), end(), rbegin(), rend(), size(), clear(), empty(), at(index) ;
remove(key) takes O(1) time to remove/delete the element from the list.  ;



BITSET 
It stores only 0 or 1 ; 

bitset<length> name;
bitset<5> bt ;

bt.all() will return true if all the bits are set i.e. all the bits are 1 ; 
bt.any() will return true if any one of the bit is set i.e. any one of the bit is 1 ;
bt.count() will print the no. of 1's ;
bt.flip(position) will flip the bit at that position;
bt.none() returns true if none of the bits are set i.e. all the bits are 0 ;
bt.set() will make all the bits set i.e. all the bits will become 1 ;
bt.set(position) will set the bit at the given position ;
bt.set(position , 0) will set the bit at the given position to 0 ;
bt.reset() will make all the bits unset i.e. all the bits will become 0 ;
bt.reset(position) will unset the bit at the given position ;
bt.size() prints the size
bt.test(position) checks whether the bit at the given position is set or not ;



ALGORITHMS

Sort ;
sort (arr, arr+n) ;	sort (vec.begin(), vec.end()) ; sort (vec.begin() + 1, vec.begin() + 6) if you want to sort from position 1 to 5 ;

Reverse ;
reverse (arr, arr+n) ;	reverse (vec.begin(), vec.end()) ; reverse (vec.begin() + 1, vec.begin() + 6) if you want to reverse from position 1 to 5 ;

Max element ;
max_element(StartIterator, EndIterator) will return iterator pointing to the max element. ;
*max_element(StartIterator, EndIterator) will give us the maximum value ;

Min element ;
min_element(StartIterator, EndIterator) will return iterator pointing to the min element. ;
*min_element(StartIterator, EndIterator) will give us the minimum value ;

Sum of elements in a given range ;
accumulate(StartIterator, EndIterator, initial sum) ;

Count frequency of occurrence of a particular number ;
count(StartIterator, EndIterator, num) ;

Find first occurrence of any number ;
auto it = find (StartIterator, EndIterator, num) will return the iterator pointing to the first instance of that number ;
Inorder to get the index, we will subtract vec.begin() or arr from it. Index = it - vec.begin() ;
if the find returns vec.end() to it i.e. it = vec.end(), this means that the element is not present in the vector. ;

Binary Search ;
It's return type is bool ;
This will work if the vector/array is sorted ;
For searching a number ;
binary_search (StartIterator, EndIterator, num) will return true if the num is present or else it will return false. ;

Lower Bound function ;
Array/Vector has to be sorted
Time complexity = O(logn)
returns an iterator pointing to the first element which is not less than num. (which means can also be pointing to the num if found);
auto it = lower_bound (StartIterator, EndIterator, num) ;

Upper Bound function ;
Array/Vector has to be sorted
Time complexity = O(logn)
returns an iterator pointing to the first element which is just greater than num. ;
auto it = upper_bound (StartIterator, EndIterator, num) ;

In case of set and map, dont use upper bound and lower bound like this
Instead use like this : s.lower_bound(key), s.upper_bound(key), mp.lower_bound(key), mp.upper_bound(key)

Next Permutation ;
It's return type is bool ;
If the next permutation of any array/vector/string exist, it will return true. Else it will return false ;
bool ans = next_permutation(vec.begin(), vec.end()) ;

Prev Permutation ;
It's return type is bool ;
If the previous permutation of any array/vector/string exist, it will return true. Else it will return false ;
bool ans = prev_permutation(vec.begin(), vec.end()) ;



COMPARATOR 

Sort in descending order ;
sort (vec.begin(), vec.end(), greater<int>()) ;

//Sort the first no. in ascending order. If the first no. is same, then sort the second no. in descending order

bool comp(pair<int,int> el1, pair<int,int> el2) {
	
	if (el1.first != el2.first)
		return el1.first < el2.first;

	else
		return el1.second > el2.second;
}



Lambda Function 

all_of (vec.begin(), vec.end(), [](int x, ..parameters) {write condition return x > 0 ;})  // Will return true only if all the elements satisfy the condition
any_of (vec.begin(), vec.end(), [](int x, ..parameters) {write condition return x > 0 ;})  // Will return true if any of the element satisfy the condition
none_of (vec.begin(), vec.end(), [](int x, ..parameters) {write condition return x > 0 ;})  // Will return true only if none of the elements satisfy the condition

bool Lambda_func (int x)
{
	return x > 0;
}

all_of (vec.begin(), vec.end(), Lamda_func);


IOTA

Assigns to every element in the range [first, last] successive values of val, as if incremented with ++val after each element is written.

void iota (vec.begin(), vec.end(), val);



