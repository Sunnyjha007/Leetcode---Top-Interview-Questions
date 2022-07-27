class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int i=0,j=n-1;
        while(i<j){
            if(v[i].first+v[j].first==target)return {v[i].second,v[j].second};
            else if(v[i].first+v[j].first>target)j--;
            else i++;
        }
        return {-1,-1};
    }
};
/*
vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            map[nums[i]] = i;
        }
        for(int i=0;i<n;i++){
            if(map.find(target-nums[i])!=map.end()&&i!=map[target-nums[i]])return {i,map[target-nums[i]]};
        }
        return {-1,-1};
    }
*/

/*
vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> v;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target)return {i,j};
            }
        }
        return {-1,-1};
    }
*/
