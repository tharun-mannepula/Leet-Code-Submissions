class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        stack<int> st;
        vector<int> door(n);
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                int Left=st.top();
                st.pop();
                door[i]=Left;
                door[Left]=i;
            }
        }
        string result;
        int flag=1;
        for(int i=0;i<n;i+=flag){
            if(s[i]=='(' || s[i]==')'){
                i=door[i];
                flag=-flag;
            }
            else result.push_back(s[i]);
        }
        return result;
    }
};