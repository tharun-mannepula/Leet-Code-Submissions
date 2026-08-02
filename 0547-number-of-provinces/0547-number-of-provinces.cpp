class Solution {
public:
    void bfsTraversal(int node,vector<int> adjList[],vector<int>& vis,vector<int>& bfs){
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            bfs.push_back(curr);
            for(auto it : adjList[curr]){
                if(vis[it]==0){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return;
    }
    
    
    int findCircleNum(vector<vector<int>>& adj) {
        int n=adj.size();
       vector<int> bfs;
       int count=0;
       vector<int> vis(n+1,0);
       vector<int> adjList[n];
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j]==1 && i!=j) adjList[i].push_back(j);
        }
       }
       for(int i=0;i<n;i++){
         if(vis[i]==0){
            count++;
            bfsTraversal(i,adjList,vis,bfs);
         }
       }
       return count;
    }
};