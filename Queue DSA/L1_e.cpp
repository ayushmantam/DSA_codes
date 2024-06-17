#include <iostream>
#include <deque>
using namespace std;

int main()
{
    // creation
    deque<int> dq;

    dq.push_front(5);
    dq.push_front(10);
    dq.push_back(20);
    dq.push_back(20);

    // dq.print();
    cout << "Size : " << dq.size() << endl;

    dq.pop_front();
    cout << "Size : " << dq.size() << endl;
    dq.pop_back();
    cout << "Size : " << dq.size() << endl;

    cout << "front: " << dq.front() << endl;
    cout << "back: " << dq.back() << endl;

    cout << "dq.empty() " << dq.empty() << endl;
}