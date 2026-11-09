class Solution {
public:
    vector<vector<int>>res={{}};
        void solve(vector<int>&nums,int start,int end){
            if(start>end){
                return;
            }
            int gate=res.size();
            for(int i=0;i<gate;i++){
                vector<int>tem=res[i];
                tem.push_back(nums[start]);
                res.push_back(tem);
            }
            solve(nums,start+1,end);
        }
    vector<vector<int>> subsets(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        solve(nums,start,end);
        return res;    
    }
};