class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq1;
        priority_queue<int,vector<int>> pq2;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pq1.push(nums[i]);
            pq2.push(nums[i]);
        }
        int largest_sum=0;
        int smallest_sum=0;
        while(k>0){
            largest_sum+=pq2.top();
            pq2.pop();
            smallest_sum+=pq1.top();
            pq1.pop();
            k--;
        }
        return abs(largest_sum-smallest_sum);
    }
};