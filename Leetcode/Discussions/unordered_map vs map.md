
## map vs unordered_map in C++


`std::map`: This container is implemented as a binary search tree, which ensures that its elements are always sorted. 
As a result, insertions and searches have a time complexity of O(log N), where N is the number of elements in the container. 
Due to its sorted nature, `std::map` is useful when you need ordered traversal of elements.
`std::map` is a sorted associative container that contains key-value pairs with unique keys. 
Keys are sorted by using the comparison function `Compare`. Search, removal, and insertion operations have logarithmic complexity.
Maps are usually implemented as [Red–black trees](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree "enwiki:Red–black tree")

### std::map time complexities
Average / Worst / Best : O(logN) as its implemented using a Red - Black or BST

![Red-Black Trees](https://upload.wikimedia.org/wikipedia/commons/7/72/Red-black_tree_example_%28B-tree_analogy%29.svg)


------

`std::unordered_map`: This container is implemented as a hash table, offering faster insertions and searches with an average time complexity of O(1). 
However, the performance can degrade to O(N) in worst-case scenarios. `std::unordered_map` is beneficial when the order of elements is not essential, 
and you prioritize fast retrieval based on keys.
Internally, the elements are not sorted in any particular order, but organized into buckets. 
Which bucket an element is placed into depends entirely on the hash of its key. 
Keys with the same hash code appear in the same bucket. This allows fast access to individual elements, 
since once the hash is computed, it refers to the exact bucket the element is placed into.

When the keys are generated in an unordered manner , the results show that `std::unordered_map` generally outperforms `std::map` in both insertion and search operations. As the map size increases, `std::unordered_map` may suffer from hash collisions and longer linked lists, resulting in slightly slower insertion times compared to `std::map`. For search operations, `std::unordered_map` continues to demonstrate superior performance over `std::map` due to its constant-time average complexity for searching, compared to the logarithmic complexity of `std::map`.

**Hashing** is done as -> **value** -> **hash**(value) -> **key** to form the ultimate key and then assign value to it 

### std::unordered_map time complexities
Best : O(1) for insertion and key finding
Best : O(N) for insertion and key finding if we have lots of collisions 


![Unordered_map_hashing](https://miro.medium.com/v2/resize:fit:1200/1*RCntWRL8U5okbdnoPIc-9w.png)

