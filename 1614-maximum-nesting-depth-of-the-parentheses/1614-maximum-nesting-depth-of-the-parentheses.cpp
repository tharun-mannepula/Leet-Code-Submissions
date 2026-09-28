class Solution {
public:
    int maxDepth(string s) {
        int depth=0;
        int n=s.size();
        int max_Depth=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                depth++;
                max_Depth=max(max_Depth,depth);
            }
            else if(s[i]==')'){
                depth--;
                 max_Depth=max(max_Depth,depth);
            }
        }
        return max_Depth;
    }
};