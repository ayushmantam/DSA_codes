#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Min-heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(4);
    pq.push(8);

    cout << "top element: " << pq.top() << endl;
    pq.pop();
    // cout << "Size:" << pq.size() << endl;
    cout << "top element: " << pq.top() << endl;
    pq.pop();
    cout << "top element: " << pq.top() << endl;
    pq.pop();
    cout << "top element: " << pq.top() << endl;
    pq.pop();
    cout << "top element: " << pq.top() << endl;
    pq.pop();
    cout << "Size:" << pq.size() << endl;
    if (pq.empty())
    {
        cout << "Min Heap is empty" << endl;
    }
    else
    {
        cout << "Min heap is not empty" << endl;
    }
    return 0;
}