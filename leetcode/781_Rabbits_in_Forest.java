class Solution {
    public int numRabbits(int[] answers) {
        if (answers == null || answers.length == 0) {
            return 0;
        }
        Map<Integer, Integer> map = new HashMap<>();
        for (int x : answers) {
            if (map.containsKey(x)) {
                map.put(x, map.get(x) + 1);
            } else {
                map.put(x, 1);
            }
        }
        int ans = 0;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int group = (entry.getValue() + entry.getKey()) / (entry.getKey() + 1);
            ans += group * (entry.getKey() + 1);
        }
        return ans;
    }
}
