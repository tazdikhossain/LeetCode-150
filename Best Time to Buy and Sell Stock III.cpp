class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int firstBuy = INT_MIN, firstSell = 0;
        int secondBuy = INT_MIN, secondSell = 0;

        for (int price : prices) {
            firstBuy = max(firstBuy, -price);              // Buy at lowest price
            firstSell = max(firstSell, firstBuy + price);  // Sell after first buy
            secondBuy = max(secondBuy, firstSell - price); // Buy again with first profit
            secondSell = max(secondSell, secondBuy + price); // Final sell
        }

        return secondSell;
    }
};
