 //Backtracking
    void solve(string digits,vector<string>& ans,string s,int si){
         vector<string> map = {" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits.size()==s.size()){
            ans.push_back(s);
            return;
        }
        string t = map[digits[si]-'0'];
        for(auto i:t){
            s.push_back(i);
            solve(digits,ans,s,si+1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return {};
        vector<string> ans;
        string s="";
        solve(digits,ans,s,0);
        return ans;
    }

 //Recursion
   void solve(string digits,vector<string>& ans,string s){
       vector<string> map = {" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
       if(digits.size()==0){
           ans.push_back(s);
           return;
       }
       string t = map[digits[0]-'0'];
       digits.erase(digits.begin()+0);
       for(int i=0;i<t.size();i++){
           solve(digits,ans,s+t[i]);
       }
   }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return {};
        vector<string> ans;
        string s="";
         solve(digits,ans,s);
        return ans;
        
    }
