## BIT Trie or XOR Trie

```cpp
    struct xorTrie
    {
        static constexpr int MAX = 1 << 19;
        xorTrie *c[2] = {};

        void insert( int n )
        {
            xorTrie *root = this;
            for( int bits = MAX ; bits > 0 ; bits >>= 1 ) // 1 0 0 0 0 to 0 0 0 1
            {
                int on = (n & bits) > 0;
                if( root -> c[on] == nullptr ) root -> c[on] = new xorTrie();
                root = root -> c[on];
            }
        }

        bool remove( int n , int bits = MAX )
        {
            if( bits == 0 ) return true;
            int check_on = ((bits) & n) > 0;
            if( c[check_on] != nullptr && c[check_on] -> remove( n , bits >> 1 ) )
            {
                delete c[check_on];
                c[check_on] = nullptr;
            }
            return c[1] == c[0];
        }

        int get_maxXOR( int n )
        {
            int maxxor = 0;
            xorTrie *root = this;
            for( int bits = MAX ; bits > 0 ; bits >>= 1 ) // 1 0 0 0 0 to 0 0 0 1
            {
                int on = (n & bits) > 0;
                if( root -> c[!on] != nullptr ) { maxxor += bits ; root = root -> c[!on];}
                else root = root -> c[on];
            }
            return maxxor;
        }

    };
```

