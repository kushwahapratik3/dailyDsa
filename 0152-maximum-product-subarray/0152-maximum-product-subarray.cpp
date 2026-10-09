class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int product=1; 
        int max1=INT_MIN;
        int max2=INT_MIN;
        for (int i=0;i<nums.size();i++){
            product*=nums[i];
            max1=max(max1,product);
            if(product==0){
                product=1;
            }
        }
        product=1;
        for (int i=nums.size()-1;i>=0;i--){
            product*=nums[i];
            max2=max(max2,product);
            if(product==0){
                product=1;
            }
        }
        return max(max1,max2);    
    }
};