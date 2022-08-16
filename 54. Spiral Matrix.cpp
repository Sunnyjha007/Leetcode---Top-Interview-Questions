class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int rs=0;
        int cs=0;
        int re=m-1;
        int ce=n-1;
        vector<int> v;
        int k = m*n;
        //maintain count variable to check whether row and col doesn't cross limits(given values of rows(m) and col(n)) 
        int count=0;
        while(count<k){
            //->->->-> row traversal in forward dir. 
        for(int i=cs;i<=ce&&count<k;i++){
            v.push_back(matrix[rs][i]);
            count++;
        }rs++;
              //col traversal in downward dir.  
        for(int i=rs;i<=re&&count<k;i++){
            v.push_back(matrix[i][ce]);
            count++;
        }ce--;
           // row traversal in backward dir.
        for(int i=ce;i>=cs&&count<k;i--){
            v.push_back(matrix[re][i]);
            count++;
        }re--;
            //col traversal in upward dir.  
        for(int i=re;i>=rs&&count<k;i--){
            v.push_back(matrix[i][cs]);
            count++;
        }cs++;
        }
        return v;
    }
};
