class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        int largest=INT_MIN;
        int smallest=INT_MAX;
        for(auto it : nums){
            largest=max(largest,it);
            smallest=min(smallest,it);
        }
        vector<int> ans;
        for(int i=smallest+1;i<largest;i++){
             if(find(nums.begin(), nums.end(), i) == nums.end()) ans.push_back(i);
        }
        return ans;
    }
};