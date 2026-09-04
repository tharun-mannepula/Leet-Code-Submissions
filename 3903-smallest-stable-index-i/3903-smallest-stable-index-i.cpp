class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefixMax(n,0);
        vector<int> suffixMin(n,0);
        prefixMax[0]=nums[0];
        suffixMin[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            prefixMax[i]=max(prefixMax[i-1],nums[i]);
            suffixMin[n-i-1]=min(suffixMin[n-i],nums[n-i-1]);
        }
        for(int i=0;i<n;i++){
            if(prefixMax[i]-suffixMin[i]<=k) return i;
        }
        return -1;
    }
};