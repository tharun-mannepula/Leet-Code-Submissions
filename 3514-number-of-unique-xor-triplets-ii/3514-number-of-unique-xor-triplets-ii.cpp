class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
         unordered_set<int> first, second, third;
        for (int x : nums)
            first.insert(x);
        for (int a : first)
            for (int x : nums)
                second.insert(a ^ x);
        for (int a : second)
            for (int x : nums)
                third.insert(a ^ x);
        
        return third.size();
    }
};