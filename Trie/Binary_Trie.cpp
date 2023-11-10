struct binary_trie_node
{
    binary_trie_node* bits[2];
    binary_trie_node()
    {
        bits[0] = nullptr; bits[1] = nullptr;
    }
};

void trie_insert( binary_trie_node* node , int N )
{
    binary_trie_node* curr_node = node;
    
    for( int i = 21 ; i >= 0 ; i-- )
    {
        if( !curr_node -> bits[ N >> i & 1 ] )
        {
            curr_node -> bits[ N >> i & 1 ] = new binary_trie_node();
        }
        
        curr_node = curr_node -> bits[ N >> i & 1 ] ;
    }
}

int trie_find( binary_trie_node* node , int N )
{
    binary_trie_node* curr_node = node;
    
    int max_xor = 0;
    
    for( int i = 21 ; i >= 0 ; i--)
    {
        if( curr_node -> bits[ 1 ^  N >> i & 1 ] )
        {
            max_xor |= 1 << i;
            curr_node = curr_node -> bits[ 1 ^  N >> i & 1 ];
        }
        else
        {
            curr_node = curr_node -> bits[ N >> i & 1 ];
        }
    }
    
    return max_xor;
}
