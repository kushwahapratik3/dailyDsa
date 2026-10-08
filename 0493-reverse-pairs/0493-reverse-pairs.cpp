class Solution {
private:
    int countPair(vector<int>&nums,int low,int mid,int high){
        int left=low;
        int right=mid+1;
        int pair=0;
        while(left<=mid&&right<=high){
            if(nums[left]>2LL*nums[right]){
                pair+=mid+1-left;
                right++;
            }
            else{
                left++;
            }
        }
        return pair;
    }
    void countInversion(vector<int>&nums,int low,int mid,int high){
        vector<int>tem;
        int inversion=0;
        int left=low;
        int right=mid+1;
        while(left<=mid&&right<=high){
            if(nums[left]<=nums[right]){
                tem.push_back(nums[left]);
                left++;
            }
            else{
                tem.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            tem.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            tem.push_back(nums[right]);
            right++;
        }
        for(int i=low;i<=high;i++){
            nums[i]=tem[i-low];
        }
    }
    int slice(vector<int>&nums,int low,int high){
        int inversion=0;
        if(low>=high) return 0;
        int mid=(low+high)/2;
        inversion+=slice(nums,low,mid);
        inversion+=slice(nums,mid+1,high);
        inversion+=countPair(nums,low,mid,high);
        countInversion(nums,low,mid,high);
        return inversion;
    }
public:
    int reversePairs(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int inversion=slice(nums,low,high);
        return inversion;
    }
};