class Solution {
public:
    int myfunc(int ind,vector<int>& nums){
        vector<int> arr;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(ind!=i) arr.push_back(nums[i]);
        }
        int m=arr.size();
        vector<int> prefixGCD(m,0);
        vector<int> suffixGCD(m,0);
        prefixGCD[0]=arr[0];
        suffixGCD[m-1]=arr[m-1];
        for(int i=1;i<m;i++) prefixGCD[i]=gcd(arr[i],prefixGCD[i-1]);
        for(int i=m-2;i>=0;i--) suffixGCD[i]=gcd(arr[i],suffixGCD[i+1]);
        int cnt=0;
        for(int i=0;i<m-1;i++){
            if(prefixGCD[i]==suffixGCD[i+1]) cnt++;
        }
        return cnt;
    }
    
    int maxValidSplits(vector<int>& nums) {
        int n=nums.size();
        int ans=myfunc(-1,nums);
        for(int i=0;i<n;i++){
            ans=max(ans,myfunc(i,nums));
        }
        return ans;
    }
};