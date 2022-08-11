string countAndSay(int n) {
        if(n==1)return "1";
        if(n==2)return "11";
        string s = "11";
        for(int i=3;i<=n;i++){
            string t = "";
            s+='&';
            int c =1;
            for(int j=1;j<s.size();j++){
                if(s[j-1]!=s[j]){
                    t = t + to_string(c);
                    t = t + s[j-1];
                    c=1;
                }else c++;   
            }
            s=t;
        }
        return s;
    }

//Recursive code->
string countAndSay(int n,string s="1"){
        if(n==1)return s;
        int i=0,j,len = s.size();
        string ans = "";
        while(i<len){
            j = i;
            while(i<len&&s[i]==s[j])i++;
            ans+= to_string(i-j) + s[j];
        }
        return countAndSay(n-1,ans);
    }
