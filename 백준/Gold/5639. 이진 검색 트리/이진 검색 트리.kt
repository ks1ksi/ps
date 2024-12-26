val reader = System.`in`.bufferedReader()
val writer = System.out.bufferedWriter()

fun convert(subTree: List<Int>): List<Int> {
    if (subTree.isEmpty()) return emptyList()
    if (subTree.size == 1) return subTree

    val root = subTree.first()
    val (left, right) = subTree.drop(1).partition { it < root }

    return convert(left) + convert(right) + root
}

fun main() {
    val preOrder =
        generateSequence {
            val line = reader.readLine()
            if (line == null || line.isEmpty()) null else line
        }.toList().map { it.toInt() }

    val postOrder = convert(preOrder)
    postOrder.forEach { writer.write("$it\n") }

    writer.flush()
    return
}
