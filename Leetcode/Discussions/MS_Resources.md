## Questions :

- Given 'n', find the number of valid parenthesis strings that can be made with a length of 'n' using '(' and ')' and print them.<br>
Link : https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

- Implement a Min Stack with O(1) amortized cost for all operations (push, pop, and getMin).<br>

- Print all the subsequences for a given array.<br>

- The problem was if we have a social media in which people are friends of each other, 
I need to figure out that if I have 2 people are, they linked to each other. 
Linked as in if they are friends to each other or if they have a path of friends connecting each other.<br>

- Implement a file system which has the standard functions like cd, pwd, ls.<br>
Link : https://medium.com/root-node/design-in-memory-file-system-96ee6c484616

- Recognizing a strobogrammatic number<br>
Link : https://stackoverflow.com/questions/57265628/how-to-check-given-number-or-list-is-strobogrammatic-number

- Implement LRU cache<br>
Link: https://leetcode.com/problems/lru-cache/

```cpp
// LRU Method
class LRUCache {
private:
    int size;
    list<int> infos;
    unordered_map<int, pair<int, list<int>::iterator>> key_list;

    public:
    LRUCache(int capacity) {
        size = capacity;
    }

    int get(int key){
        if (key_list.find(key) == key_list.end()){
            return -1; 
        }
        auto itr = key_list[key].second;
        int val = key_list[key].first;
        infos.erase(itr);
        infos.push_back(key);
        key_list[key].second = --infos.end();
        return val;
    }


    void put(int key, int val){
        if (key_list.find(key) != key_list.end()){
            auto itr = key_list[key].second;
            infos.erase(itr);
        }
        infos.push_back(key);
        key_list[key] = {val, --infos.end()};

        if (key_list.size() > size){
            int key = infos.front();
            key_list.erase(key);
            infos.pop_front();
        }
    }

};
```

- Min subarray for max sum<br>
Link : https://stackoverflow.com/questions/59707406/how-to-find-the-smallest-contiguous-subarray-with-maximum-sum
