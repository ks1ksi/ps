object IO : AutoCloseable {
    private val reader = System.`in`.bufferedReader()
    private val writer = System.out.bufferedWriter()

    fun readln(): String = reader.readLine()

    fun println() {
        writer.newLine()
    }

    fun println(value: Any) {
        writer.write(value.toString())
        writer.newLine()
    }

    override fun close() {
        writer.flush()
        reader.close()
        writer.close()
    }
}

inline fun <R> useIO(block: IO.() -> R): R = IO.use(block)

val dx = intArrayOf(0, 0, 1, -1)
val dy = intArrayOf(1, -1, 0, 0)

const val SHARK = 1e9.toInt()

fun findNext(
    board: Array<IntArray>,
    shark: Pair<Int, Int>,
    size: Int,
): Pair<Int, Int> {
    val n = board.size
    var dist = Int.MAX_VALUE
    var ret: Pair<Int, Int> = Pair(Int.MAX_VALUE, Int.MAX_VALUE)
    val visited = Array(n) { IntArray(n) }
    val queue = ArrayDeque<Pair<Int, Int>>()
    queue.add(shark)

    while (queue.isNotEmpty()) {
        val (y, x) = queue.removeFirst()

        for (i in 0 until 4) {
            val ny = y + dy[i]
            val nx = x + dx[i]

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue
            if (visited[ny][nx] > 0) continue
            if (board[ny][nx] > size) continue

            visited[ny][nx] = visited[y][x] + 1
            queue.add(Pair(ny, nx))

            if (board[ny][nx] < size && board[ny][nx] != 0) {
                if (visited[ny][nx] < dist) {
                    dist = visited[ny][nx]
                    ret = Pair(ny, nx)
                } else if (visited[ny][nx] == dist) {
                    if (ny < ret.first) {
                        ret = Pair(ny, nx)
                    } else if (ny == ret.first && nx < ret.second) {
                        ret = Pair(ny, nx)
                    }
                }
            }
        }
    }

    return ret
}

fun move(
    board: Array<IntArray>,
    shark: Pair<Int, Int>,
    size: Int,
    next: Pair<Int, Int>,
): Int {
    val n = board.size
    val visited = Array(n) { IntArray(n) }
    val queue = ArrayDeque<Pair<Int, Int>>()
    queue.add(shark)

    var ret = 0
    while (queue.isNotEmpty()) {
        val (y, x) = queue.removeFirst()

        for (i in 0 until 4) {
            val ny = y + dy[i]
            val nx = x + dx[i]

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue
            if (visited[ny][nx] > 0) continue
            if (board[ny][nx] > size) continue

            visited[ny][nx] = visited[y][x] + 1
            queue.add(Pair(ny, nx))

            if (ny == next.first && nx == next.second) {
                ret = visited[ny][nx]
                board[shark.first][shark.second] = 0
                board[ny][nx] = SHARK
            }
        }
    }

    return ret
}

fun main() =
    useIO {
        val n = readln().toInt()
        val board = Array(n) { readln().split(" ").map { it.toInt() }.toIntArray() }

        var size = 2
        var count = 0
        var time = 0

        var shark =
            board
                .mapIndexed { y, row ->
                    row.mapIndexed { x, value ->
                        if (value == 9) {
                            Pair(y, x)
                        } else {
                            null
                        }
                    }
                }.flatten()
                .filterNotNull()
                .first()
        board[shark.first][shark.second] = SHARK
        while (true) {
            val next = findNext(board, shark, size)
            if (next == Int.MAX_VALUE to Int.MAX_VALUE) {
                break
            }

            val dist = move(board, shark, size, next)
            time += dist
            count += 1
            if (count == size) {
                size += 1
                count = 0
            }
            shark = next
        }

        println(time)
    }
