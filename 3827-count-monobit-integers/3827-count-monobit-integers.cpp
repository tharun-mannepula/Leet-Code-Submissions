class Solution {
public:
    bool checkMonobit(int n){
        if(n==0 || n==1) return true;
        int check=n&1;
        n>>=1;
        while(n>0){
            if((n&1)!=check) return false;
            n>>=1;
        }
        return true;
    }
    
    int countMonobit(int n) {
        if(n==0) return 1;
        if(n==1) return 2;
        int cnt=0;
        for(int i=0;i<=n;i++){
            if(checkMonobit(i)) cnt++;
        }
        return cnt;
    }
};