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
        fun findCommonMaxValue(
            a: List<Int>,
            b: List<Int>,
        ): Int {
            a
                .sortedBy { -it }
                .forEach {
                    if (b.contains(it)) {
                        return it
                    }
                }

            return -1
        }

        val n = readln().toInt()
        var a = readln().split(" ").map { it.toInt() }

        val m = readln().toInt()
        var b = readln().split(" ").map { it.toInt() }

        val ans = mutableListOf<Int>()

        while (true) {
            val commonMaxValue = findCommonMaxValue(a, b)
            if (commonMaxValue == -1) {
                break
            }

            ans.add(commonMaxValue)
            a = a.drop(a.indexOf(commonMaxValue) + 1)
            b = b.drop(b.indexOf(commonMaxValue) + 1)
        }

        println(ans.size)
        println(ans.joinToString(" "))
    }
