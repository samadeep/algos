#pragma GCC optimize(" unroll-loops")
#pragma gcc optimize("Ofast")

// Header Files
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>
#include<unordered_set>
#include<list>
#include<iterator>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<bitset>
#include<random>
#include<map>
#include<unordered_map>
#include<stdio.h>
#include<complex>
#include<math.h>
#include<cstring>
#include<chrono>
#include<string>

using namespace std;

#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);srand(time(NULL))

using ll = long long;
using i64 = int64_t;
using i32 = int32_t;
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
using pqs = priority_queue<T, vector<T>, greater<T>>;
template<typename T1,typename T2>
using pi = pair<T1, T2>;


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


// Macros for input
#define input_int(a) scanf("%d", &a)
#define input_long(a) scanf("%ld", &a)
#define input_ll(a) scanf("%lld", &a)
#define input_float(a) scanf("%f", &a)
#define input_double(a) scanf("%lf", &a)
#define input_char(a) scanf(" %c", &a)
#define input_string(a) scanf("%s", a)
#define input_vector(a) for( auto &a : A ) cin >> a ;


// Macros for output
#define print_int(a) printf("%d", a)
#define print_long(a) printf("%ld", a)
#define print_ll(a) printf("%lld", a)
#define print_float(a) printf("%f", a)
#define print_double(a) printf("%lf", a)
#define print_char(a) printf("%c", a)
#define print_string(a) printf("%s", a)

//Input and output
#define vectorin(A) for(auto &x : A) cin>>x;
#define print(A) for( auto &a : A ) cout << a << " "; cout << endl;


#define eb          emplace_back
#define mp          make_pair
#define mt          make_tuple
#define f               first
#define s               second
#define LCM(a,b)  (a*b)/__gcd(a,b)
#define ALL(a)    a.begin(),a.end()
#define MIN(v)    *min_element(ALL(v))
#define MAX(v)    *max_element(ALL(v))
#define LB(c, x)  distance((c).begin(), lower_bound(ALL(c), (x)))
#define UB(c, x)  distance((c).begin(), upper_bound(ALL(c), (x)))
#define UNIQUE(x) sort(ALL(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())


const int64_t mod = 1e9 + 7;
int64_t inv(int64_t i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}
int64_t mod_mul(int64_t a, int64_t b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
int64_t mod_add(int64_t a, int64_t b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}

int64_t gcd(int64_t a, int64_t b) { if (b == 0) return a; return gcd(b, a % b);}
int64_t ceil_div(int64_t a, int64_t b) {return a % b == 0 ? a / b : a / b + 1;}


const int SIZE = 3.1e5;
const int MOD = 998244353;
int64_t mypow(int64_t x,int64_t y){
    x%=MOD;
    int64_t res=1%MOD;
    while(y){
        if(y&1)res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}

int64_t fac[SIZE];
int64_t inv_fac[SIZE];
void pre() {
    fac[0] = 1;
    for(int i = 1; i < SIZE; i++) {
        fac[i] =  fac[i-1] * i % MOD;
    }
    inv_fac[SIZE - 1] = mypow(fac[SIZE - 1], MOD - 2);
    for(int i = SIZE - 2; i >= 0; i--) {
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % MOD;
    }
}

int64_t NCR(int64_t n, int64_t m) {
    if(m < 0 || m > n) {
        return 0;
    }
    return fac[n] * inv_fac[m] % MOD * inv_fac[n - m] % MOD;
}


// Change Max and Min 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }


int __gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return __gcd(b, a % b);
}
 
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
 
    // Check if n is divisible by 2 or 3.
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
 
    // Use 6k +/- 1 rule for optimization.
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
 
    return true;
}

struct DSU {
    int n;
    vector<int> par, sz;
    
    DSU(int t_n) : n(t_n), par(t_n), sz(t_n) {
        iota(par.begin(), par.end(), 0);
        fill(sz.begin(), sz.end(), 1);
    }
 
    int find_parent(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = find_parent(par[x]);
    }
 
    bool merge(int u, int v) {
        int pu = find_parent(u), pv = find_parent(v);
        if (pu == pv) return false;
        if (sz[pu] < sz[pv]) swap(pu, pv);
        par[pv] = pu;
        sz[pu] += sz[pv];
        return true;
    }
 
    bool isSameParent(int u, int v) {
        return find_parent(u) == find_parent(v);
    }
 
    int getSize(int x) {
        int px = find_parent(x);
        return sz[px];
    }
};

vector<int64_t> divisors(int64_t n) 
{ 
    vector<int64_t> ans;
    for (int64_t i=1; i*i<=n; i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i == i){
                ans.eb(i); 
            }
  
            else{ 
                ans.eb(i);
                ans.eb(n/i);
            } 
        } 
    } 
    return ans;
}

/*

    Learnt:
    


*/

void solve()
{
	
    
    
    
}


signed main()
{
    fastio;
    pre();
    int t=1;
    cin >> t ;
    while(t--) solve();
    return 0;
}
\
