    void solve(vector<int>& nums,int si,vector<vector<int>>& ans,vector<int> v){
        if(si==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=si;i<nums.size();i++){
            swap(nums[i],nums[si]);
            solve(nums,si+1,ans,v);
            swap(nums[i],nums[si]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>  ans;
        vector<int> v;
        solve(nums,0,ans,v);
        return ans;
    }
