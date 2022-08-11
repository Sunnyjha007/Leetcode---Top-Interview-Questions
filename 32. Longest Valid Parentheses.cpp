//naive approach-> 0(n) time && 2*o(n) space
int longestValidParentheses(string s) {
        int n = s.size();
        int len = 0;
        stack<char> s1;
        stack<int> s2;
        s2.push(-1);
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                s1.push('(');
                s2.push(i);
            }else{
                if(!s1.empty()){
                    s1.pop();
                    s2.pop();
                    len = max(len,i-s2.top());
                }else{
                    s2.push(i);
                }
            }
        }
        return len;
    }
////naive optimised  approach-> 0(n) time && o(n) space -> only one stack is used

int longestValidParentheses(string s) {
        int n = s.size();
        int len=0;
        stack<int> st;
        st.push(-1);
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }else{
              st.pop();
                if(st.empty())st.push(i);
                else len = max(len,i-st.top());
            }
        }
        return len;
    }

///
