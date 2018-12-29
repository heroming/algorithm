class Solution {
    public int maxProfit(int[] prices, int fee) {
        if (prices == null || prices.length == 0) {
            return 0;
        }
        int non = 0, hold = -prices[0] - fee;
        for (int i = 1; i < prices.length; ++i) {
            int currentNon = Math.max(non, hold + prices[i]);
            int currentHold = Math.max(hold, non - prices[i] - fee);
            non = currentNon;
            hold = currentHold;
        }
        return non;
    }
}
