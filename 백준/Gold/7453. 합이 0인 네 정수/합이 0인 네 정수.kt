object IO {
    private val reader = System.`in`.bufferedReader()
    private val writer = System.out.bufferedWriter()

    fun readLine(): String = reader.readLine()

    fun write(value: Any) = writer.write(value.toString())

    fun flush() = writer.flush()
}

fun IntArray.lowerBound(value: Int): Int {
    var low = 0
    var high = this.size
    while (low < high) {
        val mid = low + (high - low) / 2
        if (this[mid] < value) {
            low = mid + 1
        } else {
            high = mid
        }
    }
    return low
}

fun IntArray.upperBound(value: Int): Int {
    var low = 0
    var high = this.size
    while (low < high) {
        val mid = low + (high - low) / 2
        if (this[mid] <= value) {
            low = mid + 1
        } else {
            high = mid
        }
    }
    return low
}

fun main() {
    val n = IO.readLine().toInt()
    val abcd = Array(4) { IntArray(n) }
    for (i in 0 until n) {
        val (a, b, c, d) = IO.readLine().split(" ").map { it.toInt() }
        abcd[0][i] = a
        abcd[1][i] = b
        abcd[2][i] = c
        abcd[3][i] = d
    }

    val abArray = IntArray(n * n)
    val cdArray = IntArray(n * n)

    for (i in 0 until n) {
        for (j in 0 until n) {
            abArray[i * n + j] = abcd[0][i] + abcd[1][j]
            cdArray[i * n + j] = abcd[2][i] + abcd[3][j]
        }
    }

    abArray.sort()
    cdArray.sort()

    var answer = 0L

    for (ab in abArray) {
        val lower = cdArray.lowerBound(-ab)
        val upper = cdArray.upperBound(-ab)
        answer += upper - lower
    }

    IO.write("$answer")
    IO.flush()
}
