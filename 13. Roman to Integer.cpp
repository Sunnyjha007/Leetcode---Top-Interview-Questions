int romanToInt(string s) {
      int n = s.size();
        int ans=0,num=0;
        for(int i=n-1;i>=0;i--){
            switch(s[i]){
                case 'I': num=1;break;
                case 'V': num=5;break;
                case 'X': num=10;break;
                case 'L': num=50;break;
                case 'C': num=100;break;
                case 'D': num=500;break;
                case 'M': num=1000;break;
            }
            if(4*num<ans)ans-=num;
            else ans+=num;
        }
        return ans;
    }
};
/*
  int n = s.size();
        unordered_map<char, int> map = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
	int ans = map[s.back()];
        for(int i=0;i<n-1;i++){
            if(map[s[i]]<map[s[i+1]])ans-=map[s[i]];
            else ans+=map[s[i]];
        }
     return ans;  
*/
