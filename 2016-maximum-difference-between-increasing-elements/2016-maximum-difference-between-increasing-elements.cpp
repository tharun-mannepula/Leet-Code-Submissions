class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int minsofarindex=0;
        long long ans=-1;
        for(int i=1;i<n;i++){
          if(nums[i]-nums[minsofarindex]>0) ans=max(ans,(long long)nums[i]-(long long)nums[minsofarindex]);
          if(nums[i]<nums[minsofarindex]) minsofarindex=i;
        }
        return (int)ans;
    }
};