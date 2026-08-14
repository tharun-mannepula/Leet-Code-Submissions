class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> mpp;
        int l=0;
        int r=0;
        int maxi=1;
        while(r<n){
            mpp[s[r]]++;
            if(mpp[s[r]]>2){
                while(mpp[s[r]]>2){
                    mpp[s[l]]--;
                    if(mpp[s[l]]==0) mpp.erase(mpp[s[l]]);
                    l++;
                }
            }
             maxi=max(maxi,r-l+1);
             r++;
        }
        return maxi;
    }
};