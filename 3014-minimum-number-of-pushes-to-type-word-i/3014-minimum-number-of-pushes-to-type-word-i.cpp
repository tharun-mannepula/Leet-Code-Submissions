class Solution {
public:
    int minimumPushes(string word) {
        int s=word.size();
        if(s<=8) return s;
        int eightsets=s/8;
        int remaining=s%8;
        int pushes=0;
        if(eightsets==1) pushes+=8;
        else if(eightsets==2) pushes+=24;
        else pushes+=48;
        if(remaining) pushes+=(remaining*(eightsets+1));
        return pushes;
    }
};