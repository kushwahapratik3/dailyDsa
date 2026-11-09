class Solution {
public:
vector<vector<int>>res={{}};
    void solve(vector<int>&curr,vector<int>&nums,int start,int end){
        if(start>end){
            return;
        }
        if(curr.size()<=end){
            curr.push_back(nums[start]);
            res.push_back(curr);
            solve(curr,nums,start+1,end);
            curr.pop_back();
        }
        solve(curr,nums,start+1,end);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr={};
        int start=0;
        int end=nums.size()-1;
        solve(curr,nums,start,end);
        return res;
        
    }
};