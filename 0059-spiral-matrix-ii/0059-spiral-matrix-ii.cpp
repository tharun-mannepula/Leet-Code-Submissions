class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int it=1;
        vector<vector<int>> ans(n,vector<int>(n,0));
        int top=0;
        int left=0;
        int right=n-1;
        int bottom=n-1;
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                ans[top][i]=it;
                it++;
            }
            top++;
            for(int i=top;i<=bottom;i++){
                ans[i][right]=it;
                it++;
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                ans[bottom][i]=it;
                it++;
            }
            bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    ans[i][left]=it;
                    it++;
                }
                left++;
            }
        }
        return ans;
    }
};