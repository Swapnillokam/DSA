//92_StackLargestRectangleInHistogramAndMaximalRectangle
//lc - 84 ->https://leetcode.com/problems/largest-rectangle-in-histogram/description/'=
//0(3n) - 3 passes , check the other method to make it in a single pass i.e 0(n)

vector<int> nsr(vector<int>& v) {
        vector<int> ans(v.size(), v.size());
        stack<int> st;
        for (int i = 0; i < v.size(); i++) {
            while (!st.empty() && v[st.top()] > v[i]) {
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> nsl(vector<int>& v) {
        vector<int> ans(v.size(), -1);
        stack<int> st;
        for (int i = v.size() - 1; i >= 0; i--) {
            while (!st.empty() && v[st.top()] > v[i]) {
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& v) {
        int maxArea = 0;
        vector<int> nsright = nsr(v);
        // for(int i=0;i<nsright.size();i++){
        //     cout<<nsright[i]<<" ";
        // }
        // cout<<endl;
        vector<int> nsleft = nsl(v);
        // for(int i=0;i<nsleft.size();i++){
        //     cout<<nsleft[i]<<" ";
        // }

        for (int i = 0; i < nsleft.size(); i++) {
            int area = v[i] * (nsright[i] - nsleft[i] - 1);
            maxArea = max(maxArea,area );
        }

        return maxArea;
    }