class Solution {
    public int triangleNumber(int[] nums) {
        Arrays.sort(nums);
        int ans = 0;
        for (int i = 0; i + 2 < nums.length; ++i) {
            if (nums[i] == 0) {
                continue;
            }
            int k = i + 2;
            for (int j = i + 1; j + 1 < nums.length; ++j) {
                while (k < nums.length && nums[k] < nums[i] + nums[j]) {
                    ++k;
                }
                ans += k - j - 1;
            }
        }
        return ans;
    }
}
