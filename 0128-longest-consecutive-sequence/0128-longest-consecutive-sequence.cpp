class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size()==0) return 0;
        int count=1;
        int maxC=1;
        unordered_map<int,int>hash;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            count=1;
            if(hash.find(nums[i]+1)!=hash.end()){
                auto it= hash.find(nums[i]+1);
                int i=it->first-1;
            }
            else{
                while(hash.find(nums[i]-1)!=hash.end()){
                    count++;
                    maxC=max(count,maxC);
                    hash.erase(nums[i]-1);
                    nums[i]--;
                }
            }
        }
        return maxC;
    }
};