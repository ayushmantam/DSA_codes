#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include <queue>
#include <climits>
class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>pq;
        vector<vector<int>> dist(heights.size(),
                                 vector<int>(heights.size(), INT_MAX));
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        while (!pq.empty())
        {
            auto fNode = pq.top();
            pq.pop();

            int fNodeDifference = fNode.first;
            int x = fNode.second.first;
            int y = fNode.second.second;
            // check ans tak to nhi puch gye
            if (x == heights.size() - 1 && y == heights[0].size() - 1)
            {
                return dist[x][y];
            }

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = x + dy[i];
                
                if (newX >= 0 && newY >= 0 && newX < heights.size() &&
                    newY < heights[0].size())
                {
                    int currentDifference =
                        abs(heights[x][y] - heights[newX][newX]);
                    int newMaxDifference =
                        max(currentDifference, fNodeDifference);

                    if (newMaxDifference < dist[newX][newY])
                    {
                        dist[newX][newY] = newMaxDifference;
                        pq.push({newMaxDifference, {newX, newY}});
                    }
                }
            }
        }
        return 0;
    }
};