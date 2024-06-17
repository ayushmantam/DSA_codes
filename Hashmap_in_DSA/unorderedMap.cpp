#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
int main(){
    unordered_map<string,int>umap;
    umap["prince"]=44;
    umap["gfg"]=56;
    umap["helloworld"]=90;

    for(auto x:umap){
        cout<<x.first<<" "<<x.second<<endl; 
    }

//itr is a pointer 
    for (auto itr=umap.begin();itr!=umap.end();itr++)
    {
        cout<<itr->first<<" "<<itr->second<<endl;
    }
    

    string key="prince";

    if(umap.find(key)!=umap.end()){
        cout<<"key found"<<endl;
    }
    else{
        cout<<"key not found\n";
    }

// find function gives us itreator
// by iterator we can find value and key
    if(umap.find(key)!=umap.end()){
        auto temp=umap.find(key);
        cout<<"Key is :"<<temp->first<<endl;
        cout<<"value is:"<<temp->second<<endl;
    }


    umap.insert(make_pair("mobile",17000));


    cout<<umap.size()<<endl;

    
    int arr[]={1,1,2,2,2,3,4,5,5,5,5,6,6,7,8,9,9};

    unordered_map<int,int>findFreq;
    for(int i=0;i<17;i++){
        int key=arr[i];
        findFreq[key]++;
    }

    for (auto itr=findFreq.begin();itr!=findFreq.end();itr++)
    {
        cout<<itr->first<<"->"<<itr->second<<endl;
    }
    
    
}