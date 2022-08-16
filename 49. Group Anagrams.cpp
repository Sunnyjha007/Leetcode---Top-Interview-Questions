class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> map;
        int n = strs.size();
        for(int i=0;i<n;i++){
            string s = strs[i];
            sort(strs[i].begin(),strs[i].end());
            map[strs[i]].push_back(s);
        }
        for(auto i:map){
            ans.push_back(i.second);
        }
        return ans;
        
    }
};
