class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        long long total=accumulate(nums.begin(),nums.end(),0LL);
        
        long long target = total - x;
        if(target<0) return -1;
        int l = 0;
        long long sum = 0;
        int maxLen = -1;
  
        for (int r = 0; r < n; r++) {

            sum += nums[r];

             while (sum > target) {
                sum -= nums[l];
                l++;
            }

            if (sum == target) {
            maxLen = max(maxLen, r - l + 1);
        }
    }
    if(maxLen==-1) return -1;
    else return n-maxLen;
    }
};