class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='[' || s[i]=='{' || s[i]=='(') st.push(s[i]);
            else{
                if(st.empty()) return false;
                char ele=s[i];
                if((ele==')' && st.top()!='(') || (ele==']' && st.top()!='[') || (ele=='}' && st.top()!='{')) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};