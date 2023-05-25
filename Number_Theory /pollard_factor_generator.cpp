
typedef unsigned long long ull;


// Important to know :
// Description: Pollard-rho randomized factorization algorithm. Returns prime
 // * factors of a number, in arbitrary order (e.g. 2299 -> \{11, 19, 11\}).
 // * Time: $O(n^{1/4})$, less for numbers with small factors.
 // * Status: stress-tested by Rubikun
 // * Details: This implementation uses the improvement described here
 // * (https://en.wikipedia.org/wiki/Pollard%27s_rho_algorithm#Variants…), where
 // * one can accumulate gcd calls by some factor (40 chosen here through
 // * exhaustive testing). This improves performance by approximately 6-10x
 // * depending on the inputs and speed of gcd. Benchmark found here:
 // * (https://ideone.com/nGGD9T)


const int N = 1e5 + 5;
bool vis[N];
ull modmul(ull a, ull b, ull M) {
    ll ret = a * b - M * ull(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
    ull ans = 1;
    for (; e; b = modmul(b, b, mod), e /= 2)
        if (e & 1) ans = modmul(ans, b, mod);
    return ans;
}
 
bool isPrime(ull n) 
{
    if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
    s = __builtin_ctzll(n-1), d = n >> s;
    for (ull a : A) {   // ^ count trailing zeroes
        ull p = modpow(a%n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--)
            p = modmul(p, p, n);
        if (p != n-1 && i != s) return 0;
    }
    return 1;
}
 
 
 
ull pollard(ull n) {
    auto f = [n](ull x) { return modmul(x, x, n) + 1; };
    ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
    while (t++ % 40 || __gcd(prd, n) == 1) {
        if (x == y) x = ++i, y = f(x);
        if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
        x = f(x), y = f(f(y));
    }
    return __gcd(prd, n);
}
 
 
vector<ull> factor(ull n) {
    if (n == 1) return {};
    if (isPrime(n)) return {n};
    ull x = pollard(n);
    auto l = factor(x), r = factor(n / x);
    l.insert(l.end(), all(r));
    return l;
}


void sieve ()
{
	memset(vis,true,sizeof(vis));
	vis[0] = vis[1] = false;
	
	for( int i = 4 ; i < N ; i +=2 ) vis[i] = true;
		
	for( int i = 3 ; i < N/i ; i += 2  ) 
	{
		if(vis[i]) continue;
		
		for( int j = i * i ; j < N ; j += i + 1  ) 
			vis[j] = false;
	}
}
 
