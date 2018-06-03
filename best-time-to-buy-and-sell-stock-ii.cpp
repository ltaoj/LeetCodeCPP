class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2)
            return 0;
        // 波谷购买，波峰卖出
        int profit = 0;
        for (int i = 1;i < prices.size();i++) {
            if (prices[i] > prices[i-1]) {
                profit+=(prices[i]-prices[i-1]);
            }
        }
        return profit;
    }
};
