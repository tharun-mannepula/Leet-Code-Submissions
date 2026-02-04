class Solution {
public:
    vector<int> findPGEE(vector<int>& nums){
     int n=nums.size();
     vector<int> pgee(n);
     stack<int> st;
     for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
        if(st.empty()) pgee[i]=-1;
        else pgee[i]=st.top();
        st.push(i);
     }
     return pgee;
    }
    vector<int> findNGE(vector<int>& nums){
         int n=nums.size();
     vector<int> nge(n);
     stack<int> st;
     for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
        if(st.empty()) nge[i]=n;
        else nge[i]=st.top();
        st.push(i);
     }
     return nge;
    }
    vector<int> findPSEE(vector<int>& nums){
         int n=nums.size();
     vector<int> psee(n);
     stack<int> st;
     for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
        if(st.empty()) psee[i]=-1;
        else psee[i]=st.top();
        st.push(i);
     }
     return psee;
    }
    vector<int> findNSE(vector<int>& nums){
         int n=nums.size();
     vector<int> nse(n);
     stack<int> st;
     for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
        if(st.empty()) nse[i]=n;
        else nse[i]=st.top();
        st.push(i);
     }
     return nse;
    }
    
    long long sumofSubArrayMaxs(vector<int>& nums){
        int n=nums.size();
        vector<int> nge=findNGE(nums);
        vector<int> pgee=findPGEE(nums);
        long long sum=0;
        for(int i=0;i<n;i++){
            int left=i-pgee[i];
            int right=nge[i]-i;
            long long freq=left*right*1LL;
            long long val=(freq*nums[i]*1LL);
            sum+=val;
        }
        return sum;
    }

    long long sumofSubArrayMins(vector<int>& nums){
        int n=nums.size();
        vector<int> nse=findNSE(nums);
        vector<int> psee=findPSEE(nums);
        long long sum=0;
        for(int i=0;i<n;i++){
            int left=i-psee[i];
            int right=nse[i]-i;
            long long freq=left*right*1LL;
            long long val=(freq*nums[i]*1LL);
            sum+=val;
        }
        return sum;
    }
    
    long long subArrayRanges(vector<int> &nums) {
        return sumofSubArrayMaxs(nums)-sumofSubArrayMins(nums);
    }
};
