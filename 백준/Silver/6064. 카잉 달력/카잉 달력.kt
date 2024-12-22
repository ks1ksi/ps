fun main() {
    val reader = System.`in`.bufferedReader()
    val writer = System.out.bufferedWriter()

    val t = reader.readLine().toInt()

    repeat(t) {
        val (m, n, x, y) = reader.readLine().split(" ").map { it.toInt() }

        var k = -1

        for (i in 0 until n) {
            if ((i * m + (x - 1)) % n == (y - 1)) {
                k = i * m + x
                break
            }
        }

        writer.write("$k\n")
    }

    writer.flush()
}
