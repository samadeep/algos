#pragma GCC optimize(" unroll-loops")
#pragma gcc optimize("Ofast")

#include <bits/stdc++.h>
 
using namespace std;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);srand(time(NULL))

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using u32 = unsigned int;
using u64 = unsigned long long;

//Templates for Data Structures
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
template <class T>
using vvvvvc = vector<vvvvc<T>>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

//For Loops
#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)
#define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)
#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)
#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))
#define FOR1_R(a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR2_R(i, a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)
#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)

//Input
#define vectorin(A) for(auto &x : A) cin>>x;

// others
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define lcm(a,b)  (a*b)/__gcd(a,b)
#define all(a)     a.begin(),a.end()
#define ch() getchar()
#define pc(x) putchar(x)
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) \
  sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()
  
// Read and write
  template<typename T>void read(T&x){
	static char c;static int f;
	for(f=1,c=ch();c<'0'||c>'9';c=ch())if(c=='-')f=-f;
	for(x=0;c>='0'&&c<='9';c=ch()){x=x*10+(c&15);}x*=f;
}
template<typename T>void write(T x){
	static char q[64];int cnt=0;
	if(x==0)return pc('0'),void();
	if(x<0)pc('-'),x=-x;
	while(x)q[cnt++]=x%10+'0',x/=10;
	while(cnt--)pc(q[cnt]);
}

// Max and Min 
  template <class T, class S>
inline bool chmax(T &a, const S &b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T &a, const S &b) {
  return (a > b ? a = b, 1 : 0);
}

void solve()
{ 
}

signed main()
{
    fastIO;
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}
