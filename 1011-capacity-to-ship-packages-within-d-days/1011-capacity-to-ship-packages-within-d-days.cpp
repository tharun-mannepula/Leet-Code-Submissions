class Solution {
public:
    int checkMinimumCapacity(vector<int>& weights,int balance,int n){
        int curr_weight=0;
        int days=1;
        for(int i=0;i<n;i++){
            if(curr_weight+weights[i]<=balance) curr_weight+=weights[i];
            else{
                curr_weight=weights[i];
                days++;
            }
        }
        return days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int maxi=*max_element(weights.begin(),weights.end());
        int aggregatesum=accumulate(weights.begin(),weights.end(),0);
        int low=maxi;
        int high=aggregatesum;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(checkMinimumCapacity(weights,mid,n)<=days) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};