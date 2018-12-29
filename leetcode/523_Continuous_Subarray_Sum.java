class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        if (nums.length <= 1) return false;
        if (k == 1) return true;
        if (k == 0) {
            for (int i = 0; i + 1 < nums.length; ++i) {
                if (nums[i] == 0 && nums[i + 1] == 0) {
                    return true;
                }
            }
            return false;
        }

        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        int s = 0;
        for (int i = 0; i < nums.length; ++i) {
            s = (s + nums[i]) % k;
            if (map.containsKey(s)) {
                if (i - map.get(s) > 1) {
                    return true;
                }
            } else {
                map.put(s, i);
            }
        }
        return false;
    }
}
