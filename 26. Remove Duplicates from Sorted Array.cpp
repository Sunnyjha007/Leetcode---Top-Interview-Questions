int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[j]){
                continue;
            }else{
                j++;
                nums[j] = nums[i];
            }
        }
        return j+1;
    }
//unordered_map can also be use
