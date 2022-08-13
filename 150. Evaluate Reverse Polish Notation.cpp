class Solution {
public:
    int evalRPN(vector<string>& s) {
      int n = s.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(s[i]!="+"&&s[i]!="-"&&s[i]!="*"&&s[i]!="/"){
                st.push(stoi(s[i]));
            }else {
                int a = st.top();st.pop();
                int b = st.top();st.pop();
                if(s[i]=="+"){
                    st.push(a+b);
                }else if(s[i]=="-"){
                    st.push(b-a);
                }else if(s[i]=="*"){
                    st.push(a*b);
                }else{
                    st.push(b/a);
                }
            }
        }
        return st.top();
    }
};

