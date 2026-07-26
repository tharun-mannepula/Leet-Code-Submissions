class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long result=(nums[n-1]-1);
        result*=(nums[n-2]-1);
        return (int)result;
    }
};