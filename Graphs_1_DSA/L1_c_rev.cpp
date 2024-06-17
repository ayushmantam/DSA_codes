#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;
template <typename T>

class Graph
{
public:
    unordered_map<T, list<T> > adjList;

    void addEdge(T u, T v, bool direction)
    {
        adjList[u].push_back(v);
        if (direction == 0)
        {
            adjList[v].push_back(u);
        }
    }

    void printAdjacnecyList()
    {
        for (auto node : adjList)
        {
            cout << node.first << "->";
            for (auto nbr : node.second)
            {
                cout << nbr << ", ";
            }
            cout << endl;
        }
    }

    // void bfs(int src, unordered_map<int, bool> &visited)
    // {
    //     queue<int> q;

    //     q.push(src);
    //     visited[src] = true;

    //     while (!q.empty())
    //     {
    //         int frontNode = q.front();
    //         q.pop();
    //         cout << frontNode << ", ";

    //         // inserting nbrs
    //         for (auto nbr : adjList[frontNode])
    //         {
    //             if (!visited[nbr])
    //             {
    //                 q.push(nbr);
    //                 visited[nbr] = true;
    //             }
    //         }
    //     }
    // }

    void bfs(int src,unordered_map<int,bool>&visited){
        queue<int>q;
        q.push(src);
        visited[src]=true;

        while (q.empty())
        {
            int fNode=q.front();
            cout<<fNode<<endl;
            q.pop();

            for(auto nbr:adjList[fNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr];
                }
            }
        }
        
    }

    void dfs(int src,unordered_map<int,bool>&visited){

        cout<<src<<", ";
        visited[src]=true;

        for(auto nbr: adjList[src]){
            if(!visited[nbr]){
                dfs(nbr,visited);
            }
        }
    }
};

int main()
{
    /*
    Graph<char> g;

    g.addEdge('a','b',0);
    g.addEdge('b','c',0);
    g.addEdge('a','c',0);
    g.printAdjacnecyList();
    */

    Graph<int> g;
    int n = 9;
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(2, 4, 0);
    g.addEdge(3, 5, 0);
    g.addEdge(3, 6, 0);
    g.addEdge(4, 7, 0);
    g.addEdge(4, 8, 0);
    g.addEdge(8, 9, 0);

    g.printAdjacnecyList();
    cout<<endl;
    
    unordered_map<int,bool>visited;
    cout<<"Printing BFS\n";
    for (int i = 0; i <=n; i++)
    {
        if(!visited[i]){
            g.bfs(i,visited);
        }
    }

    unordered_map<int,bool>visited2;
    cout<<"Printing DFS"<<endl;
    for(int i=1;i <=n;i++){
        if(!visited2[i]){
            g.dfs(i,visited2);
        }
    }
    
}