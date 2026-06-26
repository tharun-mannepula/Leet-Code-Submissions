class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        int fi;
        int si;
        while(i<j){
            if(nums[i]+nums[j]<target) i++;
            else if(nums[i]+nums[j]>target) j--;
            else{
               fi=i+1;
               si=j+1;
               break;
            }
        }
        return {fi,si};
    }
};