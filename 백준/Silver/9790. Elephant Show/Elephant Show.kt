fun main () {
    val dx = intArrayOf(1, 0, -1, 0)
    val dy = intArrayOf(0, 1, 0, -1)

    while (true) {
        val (w, h) = readln().trim().split(" ").map { it.toInt() }
        if (w == 0 && h == 0) break

        val map = Array(h) { readln().trim() }
        val visited = Array(h) { BooleanArray(w) }
        val queue = ArrayDeque<Pair<Int, Int>>()

        for (i in 0 until h) {
            for (j in 0 until w) {
                if (map[i][j] == 'A') {
                    queue.add(i to j)
                    visited[i][j] = true
                }
            }
        }

        var ans = 1
        while (queue.isNotEmpty()) {
            val (x, y) = queue.removeFirst()
            for (i in 0 until 4) {
                val nx = x + dx[i]
                val ny = y + dy[i]
                if (nx in 0 until h && ny in 0 until w && !visited[nx][ny] && map[nx][ny] != '#') {
                    visited[nx][ny] = true
                    queue.add(nx to ny)
                    ans++
                }
            }
        }
        println(ans)
    }
}