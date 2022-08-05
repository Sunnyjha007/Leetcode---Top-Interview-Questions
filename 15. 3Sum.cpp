vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
       for(int i=0;i<n-2;i++){
           if(i>0&&nums[i]==nums[i-1])continue;
           int left = i+1;
           int right = n-1;
           while(left<right){
               int sum = nums[i] + nums[left] + nums[right];
               if(sum<0)left++;
               else if(sum>0)right--;
               else {
                   v.push_back({nums[i],nums[left],nums[right]});
                   int left_val = nums[left];
                   while(left<n&&nums[left]==left_val)left++;
                   int right_val = nums[right];
                   while(right>=0&&nums[right]==right_val)right--;
               }
           }
       }
        return v;
    }
