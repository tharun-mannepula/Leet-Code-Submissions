class Solution {
public:
    bool static comparator(pair<char,int>& a,pair<char,int>& b){
        return a.second>b.second;
    }
    
    int minimumPushes(string word) {
        int s=word.size();
        int avl=(s+8-1)/8;
        int avl1,avl2,avl3,avl4=0;
        if(avl==1) avl1=8;
        else if(avl==2) avl1=avl2=8;
        else if(avl==3) avl1=avl2=avl3=8;
        else avl1=avl2=avl3=avl4=8;
        unordered_map<char,int> mpp;
        for(int i=0;i<s;i++){
            mpp[word[i]]++;
        }
        vector<pair<char,int>> ans;
        for(auto it : mpp){
            ans.push_back({it.first,it.second});
        }
        sort(ans.begin(),ans.end(),comparator);
        int pushes=0;
        for(auto it : ans){
            if(avl1){
                pushes+=(it.second*1);
                avl1--;
            }
            else if(avl2){
                pushes+=(it.second*2);
                avl2--;
            }
            else if(avl3){
                pushes+=(it.second*3);
                avl3--;
            }
            else{
                pushes+=(it.second*4);
                avl4--;
            }
        }
        return pushes;
    }
};