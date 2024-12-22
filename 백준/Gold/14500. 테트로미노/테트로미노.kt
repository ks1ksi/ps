val tetroArray =
    arrayOf(
        arrayOf(Pair(0, 0), Pair(0, 1), Pair(0, 2), Pair(0, 3)),
        arrayOf(Pair(0, 0), Pair(1, 0), Pair(2, 0), Pair(3, 0)),
        arrayOf(Pair(0, 0), Pair(0, 1), Pair(1, 0), Pair(1, 1)),
        arrayOf(Pair(0, 0), Pair(0, 1), Pair(1, 1), Pair(1, 2)),
        arrayOf(Pair(0, 0), Pair(1, 0), Pair(1, -1), Pair(2, -1)),
        arrayOf(Pair(0, 0), Pair(0, 1), Pair(1, -1), Pair(1, 0)),
        arrayOf(Pair(0, 0), Pair(1, 0), Pair(1, 1), Pair(2, 1)),
        arrayOf(Pair(0, 0), Pair(1, 0), Pair(2, 0), Pair(2, 1)),
        arrayOf(Pair(0, 0), Pair(0, 1), Pair(0, 2), Pair(1, 0)),
        arrayOf(Pair(0, 0), Pair(0, 1), Pair(1, 1), Pair(2, 1)),
        arrayOf(Pair(0, 2), Pair(1, 0), Pair(1, 1), Pair(1, 2)),
        arrayOf(Pair(0, 0), Pair(0, 1), Pair(1, 0), Pair(2, 0)),
        arrayOf(Pair(0, 0), Pair(1, 0), Pair(1, 1), Pair(1, 2)),
        arrayOf(Pair(0, 1), Pair(1, 1), Pair(2, 0), Pair(2, 1)),
        arrayOf(Pair(0, 0), Pair(0, 1), Pair(0, 2), Pair(1, 2)),
        arrayOf(Pair(0, 0), Pair(0, 1), Pair(0, 2), Pair(1, 1)),
        arrayOf(Pair(0, 0), Pair(1, 0), Pair(1, 1), Pair(2, 0)),
        arrayOf(Pair(0, 1), Pair(1, 0), Pair(1, 1), Pair(1, 2)),
        arrayOf(Pair(0, 1), Pair(1, 0), Pair(1, 1), Pair(2, 1)),
    )

fun main() {
    val reader = System.`in`.bufferedReader()
    val writer = System.out.bufferedWriter()

    val (n, m) = reader.readLine().split(" ").map { it.toInt() }
    val arr =
        Array(n) {
            reader
                .readLine()
                .split(" ")
                .map { it.toInt() }
                .toIntArray()
        }

    var ans = 0
    for (i in 0 until n) {
        for (j in 0 until m) {
            for (tetro in tetroArray) {
                var sum = 0
                for (p in tetro) {
                    val (dx, dy) = p
                    val nx = i + dx
                    val ny = j + dy
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                        sum = 0
                        break
                    }
                    sum += arr[nx][ny]
                }
                ans = maxOf(ans, sum)
            }
        }
    }

    writer.write("$ans")
    writer.flush()
}
