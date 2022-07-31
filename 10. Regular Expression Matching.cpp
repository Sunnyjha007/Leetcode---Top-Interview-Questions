int solve(string s,string p,int m,int n,vector<vector<int>>& dp){
        if(m<0&&n<0)return true;
        if(n<0&&m>=0)return false;
        if(m<0&&n>=0){
            if(p[n]=='*')return  solve(s,p,m,n-2,dp);
            return false;
        }
        if(dp[m][n] !=-1)return dp[m][n] ;
        if(s[m]==p[n]||p[n]=='.')return dp[m][n] = solve(s,p,m-1,n-1,dp);
        else if(p[n]=='*'){
            if(s[m]==p[n-1]||p[n-1]=='.')return dp[m][n] = solve(s,p,m-1,n,dp)||solve(s,p,m,n-2,dp);
            return dp[m][n] = solve(s,p,m,n-2,dp);
        }
        return dp[m][n] = false;
    }
    bool isMatch(string s, string p) {
      int m = s.size(),n = p.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(s,p,m-1,n-1,dp);
    }
};

//bottom up
bool isMatch(string s, string p) {
        int m = s.size(),n = p.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0] = 1;
        for(int i=1;i<=n;i++){
            if(p[i-1]=='*')dp[0][i] = dp[0][i-2];
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==p[j-1]||p[j-1]=='.')dp[i][j] = dp[i-1][j-1];
                else if(p[j-1]=='*'){
                    if(s[i-1]==p[j-2]||p[j-2]=='.')dp[i][j] = dp[i][j-2]||dp[i-1][j];
                    else dp[i][j] = dp[i][j-2];
                }else dp[i][j] = 0;
            }
        }
        return dp[m][n];
    }
