class Solution {
private:
    bool isVallid(string &curr){
        int count=0;
        for(int i=0;i<curr.length();i++){
            if(curr[i]=='(') count++;
            else count--;
            if(count<0) return false;
        }
        return count==0;
    }
    void solve(string &curr,int &n,vector<string>&res){
        if(curr.length()==2*n) {
            if(isVallid(curr)){
                res.push_back(curr);
            }
            return ;
        }
        curr=curr+"(";
        solve(curr,n,res);
        curr.pop_back();
        curr.push_back(')');
        solve(curr,n,res);
        curr.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string curr="";
        solve(curr,n,res);
        return res;
        
    }
};