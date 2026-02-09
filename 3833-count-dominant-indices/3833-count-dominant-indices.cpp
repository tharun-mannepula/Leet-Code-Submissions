class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n=nums.size();
        int curr_sum=nums[n-1];
        int curr_avg=nums[n-1];
        int curr_count=1;
        int res=0;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>curr_avg) res++;
            curr_count++;
            curr_sum+=nums[i];
            curr_avg=(curr_sum)/curr_count;
        }
        return res;
    }
};