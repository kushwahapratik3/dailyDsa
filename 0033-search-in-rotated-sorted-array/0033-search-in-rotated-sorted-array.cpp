class Solution {
private:
    int bs(vector<int>&nums,int low,int high,int target){
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else low=mid+1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[low]<=nums[mid]){
                if(target<=nums[mid]&&target>=nums[low]){
                    return bs(nums,low,mid,target);
                }
                else low=mid+1;
            }
            else{
                if(target>=nums[mid]&&target<=nums[high]){
                    return bs(nums,mid,high,target);
                }
                else high=mid-1;
            }
        }
        return -1;        
    }
};