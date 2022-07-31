 int myAtoi(string s) {
        int i =0,ans=0,check = 1;
        int n = s.size();
        while(i<n&&s[i]==' ')i++;
        if(i<n&&s[i]=='-'){
            check = -1;i++;
        }else if(i<n&&s[i]=='+')i++;
        while(i<n&&isdigit(s[i])){
            int c = s[i]-'0';
            if((INT_MAX-c)/10<ans){
                if(check==-1)return INT_MIN;
                else return INT_MAX;
            }
            ans = ans*10+c;
            i++;
        }
        return check*ans;
    }
