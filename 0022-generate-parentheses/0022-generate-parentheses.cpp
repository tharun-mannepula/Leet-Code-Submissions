class Solution {
private:
  void func(int open,int close,int n,vector<string>& ans,string s){
    if(open>n) return;
    if(open==close && (open+close)==2*n){
        ans.push_back(s);
        return;
    }
    func(open+1,close,n,ans,s+'(');
    if(open>close) func(open,close+1,n,ans,s+')');
  }


public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        func(0,0,n,ans,"");
        return ans;
    }
};