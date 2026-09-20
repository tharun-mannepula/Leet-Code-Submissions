class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        int degree=0;
        for(int i=0;i<n;i++){
            int index=i+1;
            int reverse_position=26-(s[i]-'a');
            degree+=(index*reverse_position);
        }
        return degree;
    }
};