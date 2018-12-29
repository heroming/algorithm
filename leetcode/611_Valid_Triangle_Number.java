class Solution {
    public int triangleNumber(int[] nums) {
        Arrays.sort(nums);
        int ans = 0;
        for (int i = 0; i < nums.length; ++i) {
            for (int j = i + 1; j < nums.length; ++j) {
                ans += find(nums, j + 1, nums.length - 1, nums[i] + nums[j]);
            }
        }
        return ans;
    }

    private int find(int[] v, int s, int e, int w) {
        int l = s, r = e;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (v[m] < w) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return r - s + 1;
    }
}
