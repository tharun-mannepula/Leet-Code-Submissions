class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev;
        for(int i=0;i<n;i++) prev.push_back(1);
        for(int i=1;i<m;i++){
            vector<int> temp(n,1);
            for(int j=1;j<n;j++){
                temp[j]=prev[j]+temp[j-1];
            }
            prev=temp;
        }
        return prev.back();
    }
};