class Solution {
public:
    vector<vector<int>>res;
    void solve(int start,int end,vector<int>&current,vector<int>&candidates,int target){
        if(target<=0||end<start){
            if(target==0) res.push_back(current);
            return;
        }
        if(candidates[start]<=target){
            current.push_back(candidates[start]);
            solve(start,end,current,candidates,target-candidates[start]);
            current.pop_back();
        }
        solve(start+1,end,current,candidates,target);    
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int start=0;
        int end=candidates.size()-1;
        vector<int>current={};
        solve(start,end,current,candidates,target);
        return res;

        
    }
};