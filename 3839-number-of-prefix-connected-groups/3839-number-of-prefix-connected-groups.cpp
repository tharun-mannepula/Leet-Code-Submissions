class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        int n=words.size();
        unordered_map<string,vector<string>> mpp;
        for(int i=0;i<n;i++){
            int len=words[i].size();
            if(len<k) continue;
            string t=words[i].substr(0,k);
            mpp[t].push_back(words[i]);
        }
        int count=0;
        for(auto it :mpp){
            if(it.second.size()>=2) count++;
        }
        return count;
    }
};