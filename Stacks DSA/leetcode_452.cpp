class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        stack<pair<int, int>> s;

        vector<pair<int, int>> v;
        for(int i=0; i<points.size();i++){
            v.push_back(make_pair(points[i][0],points[i][1]));
        }

        sort(v.begin(), v.end());

        s.push(v[0]);

        for(int i=1;i<v.size();i++){
            auto t=s.top();
            if(t.second>=v[i].first)    //overlap found
            {   //top updated
                s.pop();
                s.push(make_pair(v[i].first, min(v[i].second, t.second)));
            }
            else{                       //non overlapping
                s.push(v[i]);
            }
        }

        int ans= s.size();
        cout<<"final stack:"<<endl;
        while(!s.empty()){
            auto t=s.top();
            cout<<t.first<<","<<t.second<<endl;
            s.pop();
        }
        return ans;
    }
};
