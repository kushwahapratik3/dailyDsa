class Solution {
public:
    bool isPalindrome(string s) {
        string finalString="";
        for(int i=0;i<s.length();i++){
            if(s[i]>=65&&s[i]<=90){
                finalString+=s[i]+32;
            }
            else if(s[i]>=97&&s[i]<=122){
                finalString+=s[i];
            }
            else if(s[i]>=48&&s[i]<=57){
                finalString+=s[i];
            }
        };
        int low=0;
        int high=finalString.length()-1;
        while(low<=high){
            if(finalString[low]==finalString[high]){
                low++;
                high--;
            }
            else return false;
        }
        return true;
        
    }
};