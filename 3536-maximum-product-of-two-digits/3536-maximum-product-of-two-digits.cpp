class Solution {
public:
    int maxProduct(int n) {
        string s=to_string(n);
        sort(s.begin(),s.end());
        int size=s.size();
        n=stoi(s);
        int Last=n%10;
        n/=10;
        int beforeLast=n%10;
        return (beforeLast*Last);
    }
};