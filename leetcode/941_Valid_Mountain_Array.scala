object Solution {

  def validMountainArray(v: Array[Int]): Boolean = {

    if (v.length < 3) return false

    (1 until v.length - 1).foreach(k => {
      if (v(k - 1) > v(k)) {
        (k + 1 until v.length).foreach(i => {
          if (v(i - 1) <= v(i)) return false
        })
      }
    })
    v(0) < v(1) && v(v.length - 2) > v(v.length - 1)
  }
}
