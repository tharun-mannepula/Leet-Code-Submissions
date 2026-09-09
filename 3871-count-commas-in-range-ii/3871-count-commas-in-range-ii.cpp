class Solution {
public:
    long long countCommas(long long n) {
        long long res=0;
        long long lower=1000;
        long long commas=1;
        while(lower<=n){
            long long upper=lower*1000-1;
            if(upper>n) upper=n;
            long long countofNos=upper-lower+1;
            res+=(countofNos*commas);
            lower=upper+1;
            commas++;
        }
        return res;
    }
};