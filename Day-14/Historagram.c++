class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> st;

        // finding out left smallest element for each index using stack
        for (int i = 0; i < n; i++)
        {
            while (st.size() && heights[i] <= heights[st.top()])
            {
                st.pop();
            }
            if (!st.size())
                left[i] = 0;
            else
                left[i] = st.top() + 1;
            st.push(i);
        }

        // emptying the stack to save the space complexity
        while (!st.empty())
            st.pop();

        // finding out right smallest element for each index using stack
        for (int i = n - 1; i >= 0; i--)
        {
            while (st.size() && heights[i] <= heights[st.top()])
            {
                st.pop();
            }
            if (!st.size())
                right[i] = n - 1;
            else
                right[i] = st.top() - 1;
            st.push(i);
        }

        // calculating area for each index with the help of right and left smallest
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, (right[i] - left[i] + 1) * heights[i]);
        }
        return maxi;
    }
};