class Solution {
public:
    int maxProfit(vector<int>& values) {
      int n=values.size();
      vector<int> ahead(2,0);
      vector<int> cur(2,0);
     for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
        if(buy){
            cur[buy]= max(-values[ind]+ahead[0],ahead[1]);
        }
        else cur[buy]= max(values[ind]+ahead[1],ahead[0]);
        }
        ahead=cur;
     }
      return ahead[1];
    }
};