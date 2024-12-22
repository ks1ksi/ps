val reader = System.`in`.bufferedReader()
val writer = System.out.bufferedWriter()

val dx = intArrayOf(0, 0, 1, -1)
val dy = intArrayOf(1, -1, 0, 0)

fun main() {
    val (n, m) = reader.readLine().split(" ").map { it.toInt() }
    val arr = Array(n) { CharArray(m) { ' ' } }
    var start = Pair(0, 0)

    repeat(n) { i ->
        arr[i] =
            reader
                .readLine()
                .toCharArray()
        if (arr[i].contains('I')) {
            start = Pair(i, arr[i].indexOf('I'))
        }
    }

    val visited = Array(n) { BooleanArray(m) }
    var count = 0
    val queue = ArrayDeque<Pair<Int, Int>>()
    queue.add(start)

    while (queue.isNotEmpty()) {
        val (x, y) = queue.removeFirst()
        if (visited[x][y]) continue
        visited[x][y] = true

        if (arr[x][y] == 'P') {
            count++
        }

        for (i in 0 until 4) {
            val nx = x + dx[i]
            val ny = y + dy[i]
            if (nx in 0 until n && ny in 0 until m && arr[nx][ny] != 'X') {
                queue.add(Pair(nx, ny))
            }
        }
    }

    writer.write("${if (count == 0) "TT" else count}")
    writer.flush()
}
