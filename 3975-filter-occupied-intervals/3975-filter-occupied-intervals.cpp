class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int fs, int fe) {
        int n=occupiedIntervals.size();
        vector<vector<int>> merged;
        sort(occupiedIntervals.begin(),occupiedIntervals.end());
        merged.push_back(occupiedIntervals[0]);
        for(int i=1;i<n;i++){
            vector<int> last=merged.back();
            vector<int> curr=occupiedIntervals[i];
            if(curr[0]<=last[1]+1) {
                merged.back()[1]=max(merged.back()[1],curr[1]);
            }
            else{
                merged.push_back(curr);
            }
        }
        vector<vector<int>> ans;
        for (auto interval : merged) {
            int L = interval[0];
            int R = interval[1];

            if (L < fs)
                ans.push_back({L, min(R, fs - 1)});

            if (R > fe)
                ans.push_back({max(L, fe + 1), R});
        }

        return ans;
    }
};