class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       sort(strs.begin(),strs.end());
        string ans="";
        string s1 = strs[0];
        string s2 = strs[strs.size()-1];
        for(int i=0;i<s1.size();i++){
            if(s1[i]==s2[i])ans.push_back(s1[i]);
            else break;
        }
        return ans;
    }
};
