class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        set<int> st;
        for(auto it : nums) st.insert(it);
        int preSum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1) preSum+=nums[i];
            else break;
        }
        for(int i=preSum;i<=1275;i++){
            if(st.find(i)==st.end()) return i;
        }
        return -1;
    }
};