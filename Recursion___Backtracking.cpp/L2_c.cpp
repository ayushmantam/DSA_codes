
#include <iostream>
#include <vector>
using namespace std;

int checkKey(string str, int i, int &n, char key)
{
    // base case
    if (i >= n)
    {
        // key not found
        return -1;
    }

    // 1 case solve krdo
    if (str[i] == key)
    {
        return i;
    }

    // baaki recursion sambhal lega
    return checkKey(str, i + 1, n, key);
}
void checkKey2(string str, int i, int &n, char key)
{
    // base case
    if (i >= n)
    {
        // key not found
        return;
    }

    // 1 case solve krdo
    if (str[i] == key)
    {
        cout << "answer is:" << i << endl;
    }

    // baaki recursion sambhal lega
    return checkKey2(str, i + 1, n, key);
}

void checkKey3(string str, int i, int &n, char key, vector<int> &ans)
{
    // base case
    if (i >= n)
    {
        // key not found
        return;
    }

    // 1 case solve krdo
    if (str[i] == key)
    {
        ans.push_back(i);
    }

    // baaki recursion sambhal lega
    return checkKey3(str, i + 1, n, key, ans);
}

void checkKey4(string str, int i, int &n, char key, int &count)
{
    // base case
    if (i >= n)
    {
        // key not found
        return;
    }

    // 1 case solve krdo
    if (str[i] == key)
    {
        count++;
    }

    // baaki recursion sambhal lega
    return checkKey4(str, i + 1, n, key, count);
}

// Note =pass by reference se space comlexicity par fark padta hai
// SPACE COMPLEXICITY KUM HO JATI HAI PBR SE
int main()
{
    string str = "lovebabbar";
    int n = str.length();
    char key = 'b';
    int i = 0;
    //  int ans=checkKey(str,i,n,key);

    //  cout<<"answer is: "<<ans<<endl;
    // checkKey2(str,i,n,key);

    vector<int> ans;

    checkKey3(str, i, n, key, ans);

    cout << "ans printing:\n"
         << endl;
    for (auto val : ans)
    {
        cout << val << " ";
    }

    // int count=0;
    // checkKey4(str,i,n,key,count);
    // cout<<count<<endl;

    //  return 0;
}

// outcomes

// arry traverse reverse
// by reference
// void type type function
// non void type function
// by referense vector me store karna
