//naive approach ->
// find all substring -> kadane's algo & maintain a hash set for unique characters
// O(n^3) && o(n)

 bool isunique(string s,int i,int j){
        vector<char> visited(256,0);
        for(int k=i;k<=j;k++){
            if(visited[s[k]])return false;
            visited[s[k]] = true;
        }
        return true;
    }
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxlen =0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isunique(s,i,j)){
                    maxlen = max(maxlen,j-i+1);
                }
            }
        }
        return maxlen;
    }

//little optimised approach -> 
//maintain a set and a left and right poiner and check for window and repating characters in map
//if repating char present we have to move left by 1 &&check agin unitil it doesn't remove
// after that check for maxi length ans update
// push right in set
//O(2n) && o(n)

int lengthOfLongestSubstring(string s) {
//        COUNT ARRAY WITH INITIALLY VALUES FILLED AS 0
        int count[256] = {0};
        //scanning string from left to right using 2 pointers
		//if character s[end] is not in character array, insert it in count[] and increment end
		//else delete the character if present more than once and increment left;
		
		int start = 0; 
        int end = 0;
        int ans = 0;
        
        while(end < s.size())
        {
            count[s[end]]++;
          
//             if character is appearing more than once
            while(count[s[end]] > 1)
            {
//                 remove that character, decrease window 
                count[s[start]]--;
//                 for next iteration
                start++;
            }
            ans = max(ans, end-start+1);
            end++;
        }
        return ans;    
    }






//best approach ->
//check if char occurs then delete s[left] from set and  move left pointer else
//move right pointer and insert s[right] and check max len 
//o(n)&&O(n)
class Solution {
public:
  
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        set<char> st;
        int left=0,right=0,maxlen=0;
        while(right<n){
            if(st.count(s[right])==0){
                st.insert(s[right++]);
                maxlen = max(maxlen,int(st.size()));
            }else{
                st.erase(s[left++]);
            }
        }
        return maxlen;
    }
};


