fun main() {
    val (n, t) = readln().trim().split(" ").map { it.toInt() }
    val list = mutableListOf<Pair<Int, Int>>()

    for (i in 1..n) {
        val (a, b) = readln().trim().split(" ").map { it.toInt() }
        list.add(a to b)
    }

    val min = list.sumOf { it.first }
    if (min > t) {
        println(-1)
        return
    }

    var (low, high) = 1 to 1e9.toInt() + 1
    while (low < high) {
        val s = (low + high) / 2
        if (list.any { it.first > s }) {
            low = s + 1
            continue
        }

        val max = list.sumOf { it.second.coerceAtMost(s) }
        if (max < t) {
            low = s + 1
        } else {
            high = s
        }
    }
    if (high == 1e9.toInt() + 1) {
        println(-1)
    } else {
        println(high)
    }
}