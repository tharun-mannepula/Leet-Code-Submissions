class Solution {
public:
     bool dfs(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& pathVis,vector<int>& check){
    vis[node]=1;
    pathVis[node]=1;
    for(auto it : adj[node]){
        if(!vis[it]){
            if(dfs(it,adj,vis,pathVis,check)){
                check[node]=0;
                return true;
            }
        }
        else if(pathVis[it]==1){
            check[node]=0;
            return true;
        }
    }
    check[node]=1;
    pathVis[node]=0;
    return false;
 }

    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
         int V=adj.size();
         vector<int> vis(V,0);
         vector<int> pathVis(V,0);
         vector<int> check(V,0);
        vector<int> safeNodes;
        for(int i=0;i<V;i++){
            if(!vis[i]) dfs(i,adj,vis,pathVis,check);
        }
        for(int i=0;i<V;i++){
            if(check[i]) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};