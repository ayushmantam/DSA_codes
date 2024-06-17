class Solution
{
private:
    vector<int> nextSmallerElement(vector<int> arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans[n];
        for (int i = n; i >= 0; i--)
        {
            int curr = arr[i];
            while (s.top() >= curr)
            {
                s.pop();
            }
            // ans is stack ka top
            ans[i] = s.top();
            s.push(curr);
        }
        return ans;
    }

public:
    int largestRectangularArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> next[n];
        int next = nextSmallerElement(heights, n);

        vector<int> prev[n];
        prev = previousSmallerElement(heights, n);

        for (int i = 0; i < n; i++)
        {
            int l = heights[i];
            int b = next[i] - prev[i] - 1;

            if (next[i] == -1)
            {
                next[i] = n;
            }

            int newArea = l * b;
            int area = (area, newArea);
        }
        return area;
    }
}