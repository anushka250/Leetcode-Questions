class Solution {
public:
    bool search_in_row(vector<vector<int>> &mat, int target, int row){
        int n = mat[0].size();
        int st = 0, end = n-1;

        while(st <= end){
            int mid = (st + end) / 2;
            if(target == mat[row][mid]){
                return true;
            }
            if(target < mat[row][mid]){
                end = mid - 1;
            }
            else{
                st = mid+1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();
        int start_row =0, end_row = m-1;

        while(start_row <= end_row){
            int mid_row = (start_row + end_row) / 2;
            if(target >= mat[mid_row][0] && target <= mat[mid_row][n-1]){
                return search_in_row(mat, target, mid_row);
            }
            else if(target>= mat[mid_row][n-1]){
                start_row = mid_row + 1;
            }
            else{
                end_row = mid_row - 1;
            }
        }
        return false;
    }
};