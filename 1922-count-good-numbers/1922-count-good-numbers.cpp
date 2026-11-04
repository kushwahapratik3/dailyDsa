class Solution {
public:
    const long long mod=1000000007;
    long long cal(long long base,long long expo){
        long long ans=1;
        while(expo>0){
            if(expo%2==1){
                ans=(ans*base)%mod;
            }
            base=(base*base)%mod;
            expo=expo/2;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long expo5=(n+1)/2;
        long long expo4=n-expo5;
        long long result=(cal(5,expo5)*cal(4,expo4))%mod;
        return result;
        
    }
};