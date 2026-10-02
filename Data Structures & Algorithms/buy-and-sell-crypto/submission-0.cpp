class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int i=0, j= 1;
        int profit=0;
        while(j<n)
        {
            if(prices[i]<prices[j])
            {
                profit = max(profit, prices[j]-prices[i]);
            } else{
                i=j; //found a new min price
            }
            j++;
        }
        return profit;
    }
};
