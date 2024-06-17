#include <iostream>
#include <string>
#include <vector>
using namespace std;
// yha humne output ko by reference nhi liya
// to har baar recursive call ke liye nya banega
void printSubsequences(string str, string output, int i)
{
    // base case
    if (i >= str.length())
    {
        cout << output << endl;
        return;
    }

    // exlude= kuch ni karna+
    printSubsequences(str, output, i + 1);

    // include
    output.push_back(str[i]);
    // output=output+str[i];

    printSubsequences(str, output, i + 1);
}

// leetcode issubsequme google
bool isSubsequence(string s, string t)
{
    int sPtr = 0, tPtr = 0;

    while (sPtr < s.length() && tPtr < t.length())
    {
        if (s[sPtr] == t[tPtr])
        {
            sPtr++; // Move pointer in s
        }
        tPtr++; // Always move pointer in t
    }

    // If sPtr reaches the end, all characters in s are found in t in order
    return sPtr == s.length();
}

void printSubsequences2(string str, string output, int i)
{
    // base case
    if (i >= str.length())
    {
        cout << output << endl;
        return;
    }

    // include
    output.push_back(str[i]);
    // output=output+str[i];
    printSubsequences2(str, output, i + 1);
    output.pop_back();

    // exlude= kuch ni karna
    printSubsequences2(str, output, i + 1);
}

void printSubseq(vector<int> &a, vector<int> grp, int index)
{
    if (index >= a.size())
    {
        cout << "{ ";
        for (int i = 0; i < grp.size(); i++)
        {
            cout << grp[i] << " , ";
        }
        cout << "}" << endl;
        return;
    }

    // include
    grp.push_back(a[index]);
    printSubseq(a, grp, index + 1);
    // exclude

    grp.pop_back();
    printSubseq(a, grp, index + 1);
}

// void storeSubSeq(vector<int>&a,vector<vector<int>>&ans,vector<int>&curr,int index){
//     if(index==a.size()){
//         ans.push_back(curr);
//     }


// }
int main()
{
    string str = "abcd";
    string output = "";

    // int i = 0;
    // printSubsequences(str, output, i);
    // printSubsequences2(str,output,i);

    // vector<int> a = {1, 2, 3};
    // vector<int> grp;
    // int index = 0;
    // printSubseq(a, grp, index);

    return 0;
}

// method 2 bitmasking later..