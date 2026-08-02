class Solution {
public:
       bool isValid(int row,int col,int n,int m){
      if(row<0 || row>=n) return false;
      if(col<0 || col>=m) return false;
      return true;
    }
    
    void bfsTraversal(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid){
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty()){
            int crow=q.front().first;
            int ccol=q.front().second;
            q.pop();
            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};

            for (int k = 0; k < 4; k++) {
                int newRow = crow + delRow[k];
                int newCol = ccol + delCol[k];

               if (isValid(newRow, newCol, n, m) && !vis[newRow][newCol] &&
        grid[newRow][newCol] == '1') {

                  vis[newRow][newCol] = 1;
                  q.push({newRow, newCol});
             }
          }
        }
    }
    
    
    int numIslands(vector<vector<char>> &grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfsTraversal(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};