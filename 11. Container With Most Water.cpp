int maxArea(vector<int>& arr) {
        int n = arr.size();
        int i=0,j=n-1,ans=INT_MIN,width=0,min_height=0;
        while(i<j){
            min_height = min(arr[i],arr[j]);
            width = (j-i);
            ans = max(ans,width*min_height);
            if(arr[i]<arr[j])i++;
            else j--;
        }
        return ans;
    }
