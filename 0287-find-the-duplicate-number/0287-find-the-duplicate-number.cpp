class Solution {
public:
    int findDuplicate(vector<int>& nums) {
         int i = 0;
        int n = nums.size();

        while (i < n) {
            if (nums[i] != i + 1) {
                int correct = nums[i] - 1;

                if (nums[i] != nums[correct])
                    swap(nums[i], nums[correct]);
                else
                    return nums[i];
            } else {
                i++;
            }
        }

        return -1;
    }
};