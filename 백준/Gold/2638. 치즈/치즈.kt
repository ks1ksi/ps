object IO : AutoCloseable {
    private val reader = System.`in`.bufferedReader()
    private val writer = System.out.bufferedWriter()

    fun readln() = reader.readLine()

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

fun markBoard(
    board: Array<IntArray>,
    r: Int,
    c: Int,
) {
    val queue = ArrayDeque<Pair<Int, Int>>()
    queue.add(0 to 0)

    while (queue.isNotEmpty()) {
        val (x, y) = queue.removeFirst()
        for (i in 0 until 4) {
            val nx = x + dx[i]
            val ny = y + dy[i]
            if (nx in 0 until r && ny in 0 until c && board[nx][ny] == 0) {
                queue.add(nx to ny)
                board[nx][ny] = 2
            }
        }
    }
}

fun melt(
    board: Array<IntArray>,
    r: Int,
    c: Int,
): Array<IntArray> {
    val newBoard = Array(r) { IntArray(c) { 0 } }
    for (i in 1 until r - 1) {
        for (j in 1 until c - 1) {
            val x =
                if (board[i][j] == 1) {
                    var count = 0
                    for (k in 0 until 4) {
                        val nx = i + dx[k]
                        val ny = j + dy[k]
                        if (board[nx][ny] == 2) {
                            count++
                        }
                    }
                    if (count >= 2) {
                        0
                    } else {
                        1
                    }
                } else {
                    0
                }
            newBoard[i][j] = x
        }
    }
    return newBoard
}

fun count(
    board: Array<IntArray>,
    r: Int,
    c: Int,
): Int {
    var count = 0
    for (i in 1 until r - 1) {
        for (j in 1 until c - 1) {
            if (board[i][j] == 1) {
                count++
            }
        }
    }
    return count
}

fun main() =
    useIO {
        val (n, m) = readln().split(" ").map { it.toInt() }
        var board = Array(n + 2) { IntArray(m + 2) { 0 } }
        // 0, n + 1, m + 1

        repeat(n) { i ->
            val row = readln().split(" ").map { it.toInt() }
            repeat(m) { j ->
                board[i + 1][j + 1] = row[j]
            }
        }

        var year = 0
        while (count(board, n + 2, m + 2) != 0) {
            markBoard(board, n + 2, m + 2)
            board = melt(board, n + 2, m + 2)
            year++
        }
        println(year)
    }
