using ll = long long;

class DSU
{
    public:
    vector<ll> parent,size;
 
    DSU(ll n) // kind of the make- set operation of DSU
    {
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        size.resize(n);
        for(auto &s:size) s=1;
    };
 
    ll findparent(ll node)
    {
        if (parent[node]==node) return node;
        else return parent[node]=findparent(parent[node]);
    }
 
    bool makeunion(ll u, ll v)
    {
        ll parent_u=findparent(u); 
        ll parent_v=findparent(v);
 
        if(parent_u != parent_v)
        {
        	if( size[parent_v] < size[parent_u] )
        	{
        		swap(parent_u,parent_v);
        	}
        	
        	
        	parent[parent_u] = parent_v;
            size[parent_v]+=size[parent_u];
            return true;
        }
        else return false;
    }
    
    
};
 
