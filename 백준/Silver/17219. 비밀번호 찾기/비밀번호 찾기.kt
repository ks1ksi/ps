val reader = System.`in`.bufferedReader()
val writer = System.out.bufferedWriter()

fun main() {
    val (n, m) = reader.readLine().split(" ").map { it.toInt() }
    val map = mutableMapOf<String, String>()

    repeat(n) {
        val (a, b) = reader.readLine().split(" ")
        map[a] = b
        map[b] = a
    }

    repeat(m) {
        val a = reader.readLine()
        writer.write("${map[a]}\n")
    }

    writer.flush()
}
