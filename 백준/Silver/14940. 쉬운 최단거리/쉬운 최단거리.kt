val dx = intArrayOf(0, 0, 1, -1)
val dy = intArrayOf(1, -1, 0, 0)

fun main() {
    val reader = System.`in`.bufferedReader()
    val writer = System.out.bufferedWriter()

    val (n, m) = reader.readLine().split(" ").map { it.toInt() }
    val arr = Array(n) { IntArray(m) }
    var start = Pair(0, 0)
    for (i in 0 until n) {
        arr[i] =
            reader
                .readLine()
                .split(" ")
                .map { it.toInt() }
                .toIntArray()
        if (arr[i].contains(2)) {
            start = Pair(i, arr[i].indexOf(2))
        }
    }

    val ans = Array(n) { IntArray(m) }
    val q = ArrayDeque<Pair<Int, Int>>()
    q.add(start)

    while (q.isNotEmpty()) {
        val (x, y) = q.removeFirst()
        for (i in 0 until 4) {
            val nx = x + dx[i]
            val ny = y + dy[i]
            if (nx in 0 until n &&
                ny in 0 until m &&
                ans[nx][ny] == 0 &&
                arr[nx][ny] == 1
            ) {
                ans[nx][ny] = ans[x][y] + 1
                q.add(Pair(nx, ny))
            }
        }
    }

    for (i in 0 until n) {
        for (j in 0 until m) {
            if (arr[i][j] == 1 && ans[i][j] == 0) {
                ans[i][j] = -1
            }
        }
    }

    for (i in 0 until n) {
        ans[i]
            .joinToString(" ")
            .let { writer.write("$it\n") }
    }
    writer.flush()
}
