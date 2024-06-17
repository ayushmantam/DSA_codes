#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int>winner;
        set<int>loser;
        for(int i=0; i < matches.size(); i++){
            winner.insert(matches[i][0]);
            loser.insert(matches[i][1]);
        }

        vector<int>answer0;
        for(auto player:winner){
            if(!loser.count(player)){
                answer0.push_back(player);
            }
        }
        sort(answer0.begin(),answer0.end());
        
        unordered_map<int,int>lostCount;
        for(int i=0; i < matches.size(); i++){
            lostCount[matches[i][1]]++;
        }

        vector<int>answer1;
        for(auto it:lostCount){
            if(it.second==1){
                answer1.push_back(it.first);
            }
        }
        sort(answer1.begin(),answer1.end());
        vector<vector<int>>answer;
        answer.push_back(answer0);
        answer.push_back(answer1);

        return answer;

    }
};