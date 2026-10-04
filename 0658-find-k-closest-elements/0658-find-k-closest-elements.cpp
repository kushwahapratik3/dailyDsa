class Solution {
private:
    int getUpper(vector<int>&arr,int pivot,int end,int x){
        int upper=arr[end]-x;
        return upper;
    }
    int getlower(vector<int>&arr,int pivot,int start,int x){
        int lower=(x-arr[start]);
        return lower;
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>res;
        int i=0;
        while(i<arr.size()&&arr[i]<=x){
            i++;
        }
        int pivot=i-1;
        if(pivot==-1){
            for(int i=0;i<k;i++){
                res.push_back(arr[i]);
            }
        }
        else if (pivot==arr.size()-1){
            for(int i=0;i<k;i++){
                res.push_back(arr[arr.size()-k+i]);
            }
        }
        else{
            int start=pivot;
            int end=pivot+1;
            int upper,lower;
            for(int i=0;i<k;i++){
                if(start>=0&&end<arr.size()&&start<=end){
                    upper=getUpper(arr,pivot,end,x);
                    lower=getlower(arr,pivot,start,x);
                    if(lower<=upper){
                        res.push_back(arr[start]);
                        start--;
                    }
                    else{
                        res.push_back(arr[end]);
                        end++;
                    }
                }
                if(start<0){
                    while(res.size()<k){
                        res.push_back(arr[end]);
                        end++;
                    }
                } 
                if(end>=arr.size()){
                    while(res.size()<k){
                        res.push_back(arr[start]);
                        start--;
                    }
                }   
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};