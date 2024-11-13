template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
template<size_t N,
         class T,
         T (*op)(const T&, const T&),
         T (*e)()>
struct SegmentTree {
  struct Node {
    Node *left, *right;
    T val;
    void pushup() { val = op(left->val, right->val); }
  };
  Node pool[N << 1], *last, *rt;
  int n;
  SegmentTree(const vector<T>& v): n(SZ(v)) {
    last = pool;
    rt = build(0, n, v);
  }
  SegmentTree(int n): SegmentTree(vector<T>(n, e())) {}
  Node* build(int a, int b, const vector<T>& v) {
    Node* ret = last++;
    if (a + 1 == b) { ret->val = v[a]; return ret; }
    int mid = (a + b) / 2;
    ret->left = build(a, mid, v);
    ret->right = build(mid, b, v);
    ret->pushup();
    return ret;
  }
  void set(int pos, T val) { return set(rt, 0, n, pos, val); }
  void set(Node* cur, int a, int b, int pos, T val) {
    if (pos < a || pos >= b) return;
    if (a + 1 == b) { cur->val = val; return; }
    int mid = (a + b) / 2;
    set(cur->left, a, mid, pos, val);
    set(cur->right, mid, b, pos, val);
    cur->pushup();
  }
  T query(int ll, int rr) { return query(rt, 0, n, ll, rr); }
  T query(Node* cur, int a, int b, int ll, int rr) {
    if (ll >= rr || a >= rr || b <= ll) return e();
    if (a >= ll && b <= rr) return cur->val;
    int mid = (a + b) / 2;
    return op(query(cur->left, a, mid, ll, rr), query(cur->right, mid, b, ll, rr));
  }
};

// min
const int N = 2e5 + 10;
template<typename T> T op(const T& a, const T& b) { return a + b; }
template<typename T> T e() { return inf<T>; }
using segtree = SegmentTree<N, int, op, e>;
