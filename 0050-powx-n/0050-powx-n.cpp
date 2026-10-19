class Solution {
private:
    double ans(double x,long n){
        if(n==1) return  x;
        else if(n==0) return 1;
        double temp=ans(x,n/2);
        if(n%2==0){
            return temp*temp;
        }
        else return x*temp*temp;
    }
public:
    double myPow(double x, int n) {
        if(n==1) return  x;
        else if(n==0) return 1;
        long N=abs((long)n);
        if (n>0) return ans(x,N);
        else return 1/ans(x,N);    
    }
};