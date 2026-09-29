class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int, int> mpp;

        for(int x : nums)
            mpp[x]++;

        vector<int> ans;
        int remaining = nums.size();

        while(remaining > 0) {

            for(auto &it : mpp) {
                if(it.second > 0) {
                    ans.push_back(it.first);
                    it.second--;
                    remaining--;
                }
            }
        }

        return ans;
    }
};