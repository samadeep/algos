 
template<typename T> struct Fenwick {
	vector<T> a;
	int n;
 
	Fenwick() : a(), n(0) {}
	Fenwick(int _n) {
		n = _n;
		a = vector<T>(n, T());
	}
 
	void clear() {
		a = vector<T>(n, T());
	}
 
	void add(int p, T x) {
		for(; p < n; p |= p + 1)
			a[p] += x;
	}
	T get(int r) {
		if (r < 0) return T();
		r = min(r, n - 1);
		T res = T();
		for(; r >= 0; r = (r & (r + 1)) - 1)
			res += a[r];
		return res;
	}
	T getSum(int l, int r) {
		return get(r - 1) - get(l - 1);
	}
};
