class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> dummy(n,0);
        for(int i=0;i<n;i++){
            dummy[i]=abs(nums[i]);
        }
        sort(dummy.begin(),dummy.end(),greater<int>());
        int l1=0;
        int r1=n-1;
        int l2=0;
        int r2=1;
        while(l1<=r1){
            if(l1==r1){
                nums[l2]=dummy[r1];
                break;
            }
            nums[l2]=dummy[l1];
            l1++;
            l2+=2;
            nums[r2]=dummy[r1];
            r1--;
            r2+=2;
        }
        long long sum=0;
        for(int i=0;i<n;i++){
            if(i%2==0) sum+=(nums[i]*nums[i]);
            else sum-=(nums[i]*nums[i]);
        }
        return sum;
    }
};