class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>umap;
        for(auto x:nums){
          umap[x]++;
        }

        //we can modify sort function by lamda function
        sort(nums.begin(),sums.end(),[&](int a,int b
        ){ return umap[a]!=umap[b] ?  umap[a]<umap[b]  :  a > b  ;} );
    }
};