#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>

using namespace std;
template <typename T>
class Graph{
    public:
    unordered_map<T,list<T>>adjList;
 
    void addEdge(T u,T v,bool direction){
        // direction = 0 -> undirected graph
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
     void bfs(int src, unordered_map<int, bool>& visited) {
    queue<int> q;
    
    q.push(src);
    visited[src] = true;

    while(!q.empty()) {
      int frontNode= q.front();
      q.pop();
      cout << frontNode << ", ";

      //insert neighbours
      for(auto neighbour: adjList[frontNode]) {
        if(!visited[neighbour] ) {
          q.push(neighbour);
          visited[neighbour] = true;
        }
      }
    }
  }
};
    
   


int main(){
    // Graph<char> g;

    // g.addEdge('a','b',0);
    // g.addEdge('b','c',0);
    // g.addEdge('a','c',0);
    // g.printAdjacencyList();

    
}

// c->b, a, 
// b->a, c, 
// a->b, c, 


