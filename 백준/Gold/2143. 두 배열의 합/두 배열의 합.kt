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
        val t = readln().toLong()
        val n = readln().toLong()
        val nList = readln().split(" ").map { it.toLong() }
        val m = readln().toLong()
        val mList = readln().split(" ").map { it.toLong() }

        val nPrefixSum = nList.scan(0L) { acc, number -> acc + number }
        val mPrefixSum = mList.scan(0L) { acc, number -> acc + number }

        val nMap = mutableMapOf<Long, Long>()
        for (i in nPrefixSum.indices) {
            for (j in 0 until i) {
                val x = nMap.getOrDefault(nPrefixSum[i] - nPrefixSum[j], 0)
                nMap[nPrefixSum[i] - nPrefixSum[j]] = x + 1
            }
        }

        val mMap = mutableMapOf<Long, Long>()
        for (i in mPrefixSum.indices) {
            for (j in 0 until i) {
                val x = mMap.getOrDefault(mPrefixSum[i] - mPrefixSum[j], 0)
                mMap[mPrefixSum[i] - mPrefixSum[j]] = x + 1
            }
        }

        val count = nMap.entries.sumOf { (key, value) -> value * mMap.getOrDefault(t - key, 0) }
        println(count)
    }
