class Solution {
public:
    void solve(int n,int open,int close,vector<string>& v,string s){
        if(close>open||close>n||open>n)return;
        if(close==n){
            v.push_back(s);
            return;
        }
        s.push_back('(');
        solve(n,open+1,close,v,s);
        s.pop_back();
        s.push_back(')');
        solve(n,open,close+1,v,s);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
      vector<string> v;
        string s ="";
        solve(n,0,0,v,s);
        return v;
    }
};
