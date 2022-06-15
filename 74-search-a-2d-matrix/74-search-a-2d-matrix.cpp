class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int n=matrix.size();
         int cols=matrix[0].size();
         int lo=0,hi=n*cols-1;
         while(lo<=hi){
            int mid=(lo+hi)/2;
            if(matrix[mid/cols][mid%cols]==target) return true;
            else if(matrix[mid/cols][mid%cols]>target) hi=mid-1;
            else lo=mid+1;
         }
         return false;
    }
};