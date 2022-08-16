class Solution {
public:
 
    int trap(vector<int>& arr) {
        int n = arr.size();
        int lmax=0,rmax=0,i=0,j=n-1;
        int ans=0;
        while(i<j){
            lmax = max(lmax,arr[i]);
            rmax = max(rmax,arr[j]);
            ans+= (lmax<rmax)?lmax-arr[i++]:rmax-arr[j--];
        }
        return ans;
    }
};
/*
int trap(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0] = arr[0];
        right[n-1] = arr[n-1];
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1],arr[i]);
        }
        for(int i=n-2;i>=0;i--){
            right[i] = max(right[i+1],arr[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans+=min(left[i],right[i]) - arr[i];
        }
        return ans;
    }

*/
