class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       int n=nums.size();
        for(int i=0 ; i<n ; i++){
            while(nums[i]>0 and nums[i]<=n and nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
        }
        for(int i=0 ; i<n ; i++)if(nums[i] != i+1) return i+1;
        return n+1;
    }
};
/*
int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0 ; i<n ; i++)
        {
            while(nums[i]>0 and nums[i]<=n and nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
        }
        for(int i=0 ; i<n ; i++) if(nums[i] != i+1) return i+1;
        return n+1;
    }
*/
/*
 int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> v(n+1,false);
        for(int i=0;i<n;i++){
            if(nums[i]>0&&nums[i]<=n){
                v[nums[i]] = true;
            }
        }
        n++;
        for(int i=1;i<n;i++){
            if(!v[i]){
            return i;
            }
        }
        return n;
    }
*/
/*
int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans=1;
        for(int i=0;i<n;i++){
            if(nums[i]==ans)ans++;
            if(ans<nums[i])break;
        }
        return ans;
    }
*/
