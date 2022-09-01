class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> ple(n);
        vector<int> nle(n);
        ple[0] = 0;
        nle[n-1] = n-1;
        //calculating ple
        st.push(0);
        for(int i=1; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                ple[i] = 0;
            }else{
                ple[i] = st.top() + 1;
            }
            st.push(i);
        }
        //calculating nle
        while(!st.empty()){
            st.pop();
        }
        
        st.push(n-1);
        for(int i=n-2; i>=0; i--){
            
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(st.empty()){
                nle[i] = n-1;
            }else{
                nle[i] = st.top() - 1;
            }
            st.push(i);
        }           
            
            int mx = 0;
        for(int i=0; i<n; i++){
            // cout<<ple[i]<<" ";
            mx = max(mx, abs(nle[i] - ple[i] + 1)*heights[i]);
        }
        return mx;
    }
};