class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0;
        int pivot=0;
        for(int i=1;i<nums.size();i++){
            while(i<nums.size()&&nums[pivot]==nums[i]){
                nums[i]=101;
                count++;
                i++;
            }
            pivot=i;
        }
        sort(nums.begin(),nums.end());
        return nums.size()-count;
    }
};