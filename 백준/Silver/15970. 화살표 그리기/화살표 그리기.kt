fun main() {
    val n = readln().toInt()
    val list = mutableListOf<Pair<Int, Int>>()
    for (i in 1..n) {
        val (a, b) = readln().split(" ").map { it.toInt() }
        list.add(a to b)
    }

    list.sortBy { it.first }
    var ans = 0

    for (i in 0 until n) {
        var l = 1e9.toInt()
        var r = 1e9.toInt()
        for (j in i - 1 downTo 0) {
            if (list[j].second == list[i].second) {
                l = list[i].first - list[j].first
                break
            }
        }
        for (j in i + 1 until n) {
            if (list[j].second == list[i].second) {
                r = list[j].first - list[i].first
                break
            }
        }
        ans += minOf(l, r)
    }
    println(ans)
}