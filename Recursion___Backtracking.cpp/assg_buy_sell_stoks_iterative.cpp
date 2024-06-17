class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=prices[0];
        int maxProfit=INT_MIN;
        for(int i=0; i< prices.size(); i++){

          if(minprice>prices[i]){
            minprice=prices[i];
          }

          int currProfit=prices[i]-minprice;
          
          if(currProfit>maxProfit){
            maxProfit=currProfit;
          }

        }
        return maxProfit;
    }
};