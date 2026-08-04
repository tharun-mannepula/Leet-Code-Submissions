class Solution{
public:
    int orangesRotting(vector<vector<int>> &grid) {
       int n=grid.size();
       int m=grid[0].size();
       int vis[n][m];
       queue<pair<pair<int,int>,int>> q;
       int cntFresh=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                 q.push({{i,j},0});
                 vis[i][j]=2;
            }
            else vis[i][j]=0;
            if(grid[i][j]==1) cntFresh++;
        }
    }
       int delRow[]={-1,0,1,0};
       int delCol[]={0,-1,0,1};
       int maxTime=0;
       int cnt=0;
       while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int time=q.front().second;
        q.pop();
        maxTime=max(maxTime,time);
        for(int i=0;i<4;i++){
            int nrow=row+delRow[i];
            int ncol=col+delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                vis[nrow][ncol]=2;
                q.push({{nrow,ncol},time+1});
                cnt++;
            }
        }
       }
       if(cntFresh!=cnt) return -1;
       else return maxTime; 
    }
};