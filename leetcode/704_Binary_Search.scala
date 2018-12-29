object Solution {
    def search(nums: Array[Int], target: Int): Int = {
    var l = 0
    var r = nums.length - 1
    while (l <= r) {
      val m = (l + r) >> 1
      if (nums(m) == target) {
        return m
      }
      if (nums(m) < target) {
        l = m + 1
      } else {
        r = m - 1
      }
    }
    -1
  }
}
