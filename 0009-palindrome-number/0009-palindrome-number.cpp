class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int ele=x;
        long rev=0;
        while(ele>0){
            long ld=ele%10;
            rev=rev*10+ld;
            ele/=10;
        }
        return (int)rev==x;
    }
};