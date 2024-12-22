val reader = System.`in`.bufferedReader()
val writer = System.out.bufferedWriter()

fun main() {
    val n = reader.readLine().toInt()
    val m = reader.readLine().toInt()
    val s = reader.readLine()

    var i = 0
    var ans = 0
    while (i < m) {
        if (s[i] == 'O') {
            i++
            continue
        }

        var j = i
        while (j + 2 < m && s[j + 1] == 'O' && s[j + 2] == 'I') {
            j += 2
        }

        if (j > i) {
            val k1 = j - i + 1
            val k2 = n * 2 + 1
            if (k1 >= k2) {
                ans += (k1 - k2) / 2 + 1
            }
            i = j + 1
        } else {
            i++
        }
    }

    writer.write("$ans")
    writer.flush()
}
