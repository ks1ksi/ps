fun main() {
    val n = readln().toInt()
    val q = ArrayDeque<Int>()
    repeat(n) {
        val operation = readln().split(" ")
        when (operation[0]) {
            "push" -> q.addLast(operation[1].toInt())
            "pop" -> println(q.removeFirstOrNull() ?: -1)
            "size" -> println(q.size)
            "empty" -> println(if (q.isEmpty()) 1 else 0)
            "front" -> println(q.firstOrNull() ?: -1)
            "back" -> println(q.lastOrNull() ?: -1)
        }
    }
}
