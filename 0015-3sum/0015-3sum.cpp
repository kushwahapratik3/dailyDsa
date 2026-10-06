class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int fixed;
        int i;
        for(i=0;i<nums.size()-2;i++){
            if (i==0)fixed=nums[i];
            else{
                while(i<nums.size()-2&&nums[i]==nums[i-1]){
                    i++;
                }
                fixed=nums[i];

            }
            int low=i+1;
            int high=nums.size()-1;
            while(low<high){
                int total=fixed+nums[low]+nums[high];
                if(total==0){
                    ans.push_back({fixed,nums[low],nums[high]});
                    while(low<high&&nums[low]==nums[low+1]) low++;
                    while(low<high&&nums[high]==nums[high-1]) high--;
                    low++;
                    high--;
                }
                else if (total>0){
                    high--;
                }
                else{
                    low++;
                }
            }
        }
        return ans;
    }
};