class Solution {
public:
    int sumDecoded(vector<long long>& nums) {
        int mod=(int)(1e9+7);
        long long int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            long long num=nums[i];
            long long width=(nums[i])%10;
            long long di=(nums[i]/10);
            string st=to_string(di);
            string xi=st.substr(0,width);
            string yi=st.substr(width,(st.size()-width));
            long long int xi2=stoll(xi);
            long long int yi2=stoll(yi);
             long long int result=1;
            while(yi2>0){
               if(yi2%2){
                  result=(result*xi2)%mod;
                  yi2-=1;
               }
               else{
                 xi2=(xi2*xi2)%mod;
                 yi2/=2;
               }
            }
            result%=mod;
            sum+=result;
            sum%=mod;
        }
        sum%=mod;
        return (int)sum;
    }
};