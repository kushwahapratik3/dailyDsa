class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        int count=n/2;
        vector<char>isPrime(n,1);
        isPrime[0]=isPrime[1]=0;
        for(int i=3;i*i<n;i+=2){
            if(isPrime[i]){
                for(int j=i*i;j<n;j+=2*i){
                    if(isPrime[j]){
                        isPrime[j]=0;
                        count--;
                    }
                }
            }
        }
        return count;
        
    }
};