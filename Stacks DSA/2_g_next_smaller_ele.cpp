/*
vector<int> nextSmallerElement(vector<int>&arr, int n){
    stack<int>s;
    s.push(-1);  //starting me -1 ko daala
    vector<int> ans[n];
    for (int i = n; i >=0; i--)
    {
        int curr=arr[i];
        while (s.top()>=curr)
        {
            s.pop();
        }
        //ans is stack ka top
        ans[i]=s.top();
        s.push(curr);
    }
    return ans;
    
}
*/