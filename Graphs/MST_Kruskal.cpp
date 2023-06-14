// nealwu codes 

template<typename T_edge>
struct kruskal {
    struct edge {
        int a, b;
        T_edge weight;
        int index = -1;
        bool in_tree = false;
 
        edge() {}
 
        edge(int _a, int _b, T_edge _weight, int _index = -1) : a(_a), b(_b), weight(_weight), index(_index) {}
 
        bool operator<(const edge &other) const {
            return weight < other.weight;
        }
    };
 
    union_find UF;
    vector<edge> edges;
    vector<bool> original_in_tree;
 
    kruskal(int n = -1) {
        if (n >= 0)
            init(n);
    }
 
    void init(int n) {
        UF.init(n);
        edges = {};
    }
 
    void add_edge(int a, int b, T_edge weight) {
        edges.emplace_back(a, b, weight, edges.size());
        original_in_tree.push_back(false);
    }
 
    template<typename T_sum>
    T_sum solve() {
        sort(edges.begin(), edges.end());
        T_sum total = 0;
 
        for (edge &e : edges)
            if (UF.unite(e.a, e.b)) {
                total += e.weight;
                e.in_tree = true;
                original_in_tree[e.index] = true;
            }
 
        return total;
    }
};
 
