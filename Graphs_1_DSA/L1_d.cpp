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
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, bool direction)
    {
        adjList[u].push_back(v);
        if (!direction)
        {
            adjList[v].push_back(u);
        }
    }

    void printAdjacencyList()
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

    void bfs(T src, unordered_map<T, bool> &visited)
    {
        queue<T> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            T frontNode = q.front();
            q.pop();
            cout << frontNode << ", ";

            // Inserting neighbors
            for (auto nbr : adjList[frontNode])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }


    void dfs(int src,unordered_map<int,bool>& visited){
        cout<<src<<", ";
        visited[src]=true;

        for(auto nbr:adjList[src]){
            if(!visited[nbr]){
                dfs(nbr ,visited);
            }
        }
    }
    
    bool checkCyclicUsingBfs(int src,unordered_map<int,bool>&visited){
        queue<int>q;
        unordered_map<int,int>parent;

        q.push(src);
        visited[src]=true;
        parent[src]=-1;

        while(!q.empty()){
             int frontNode=q.front();
             q.pop();

             for(auto nbr:adjList[frontNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                    parent[nbr]=frontNode;
                }
                if(visited[nbr]&& nbr!=parent[frontNode]){
                    //cycle present
                    return true;
                }
             }
        }
        return false;
    }

    bool checkCyclicUsingDfs(int src,unordered_map<int,bool>&visited,int parent){
        visited[src]=true;
        for(auto nbr: adjList[src]){
            if(!visited[nbr]){
                bool checkAagekaAns=checkCyclicUsingDfs(nbr,visited,src);
                if(checkAagekaAns==true)  //it is like a base condition
                    return true;
            }

            if(visited[nbr]&& nbr!=parent){
                return true;
            }
        }
        return false;
    }

    bool checkCyclicDirectedGraphUsingDfs(int src, unordered_map<int,bool>& visited, unordered_map<int,bool> dfsVisited) {

		visited[src] = true;
		dfsVisited[src] = true;

		for(auto nbr: adjList[src]) {
			if(!visited[nbr]) {
				bool aageKaAnswer = checkCyclicDirectedGraphUsingDfs(nbr, visited, dfsVisited);
				if(aageKaAnswer == true)
					return true;
			}
			if(visited[nbr] == true && dfsVisited[nbr] == true) {
				return true;
			}
		}
		//yaha hi galti hoti h 
		dfsVisited[src] = false;
		return false;
	}

    
};

int main()
{
    /*
    Graph<int> g;
    int n = 5;
    g.addEdge(0, 1, false);
    g.addEdge(1, 3, false);
    g.addEdge(0, 2, false);
    g.addEdge(2, 4, false);

    g.printAdjacencyList();
    cout << endl;

    unordered_map<int, bool> visited;
    cout << "Printing BFS\n";
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.bfs(i, visited);
        }
    }
*/
/*
4->2, 
0->1, 2, 
1->0, 3, 
3->1, 
2->0, 4, 

Printing BFS
0, 1, 2, 3, 4,
    return 0;

*/    
    // unordered_map<int, bool> visited2;
    // cout << "Printing DFS\n";
    // for (int i = 0; i < n; i++)
    // {
    //     if (!visited2[i])
    //     {
    //         g.dfs(i, visited2);
    //     }
    // }
//  Printing DFS
// 0, 1, 3, 2, 4,

/*    unodiecrect by bfs
    bool ans=false;
    unordered_map<int,bool>visited3;
    
    for(int i=0;i<n ; i++){
        if(!visited3[i]){
            ans=g.checkCyclicUsingBfs(i,visited3);
            if(ans==true){
                break;
            }
        }
    }

    if(ans == true) 
		cout << "Cycle is Present" << endl;
	else
		cout << "Cycle Absent" << endl;


        // Cycle is Present

*/     
    
    /*
    cout<<"checking cyclic by dfs (undirected graph)\n";
    bool ansDfs=false;
    unordered_map<int,bool>visitedDfs;
    
    for(int i=0;i<n ; i++){
        if(!visitedDfs[i]){
            ansDfs=g.checkCyclicUsingBfs(i,visitedDfs);
            if(ansDfs==true){
                break;
            }
        }
    }

    if(ansDfs == true) 
		cout << "Cycle is Present" << endl;
	else
		cout << "Cycle Absent" << endl;

// checking cyclic by dfs (undirected graph)
// Cycle is Present
    */

    Graph<int> g;
	//n -> number of nodes in graph
	int n = 5;
	g.addEdge(0,1,1);
	g.addEdge(1,2,1);
	g.addEdge(2,3,1);
	g.addEdge(3,4,1);
	g.addEdge(4,0,1);

	g.printAdjacencyList();
	cout << endl;

	bool ans = false;
	unordered_map<int, bool> visited;
	unordered_map<int, bool> dfsVisited;
	for(int i=0; i<n; i++) {
		if(!visited[i] ) {
			ans = g.checkCyclicDirectedGraphUsingDfs(i,visited,dfsVisited);
			if(ans == true)
				break;
		}
	}

	if(ans == true) 
		cout << "Cycle is Present" << endl;
	else
		cout << "Cycle Absent" << endl;


    
}
