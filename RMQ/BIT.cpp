template <typename T>
struct binary_indexed_tree{
  int N;
  vector<T> BIT;
  binary_indexed_tree(int N): N(N), BIT(N + 1, (1<<30)){
  }
  void add(int i, T x){
    while (i <= N){
      BIT[i] = min(BIT[i],x);
      i += i & -i;
    }
  }
  T get(int i){
    T ans = (1<<30);
    while (i > 0){
      ans = min(ans,BIT[i]);
      i -= i & -i;
    }
    return ans;
  }
  T get(int L, int R){
    return get(R) - get(L-1);
  }
};
