object Solution {
  def distance(x: Array[Int], y: Array[Int]): Double = {
    val a = x(0) - y(0)
    val b = x(1) - y(1)
    scala.math.sqrt(a * a + b * b)
  }

  def largestTriangleArea(points: Array[Array[Int]]): Double = {
    val n = points.length

    (2 until n).map(i => {
      (1 until i).map(j => {
        (0 until j).map(k => {

          val a = distance(points(i), points(j))
          val b = distance(points(i), points(k))
          val c = distance(points(j), points(k))
          val p = (a + b + c) / 2.0

          scala.math.sqrt(p * (p - a) * (p - b) * (p - c))
        }).max
      }).max
    }).max
  }
}
