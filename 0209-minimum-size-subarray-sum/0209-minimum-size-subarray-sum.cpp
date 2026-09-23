class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=0;
        int minLen=INT_MAX;
        long long sum=0;
        while(r<n){
            sum+=nums[r];
            while(sum>=target){
               minLen=min(minLen,r-l+1);
               sum-=nums[l];
               l++;
            }
            r++;
        }
        if(minLen==INT_MAX) return 0;
        else return minLen;
    }
};