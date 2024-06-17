#include<iostream>
using namespace std;
#include<list>
#include<unordered_map>
#include<vector>

class Graph{
    public:
    unordered_map<int,list<int>>adjList;

    void addEdge(int u,int v,bool direction){
        adjList[u].push_back(v);
        if(direction==0){
            adjList[v].push_back(u);
        }
    }

    void printAdjacencyList(){
        for(auto node:adjList){
            cout<<node.first<<"->";
            for(auto nbr: node.second){
                cout<<nbr<<", ";
            }
            cout<<endl;
        }
    }
};


int main(){
    Graph g;
/*
    //undirected graph
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(0,2,0);
    g.printAdjacencyList();

// 2->1, 0, 
// 1->0, 2, 
// 0->1, 2,
*/

    //directed graph
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(0,2,1);
    g.printAdjacencyList();

// 1->2, 
// 0->1, 2,

}