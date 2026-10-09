class Solution {
public:
    int minRotations(string s) {
        int n=s.size();
        int curr=0;
        int result=0;
        for(int i=0;i<n;i++){
         int digit=s[i]-'0';
         int diff=abs(curr-digit);
         result+=min(diff,10-diff);
         curr=digit;
        }
        return result;
    }
};