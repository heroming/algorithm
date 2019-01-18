object Solution {

  def reverseOnlyLetters(s: String): String = {
    val rs = s.filter(_.isLetter).reverse
    var k = -1
    s.map(c => {
      if (c.isLetter) {
        k += 1
        rs.charAt(k)
      } else {
        c
      }
    }).toString
  }
}
