class Solution {
private:
    void solve(int open,int close,string &curr,int &n,vector<string>&res){
        if(curr.length()==2*n) {
            res.push_back(curr);
            return ;
        }
        if(open<n){
            curr=curr+"(";
            solve(open+1,close,curr,n,res);
            curr.pop_back();
        }
        if(close<open){
            curr.push_back(')');
            solve(open,close+1,curr,n,res);
            curr.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string curr="";
        solve(0,0,curr,n,res);
        return res;
        
    }
};