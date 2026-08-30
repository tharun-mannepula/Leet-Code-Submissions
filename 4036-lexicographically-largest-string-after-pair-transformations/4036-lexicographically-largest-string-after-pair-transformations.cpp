class Solution {
public:
    int getNearPowerOf2(int num){
          int p = 1 << 25;

        while (p > num)
            p /= 2;

        return p;
    }
    vector<string> largestString(vector<int>& nums) {
        unordered_map<int,char> mpp;
        for(int i=0;i<26;i++){
            mpp[1<<i]='a'+i;
        }
        int n=nums.size();
        vector<string> ans;
        for(int i=0;i<n;i++){
            int num=nums[i];
            string curr="";
            while(num>0){
                int Nearpowerof2=getNearPowerOf2(num);
                curr+=mpp[Nearpowerof2];
                num=num-Nearpowerof2;
            }
            ans.push_back(curr);
        }
        return ans;
    }
};