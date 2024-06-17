#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;.0 


class Graph{
    public:
    unordered_map<int,list<int>>adjList;       //LIST ki jagah vector ,set bhi use kar sakte hai

    void addEdge(int u,int v,bool direction){
        //direction = 0 -> undirected graph
        //direction = 1 -> directed graph
        //create an egde from u to v
        adjList[u].push_back(v);

        if(direction==0){
            //undirected edge
            //create an egde from v to u
            adjList[v].push_back(u);
        }
    }

    void printAdjacencyList(){
        for(auto node: adjList){
            cout<<node.first<<"->" ;
            for(auto neighbour: node.second){
                cout<<neighbour<<", ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g;

/*
    //undirected input
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(0,2,0);
*/
    //directed input
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(0,2,1);
    cout<<endl;
    g.printAdjacencyList();

}

