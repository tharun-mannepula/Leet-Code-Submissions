class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<long long>> dp(n,vector<long long>(amount+1,0));
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                dp[0][i] = 1;
        }
         for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= amount; target++) {
                int notTaken = dp[ind - 1][target];
 
                int taken = 0;
                if (coins[ind] <= target)
                    taken = dp[ind][target - coins[ind]];
 
                dp[ind][target] = (1LL*notTaken + 1LL*taken);
            }
        }  
        return dp[n-1][amount];
    }
};