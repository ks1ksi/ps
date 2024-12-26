val reader = System.`in`.bufferedReader()
val writer = System.out.bufferedWriter()

class DisjointSet(
    private val n: Int,
) {
    private val parent = IntArray(n + 1) { -it }

    fun find(x: Int): Int =
        if (parent[x] < 0) {
            x
        } else {
            parent[x] = find(parent[x])
            parent[x]
        }

    fun union(
        x: Int,
        y: Int,
    ): Boolean {
        var (px, py) = find(x) to find(y)
        if (px == py) return false
        if (parent[px] > parent[py]) px = py.also { py = px }
        parent[px] += parent[py]
        parent[py] = px
        return true
    }
}

fun main() {
    val (v, e) = reader.readLine().split(" ").map { it.toInt() }
    val edges =
        List(e) {
            val (a, b, c) = reader.readLine().split(" ").map { it.toInt() }
            Triple(a, b, c)
        }

    val disjointSet = DisjointSet(v)
    edges
        .sortedBy { it.third }
        .fold(0L) { acc, (a, b, c) ->
            if (disjointSet.union(a, b)) acc + c else acc
        }.let {
            writer.write("$it")
        }

    writer.flush()
    return
}
