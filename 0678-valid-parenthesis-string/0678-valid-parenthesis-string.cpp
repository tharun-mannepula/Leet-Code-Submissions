class Solution {
public:
    bool checkValidString(string s) {
         int n=s.size();
        int minrange=0;
        int maxrange=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                minrange++;
                maxrange++;
            }
            else if(s[i]==')'){
                minrange--;
                maxrange--;
            }
            else{
                minrange--;
                maxrange++;
            }
            if(minrange<0) minrange=0;
            if(maxrange<0) return false;
        }
        return (minrange==0);
    }
};