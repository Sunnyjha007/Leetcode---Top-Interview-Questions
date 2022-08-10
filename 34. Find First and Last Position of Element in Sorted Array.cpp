class Solution {
public:
    int binarySearch(vector<int>& nums,int target,string check){
        int n = nums.size();
        int si = 0,ei = n-1;
        int ans = -1;
        while(si<=ei){
            int mid = si + (ei-si)/2;
            if(nums[mid]==target){
                ans = mid;
                (check=="start"?ei=mid-1:si=mid+1);
            }else if(nums[mid]>target){
                ei = mid-1;
            }else{
                si = mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {binarySearch(nums,target,"start"),binarySearch(nums,target,"end")};
    }
};
