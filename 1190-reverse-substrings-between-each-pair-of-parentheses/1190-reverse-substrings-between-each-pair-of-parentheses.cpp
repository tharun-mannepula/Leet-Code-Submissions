class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        string res="";
        stack<int> st;
        for(int i=0;i<n;i++){
           if(s[i]!='(' && s[i]!=')'){
            res+=s[i];
            continue;
           }
           else if(s[i]=='('){
             st.push(res.size());
             continue;
           }
           else{
             int l=st.top();
             st.pop();
             reverse(res.begin()+l,res.end());
             continue;
           }
        }
        return res;
    }
};