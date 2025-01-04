import kotlin.math.abs

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

fun main() =
    useIO {
        readln()
        val arr = readln().split(" ").map { it.toInt() }
        var l = 0
        var r = arr.size - 1

        var diff = Int.MAX_VALUE
        var ans = Pair(0, 0)

        while (l < r) {
            val sum = arr[l] + arr[r]
            if (abs(sum) < diff) {
                diff = abs(sum)
                ans = arr[l] to arr[r]
            }
            if (sum < 0) {
                l++
            } else {
                r--
            }
        }

        println("${ans.first} ${ans.second}")
    }
