class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
      int n = nums.size();

        int i = 0;

        while (i < n) {

            if (s[i] == '0') {
                i++;
                continue;
            }

            // Start of consecutive 1s
            int l = i;
            int r = i;

            while (r + 1 < n && s[r + 1] == '1') {
                r++;
            }

            // There is a 0 before this block
            if (l > 0) {

                // Find minimum value and its index
                int minIndex = l;

                for (int j = l + 1; j <= r; j++) {
                    if (nums[j] < nums[minIndex]) {
                        minIndex = j;
                    }
                }

                if (nums[minIndex] < nums[l - 1]) {
                    s[l - 1] = '1';
                    s[minIndex] = '0';
                }
            }

            i = r + 1;
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ans += nums[i];
            }
        }
     return ans;
    }
};