class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int buy = INT_MIN;int sell = 0;
        for (int i = 0;i < prices.size();i++) {
            buy = max(buy, -prices[i]);
            sell = max(sell, prices[i]+buy);
        }
        return sell;
    }
};
