class Solution {
private:
    int maxInd(vector<vector<int>>&mat,int m,int n,int mid){
        int el=-1;
        int ind=-1;
        for(int i=0;i<m;i++){
            if(el<mat[i][mid]){
                el=mat[i][mid];
                ind=i;
            }
        }
        return ind;

    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int l=0,h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int maxRowInd=maxInd(mat,m,n,mid);
            int left=mid-1>=0?mat[maxRowInd][mid-1]:-1;
            int right=mid+1<n?mat[maxRowInd][mid+1]:-1;
            if(mat[maxRowInd][mid]>left&&mat[maxRowInd][mid]>right){
                return {maxRowInd,mid};
            }
            else if(mat[maxRowInd][mid]<left){
                h=mid-1;
            }
            else l=mid+1;
        }
        return{-1,-1};
        
    }
};