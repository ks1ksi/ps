val reader = System.`in`.bufferedReader()
val writer = System.out.bufferedWriter()

fun main() {
    val n = reader.readLine().toInt()
    val arr = IntArray(n + 1) { Int.MAX_VALUE }
    arr[0] = 0
    arr[1] = 1

    for (i in 2..n) {
        for (j in 1..i) {
            if (j * j > i) break
            arr[i] = minOf(arr[i], arr[i - j * j] + 1)
        }
    }

    writer.write("${arr[n]}")
    writer.flush()
}
