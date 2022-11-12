class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price=prices[0],max_profit=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>prices[i-1])
                max_profit+=prices[i]-prices[i-1];
        }
        return max_profit;
    }
};
