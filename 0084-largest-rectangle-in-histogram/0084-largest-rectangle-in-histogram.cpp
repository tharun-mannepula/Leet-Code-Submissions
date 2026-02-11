class Solution
{
public:
    int largestRectangleArea(vector<int> &heights) {
      int n=heights.size();
      int maxArea=INT_MIN;
      stack<int> st;
      for(int i=0;i<n;i++){
        while(!st.empty() && heights[st.top()]>=heights[i]){
            int ele=st.top();
            st.pop();
            int pse=st.empty()?-1:st.top();
            maxArea=max(maxArea,(heights[ele]*(i-pse-1)));
        }
        st.push(i);
      }
      while(!st.empty()){
        int ele=st.top();
        st.pop();
        int pse=st.empty()?-1:st.top();
        maxArea=max(maxArea,(heights[ele]*(n-pse-1)));
      }
      return maxArea;
    }
};