class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorr=0;
        int maxlen=0;
        int n=nums.size();
        int i=0;
        while(i<n){
            xorr^=nums[i];
            i++;
        }
        if(xorr!=0) return n;
        else{
           for(int i=0;i<n;i++){
             if(nums[i]!=0) maxlen=n-1;
           }
        }
        return maxlen;
    }
};