// The class has two member variables:

// fenw is a vector of type T that represents the Fenwick tree. It will store the cumulative values used to efficiently calculate prefix sums.
// n is an integer that represents the size of the Fenwick tree.

// The constructor Fenwick(int _n) takes an integer _n and initializes the n variable with the provided value. It also resizes the fenw vector to have a size equal to n.

// The modify member function is responsible for updating the Fenwick tree. It takes an index x and a value v. The function adds the value v to the element at index x 
// in the Fenwick tree and propagates the changes to the necessary indices in the tree using bitwise operations and a while loop.

// The get member function is used to calculate the prefix sum up to a given index x. It takes an index x as an argument and returns the cumulative sum of 
// the elements from index 0 to x in the Fenwick tree. It iteratively accumulates the values by traversing the tree in reverse order using bitwise operations and a while loop.

#include <bits/stdc++.h>
using namespace std;


template <typename T>
class Fenwick
{
	public:
	vector<T> fenw;int n;
	
	Fenwick(int _n) : n(_n)
	{
		fenw.resize(n);
	}
	
	void modify(int x, T v) 
	{
    	while (x < n) 
    	{
      		fenw[x] += v;
      		x |= (x + 1);
    	}
  	}
  	
  	T get(int x) {
    	T v{};
    	
    	while (x >= 0) 
    	{
      		v += fenw[x];
      		x = (x & (x + 1)) - 1;
    	}
    	
    	return v;
  }
};
