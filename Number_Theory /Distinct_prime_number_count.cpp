
// Number of distinct prime factors for a particular number

vector<int> save(100005, -1), v(N), ind(N), left(N), right(N);

int distinct_count_prime(int x, vector<int> &s) 
{
    
    int& t = s[x];
    if (t >= 0) {
        return t;
    }
    t = 0;
    for (int i = 2; i * i <= x; ++i) {
       if (x % i == 0) {
            ++t;
            while (x % i == 0) {
                x /= i;
            }
       }
    }
    if (x > 1) {
        ++t;
    }
    return t;
  
}
