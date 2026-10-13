class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
           nums[i]=(nums[i]*nums[i]);
        }
        nth_element(nums.begin(),nums.begin()+n/2,nums.end());
        long long smallSum=accumulate(nums.begin(),nums.begin()+n/2,0LL);
        long long largeSum=accumulate(nums.begin()+n/2,nums.end(),0LL);
        return largeSum-smallSum;
    }
};