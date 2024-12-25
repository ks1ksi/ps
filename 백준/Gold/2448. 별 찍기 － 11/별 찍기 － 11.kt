val baseStar =
    """
      *  
     * * 
    *****
    """.trimIndent()

fun makeStar(x: Int): String {
    if (x == 1) return baseStar

    val prev = makeStar(x / 2)

    val top =
        prev
            .split("\n")
            .joinToString("\n") {
                "${" ".repeat(it.length / 2 + 1)}$it${" ".repeat(it.length / 2 + 1)}"
            }

    val bottom =
        prev
            .split("\n")
            .joinToString("\n") {
                "$it $it"
            }

    return "$top\n$bottom"
}

fun main() {
    val reader = System.`in`.bufferedReader()
    val writer = System.out.bufferedWriter()

    val n = reader.readLine().toInt()
    val star = makeStar(n / 3)

    writer.write(star)
    writer.flush()
    return
}
