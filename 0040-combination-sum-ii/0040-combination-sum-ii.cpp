class Solution {
public:
    vector<vector<int>>res;
    void solve(int start,int end,vector<int>&current,vector<int>&candidates,int target){
        if(target==0){
            res.push_back(current);
            return;
        }
        for(int i=start;i<=end;i++){
            if(i>start&&candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            current.push_back(candidates[i]);
            solve(i+1,end,current,candidates,target-candidates[i]);
            current.pop_back();    
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int start=0;
        int end=candidates.size()-1;
        vector<int>current={};
        solve(start,end,current,candidates,target);
        return res;    
    }
};