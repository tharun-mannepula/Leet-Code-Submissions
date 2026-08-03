class Solution{
    public:
    bool isValid(int r,int c,int n,int m){
        if(r<0 || r>=n) return false;
        if(c<0 || c>=m) return false;
        return true;
    }
    void bfsTraversal(int sr,int sc,
                  vector<vector<int>>& vis,
                  vector<vector<int>>& image,
                  int initialColor,
                  int newColor,
                  int n,int m){

    queue<pair<int,int>> q;

    q.push({sr,sc});
    vis[sr][sc]=1;
    image[sr][sc]=newColor;

    int delRow[]={-1,0,1,0};
    int delCol[]={0,1,0,-1};

    while(!q.empty()){
        auto [row,col]=q.front();
        q.pop();

        for(int k=0;k<4;k++){
            int crow=row+delRow[k];
            int ccol=col+delCol[k];

            if(isValid(crow,ccol,n,m) &&
               !vis[crow][ccol] &&
               image[crow][ccol]==initialColor){

                vis[crow][ccol]=1;
                image[crow][ccol]=newColor;
                q.push({crow,ccol});
            }
        }
    }
}


    vector<vector<int>> floodFill(vector<vector<int>> &image,int sr, int sc, int newColor) {
       int n=image.size();
       int m=image[0].size();
       int initialColor=image[sr][sc];
       if(initialColor==newColor) return image;
       vector<vector<int>> vis(n,vector<int>(m,0));
         bfsTraversal(sr,sc,vis,image,initialColor,newColor,n,m);
       return image;
    }
};
