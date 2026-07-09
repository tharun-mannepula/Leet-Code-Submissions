class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        long long minsofar=prices[0];
        long long ans=0;
        for(int i=1;i<n;i++){
            ans=max(ans,(long long)(prices[i])-minsofar);
            minsofar=min(minsofar,(long long)prices[i]);
        }
        return (int)ans;
    }
};