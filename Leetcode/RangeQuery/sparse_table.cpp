class sparse_table{
	
	public:	
	sparse_table(vector<int> &a){
		
		int n = a.size() + 1;
		copy(a.begin(), a.end(), range_gcds[0]);
		
		for( int i = 1; i <= K ; i++ ){
			for( int j = 0; j + (1<<i) <= n; j++ ){
				range_gcds[i][j] = gcd(range_gcds[i - 1][j],range_gcds[i - 1][j + (1 << (i - 1))]);
			}
		}
	}
	
	int gcd(int a, int b){
		while (b != 0) {
		    int temp = b;
		    b = a % b;
		    a = temp;
		  }
		  return a;
	}
	
	int query(int l, int r){
	
		int range_len = r-l+1;
		int log2_floor_val = log2_floor(range_len);
		int val = r-(1<<log2_floor_val)+1;
		return gcd(range_gcds[log2_floor_val][l], range_gcds[log2_floor_val][val]);
	}
};
