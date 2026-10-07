class Solution {
private:
    int maxpile(vector<int>nums){
        int m=nums[0];
        for(int i=0;i<nums.size();i++){
            m=max(m,nums[i]);
        }
        return m;
    }
    long long eated(vector<int>nums,double speed){
        double ht;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            ht=ceil(nums[i]/speed);
            sum=sum+ht;  
        }
        return sum;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high=maxpile(piles);
        int l=1;
        int ans;
        while(l<=high){
            int speed=l+(high-l)/2;
            long long hour_take=eated(piles,speed);
            if(hour_take<=h){
                ans=speed;
                high=speed-1;
            }
            else{
                l=speed+1;
            }
        }
        return ans;
        
    }
};