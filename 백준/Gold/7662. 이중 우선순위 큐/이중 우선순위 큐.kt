import java.util.*

class TreeMultiSet<T : Comparable<T>> {
    private val map = TreeMap<T, Int>()
    private var size = 0

    fun add(
        element: T,
        count: Int = 1,
    ) {
        require(count > 0) { "Count must be positive" }
        val newCount = (map[element] ?: 0) + count
        map[element] = newCount
        size += count
    }

    fun remove(
        element: T,
        count: Int = 1,
    ): Boolean {
        require(count > 0) { "Count must be positive" }
        val currentCount = map[element] ?: return false

        when {
            currentCount <= count -> {
                map.remove(element)
                size -= currentCount
            }

            else -> {
                map[element] = currentCount - count
                size -= count
            }
        }
        return true
    }

    fun first(): T = map.firstKey()

    fun last(): T = map.lastKey()

    fun isEmpty(): Boolean = map.isEmpty()
}

fun main() {
    val reader = System.`in`.bufferedReader()

    val t = reader.readLine().toInt()
    repeat(t) {
        val query = reader.readLine().toInt()
        val set = TreeMultiSet<Int>()
        repeat(query) {
            val line = reader.readLine().split(" ")
            when (line.first()) {
                "I" -> set.add(line.last().toInt())
                "D" -> {
                    if (set.isEmpty()) return@repeat
                    when (line.last()) {
                        "1" -> set.remove(set.last())
                        "-1" -> set.remove(set.first())
                    }
                }
            }
        }
        if (set.isEmpty()) {
            println("EMPTY")
        } else {
            println("${set.last()} ${set.first()}")
        }
    }
}
