#include<iostream>
using namespace std;
#include<unordered_map>
#include<list>
#include<vector>

class Graph{
    public:
    unordered_map<int, list<pair<int,int>> >adjList;

    void addEdge(int u,int v,int weight,bool direction){
        
        adjList[u].push_back({v,weight});

        if(direction==0){
            adjList[v].push_back({u,weight});
        }
    }

    void printAdjacencyList(){
        for(auto node: adjList){
            cout<<node.first<<"->";
            for(auto nbr: node.second){
                cout<<"("<<nbr.first<<","<<nbr.second<<"), ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g;

    /*
    g.addEdge(0,1,5,0);
    g.addEdge(1,2,3,0);
    g.addEdge(0,2,2,0);
    g.printAdjacencyList();

// 2->(1,3), (0,2), 
// 1->(0,5), (2,3), 
// 0->(1,5), (2,2), 
    */
    g.addEdge(0,1,5,1);
    g.addEdge(1,2,3,1);
    g.addEdge(0,2,2,1);
    g.printAdjacencyList();

// 1->(2,3), 
// 0->(1,5), (2,2), 

}