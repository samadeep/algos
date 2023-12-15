#### pow(x,N)
Link : https://leetcode.com/problems/powx-n/

```cpp
class Solution {
public:
    double myPow(double x, int n) 
    {
        if( x == 1 ) return 1.0;

        unsigned int N = n; // -2147483648

        if( n < 0 )
        {
            x = 1.0 / x ; //  2 ^ -4 -> 0.5 ^ 4
            N = n; 
            N = -N; // [4 ^ 8] -> 4 ^ 2 -> 4 ^ 4 -> 4 ^ 8
        } 

        function <double(double,int)> find_pow = [&]( double base , int pow )
        {
            if( pow == 0 ) return 1.0 ;
            if( pow % 2 == 0 ) 
                return find_pow( base * base , pow / 2 );
            else return base * find_pow( base * base , pow / 2 );
        };

        return find_pow(x,N);
        
    }
};
```
