object IO : AutoCloseable {
    private val reader = System.`in`.bufferedReader()
    private val writer = System.out.bufferedWriter()

    fun readln() = reader.readLine()

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
        val n = readln().toInt()
        val s =
            buildString {
                for (i in 1..n) {
                    append("$i ")
                    if (i % 6 == 0) append("Go! ")
                }
                if (n % 6 != 0) append("Go!")
            }
        println(s)
    }
