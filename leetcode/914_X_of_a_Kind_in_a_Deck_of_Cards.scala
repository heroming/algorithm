object Solution {

  def gcd(a: Int, b: Int): Int = {
    if (b == 0) {
      a
    } else {
      gcd(b, a % b)
    }
  }

  def hasGroupsSizeX(deck: Array[Int]): Boolean = {
    val s = deck.map((_, 1)).groupBy(_._1).map(_._2.length).toArray

    if (s.length == 1) {
      s.head > 1
    } else {
      s.fold(s.head) { (x, k) => gcd(x, k) } > 1
    }
  }
}
