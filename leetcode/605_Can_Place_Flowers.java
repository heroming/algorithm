class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int count = 0;
        for (int i = 0; i < flowerbed.length; ++i) {
            if (flowerbed[i] == 0
                    && (i == 0 || flowerbed[i - 1] == 0)
                    && (i + 1 == flowerbed.length || flowerbed[i + 1] == 0)) {
                ++count;
                flowerbed[i] = 1;
            }
        }
        return n <= count;
    }
}
