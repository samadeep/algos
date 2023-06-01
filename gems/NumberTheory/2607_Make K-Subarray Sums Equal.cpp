
//https://leetcode.com/problems/make-k-subarray-sums-equal/description/
// Key Intuition
// Let’s first look at a toy example by assuming k = 3. Because the problem requires the sum of each subarray of length k to be equal, we then need to have arr[0] + arr[1] + arr[2] = arr[1] + arr[2] + arr[3], which implies that arr[0] = arr[3]. Essentially, this is saying that every k-th element of arr needs to be equal after all operations.

// There is one caveat yet to make the argument complete: In this problem arr is not only a regular array but also a circular array. Suppose n = 6 and k = 4, we need to have every gcd(n, k) = gcd(6, 4) = 2-th element of arr to be equal after all operations.

class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {

        int sz = arr.size(); long long ans=0;

        for(int i=0;i<sz;i++)
        {
            vector<int> cycle;

            for( int j = i; arr[j]!=0 ; j= (j+k)%sz )
               { 
                   cycle.push_back(arr[j]);
                   arr[j]=0; // now this is out of considerartion
                }
            
            int median_idx = (int)cycle.size()/2;
            nth_element(cycle.begin(),cycle.begin()+median_idx,cycle.end());
            
//             for(auto e : cycle) cout<<e<<" "; cout<<endl;
            
            for(auto e : cycle)
            {
                ans += abs(e-cycle[median_idx]);
            }
        }

        return ans;
    }
};
