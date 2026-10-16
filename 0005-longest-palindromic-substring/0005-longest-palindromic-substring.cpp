class Solution {
public:
    string longestPalindrome(string s) {
        int strLen1=0,l1=-1;
        for(int i=0;i<s.length();i++){
            int l=i;
            int r1=i;
            while(l>=0&&r1<s.length()){
                if(s[l]==s[r1]){
                    if(r1-l+1>strLen1){
                        strLen1=r1-l+1;
                        l1=l;
                    }
                    l--;
                    r1++;
                }
                else break;
            }
            l=i;
            r1=i+1;
            while(l>=0&&r1<s.length()){
                if(s[l]==s[r1]){
                    if(r1-l+1>strLen1){
                        strLen1=r1-l+1;
                        l1=l;
                    }
                    l--;
                    r1++;
                }
                else break;
            }

        } 
        return s.substr(l1,strLen1);; 
    }
};