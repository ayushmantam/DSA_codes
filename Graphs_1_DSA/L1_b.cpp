#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
    public:
    unordered_map< int, list< pair<int,int> > >adjList;

    void addEdge(int u,int v,int weight,bool direction){
        //direction = 0 -> undirected graph
        //direction = 1 -> directed graph
        //create an egde from u to v
        adjList[u].push_back({v,weight});

        if(direction==0){
            //undirected edge
            //create an egde from v to u
            adjList[v].push_back({u,weight});
        }
    }

    void printAdjacencyList(){
        for(auto node: adjList){
            cout<<node.first<<"->" ;
            for(auto neighbour: node.second){
                cout<<"("<<neighbour.first<<","<<neighbour.second<<"), ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g;

//   g.addEdge(srcNode,destNode,weight,direction);
/*
    //undirected input
    g.addEdge(0,1,5,0);
    g.addEdge(1,2,8,0);
    g.addEdge(0,2,6,0);
*/
    //directed input
    g.addEdge(0,1,5,1);
    g.addEdge(1,2,8,1);
    g.addEdge(0,2,6,1);
    cout<<endl;
    g.printAdjacencyList();

}

// 1->(2,8), 
// 0->(1,5), (2,6),

