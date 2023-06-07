
###  Reference codeforces Blogs:

 - https://codeforces.com/blog/entry/18051
 - https://codeforces.com/blog/entry/60837

------------------------------------------------------------------------------

### General Idea for Query Operation :
 **General idea is the following**

If l, the left interval border, is odd (which is equivalent to l&1) then l is the right child of its parent. Then our interval includes node l but doesn't include it's parent. So we add t[l] and move to the right of l's parent by setting l = (l + 1) / 2. If l is even, it is the left child, and the interval includes its parent as well (unless the right border interferes), so we just move to it by setting l = l / 2. Similar argumentation is applied to the right border. We stop once borders meet.

### Codes : 

```cpp

const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
  build();
  modify(0, 1);
  printf("%d\n", query(3, 11));
  return 0;
}

```
  
  

  
 ### 1.1 Non-commutative combiner functions
  
  ```cpp
  void modify(int p, const S& value) {
  for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
}

S query(int l, int r) {
  S resl, resr;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) resl = combine(resl, t[l++]);
    if (r&1) resr = combine(t[--r], resr);
  }
  return combine(resl, resr);
}
  
  ```

