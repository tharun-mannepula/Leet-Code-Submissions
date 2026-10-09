class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int count=0;
        long long insertions=0;
        int i=0;
        while(i<n){
            if(s[i]=='('){
                count++;
                i++;
            }
            else{
                if(count>0){
                    count--;
                }
                else{
                    insertions++;
                }
                if(s[i+1]==')') i+=2;
                else {
                    insertions++;
                    i++;
                }
            }
        }
        if(count>0) insertions+=(count*2);
        return (int)insertions;
    }
};