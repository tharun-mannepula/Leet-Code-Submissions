class Solution {
public:
    int SumofWeights(string& s,vector<int>& arr){
        int sum=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            sum+=arr[s[i]-'a'];
        }
        return sum;
    }
    
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        unordered_map<int,char> mpp;
        for(int i=25;i>=0;i--){
            mpp[i]='z'-i;
        }
        string ans="";
        int n=words.size();
        for(int i=0;i<n;i++){
            int sum=SumofWeights(words[i],weights);
            ans+=mpp[sum%26];
        }
        return ans;
    }
};