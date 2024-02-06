
This algorithm is based on the concept of hashing ( generating hash values for all substrings of a string for patterns )
This algorithm was authored by **Rabin and Karp** in 1987.

Problem: Given two strings - a pattern `p` and a text `text`. 
Determine if the pattern appears in the text and if it does, enumerate all its occurrences in  `O(|s| + |t|)` time.


Initially generate a hash value for the pattern length : `len`

```cpp

long long hash = 0;
for( int i = 0 ; i < len ; i++ ) hash = hash * unique + (val[i]);

```


Then we slide the window for the next substrings of lengths : `len`

For each substring for :
```cpp
for( int i = 1 ; i + len - 1 < s.size() ; i++ ){
	hash = hash * unique - val[i-1] * char_pow_l + val[i+len-1];
}
```

### Complete Implementation :

```cpp

long long hash = 0;
int len = 10; // add the length of the substring to be hashed

for( int i = 0 ; i < len ; i++ ) hash = hash * unique + (val[i]);

for( int i = 1 ; i + len - 1 < s.size() ; i++ ){
	hash = hash * unique - val[i-1] * char_pow_l + val[i+len-1];
	// Perform the operations and then go to the next hash substring
}

```


Related Questions :
[187. Repeated DNA Sequences](https://leetcode.com/problems/repeated-dna-sequences/)
### Code :
```cpp
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        int len = 10 , n = s.size();
        vector<string> ans;

        // ROlling Hash 
        // H[0] = 0
        
        // For 1 ... L
        // H[i] = H[i] * a + char_num[i]

        // For rolling the hash for [start ... L] :
        // H[i] = H[i] * a - char_num[start-1] * pow(a,L) + char_num[start+L-1]

        vector<int> val(s.size());
        int i = 0;
        for( auto &x : s ){
            if(x=='A') val[i++] = 0;
            if(x=='C') val[i++] = 1;
            if(x=='G') val[i++] = 2;
            if(x=='T') val[i++] = 3;
        }

        int unique = 4;

        if( s.size() < len ) return {};
        map<int,int> hash_count;

        long long hash = 0;
        for( int i = 0 ; i < len ; i++ ) hash = hash * unique + (val[i]);

        hash_count[hash] = 1;

        long long char_pow_l = pow(unique,len);

        for( int i = 1 ; i + len - 1 < s.size() ; i++ ){

            hash = hash * unique - val[i-1] * char_pow_l + val[i+len-1];

            if( hash_count[hash] == 1 ) ans.push_back(s.substr(i,len)); // add only once

            hash_count[hash] += 1;
        }

        return ans;
        
    }
};
```


### More Questions :

[Longest Duplicate Substring - LeetCode](https://leetcode.com/problems/longest-duplicate-substring/description/)


