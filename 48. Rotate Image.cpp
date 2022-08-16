class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
         int i=0,j=n-1;
        while(i<j){
            swap(matrix[i++],matrix[j--]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
      
    }
};
