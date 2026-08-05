class Solution {
public:
     int func(vector<int>& nums){
     int n=nums.size();
        int prev2=0;
        int prev=nums[0];
        for(int i=1;i<n;i++){
         int take=nums[i];
         if(i>1) take+=prev2;
         int notTake=0+prev;
         int curi=max(take,notTake);
         prev2=prev;
         prev=curi;
        }
        return prev;
     }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> arr1;
        vector<int> arr2;
        for(int i=0;i<n;i++){
            if(i!=0) arr1.push_back(nums[i]);
            if(i!=n-1) arr2.push_back(nums[i]);
        }
        int res1=func(arr1);
        int res2=func(arr2);
        return max(res1,res2);
    }
};