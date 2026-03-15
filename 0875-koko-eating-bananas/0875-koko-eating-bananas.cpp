class Solution {
    long division(vector<int>& arr,int d){
  int n=arr.size();
  long sum=0;
  for(int i=0;i<n;i++){
    sum+=(arr[i]+d-1)/d;
  }
  return sum;
 }
public:
    int minEatingSpeed(vector<int>& nums, int h) {
                   int maxi=*max_element(nums.begin(),nums.end());
       long low=1;
       long high=maxi;
       while(low<=high){
        long mid=low+(high-low)/2;
        if(division(nums,mid)<=h) high=mid-1;
        else low=mid+1;
       }
       return (int)low;
    }
};