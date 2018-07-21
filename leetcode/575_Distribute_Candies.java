class Solution {
    public int distributeCandies(int[] candies) {
        HashMap<Integer, Boolean> map = new HashMap<>();
        for (int x : candies) {
            if (!map.containsKey(x)) {
                map.put(x, true);
            }
        }
        final int kind = map.size();
        final int half = candies.length >> 1;
        return Math.min(kind, half);
    }
}
