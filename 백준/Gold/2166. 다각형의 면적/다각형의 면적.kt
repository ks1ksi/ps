import kotlin.math.abs

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

fun main() =
    useIO {
        val n = readln().toInt()
        val points =
            List(n) {
                val (x, y) = readln().split(" ").map { it.toLong() }
                x to y
            }

        val area =
            points
                .plus(points.first())
                .zipWithNext()
                .fold(0.0) { acc, (p1, p2) ->
                    acc + (p1.first + p2.first) * (p1.second - p2.second)
                }.let { abs(it) / 2 }

        println("%.1f".format(area))
    }
