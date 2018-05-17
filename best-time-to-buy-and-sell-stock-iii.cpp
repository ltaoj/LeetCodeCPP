class Solution {
// 股票买入卖出最大收益问题，两次交易
public:
    int maxProfit(vector<int> &prices) {
        int buy1 = INT_MIN; int sell1 = 0; int buy2 = INT_MIN; int sell2 = 0;
        
        for (auto price : prices) {
            buy1 = max(buy1, -price);
            sell1 = max(sell1, price + buy1);
            
            buy2 = max(buy2, sell1-price);
            sell2 = max(sell2, price + buy2);
        }
        return sell2;
    }
};
