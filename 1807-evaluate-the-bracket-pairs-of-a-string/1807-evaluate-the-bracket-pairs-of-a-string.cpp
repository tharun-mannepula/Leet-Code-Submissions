class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n=knowledge.size();
        unordered_map<string,string> mpp;
        for(int i=0;i<n;i++){
            string key=knowledge[i][0];
            string value=knowledge[i][1];
            mpp[key]=value;
        }
        int m=s.size();
        string ans="";
        for(int i=0;i<m;i++){
            if(s[i]=='('){
                string dummy="";
                while(s[i+1]!=')'){
                    dummy+=s[i+1];
                    i++;
                }
                i++;
                if(mpp.find(dummy)!=mpp.end()) ans+=mpp[dummy];
                else ans+='?';
                continue;
            }
            ans+=s[i];
        }
        return ans;
    }
};