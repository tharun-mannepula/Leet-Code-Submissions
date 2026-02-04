class Solution {
public:
    string removeKdigits(string nums, int k) {
       int n=nums.size();
       stack<int> st;
       for(int i=0;i<n;i++){
        while(!st.empty() && (st.top()-'0')>(nums[i]-'0') && k>0){
            st.pop();
            k--;
        }
        st.push(nums[i]);
       }
        while(k>0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        while(res.size()!=0 && res.back()=='0') res.pop_back();
        reverse(res.begin(),res.end());
        if(res.empty()) return "0";
        return res;
    }
};