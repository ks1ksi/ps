class DisjointSet(
    private val n: Int,
) {
    private val parent = IntArray(n + 1) { -it }

    fun find(x: Int): Int {
        if (parent[x] < 0) return x
        parent[x] = find(parent[x])
        return parent[x]
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
    val reader = System.`in`.bufferedReader()
    val writer = System.out.bufferedWriter()

    val (n, m) = reader.readLine().split(" ").map { it.toInt() }

    val (liarCount, liars) =
        reader
            .readLine()
            .split(" ")
            .map { it.toInt() }
            .let { it[0] to it.drop(1) }

    if (liarCount == 0) {
        writer.write("$m\n")
        writer.flush()
        return
    }

    val parties =
        List(m) {
            reader
                .readLine()
                .split(" ")
                .map { it.toInt() }
                .drop(1)
        }

    val ds = DisjointSet(n)

    for (party in parties) {
        for (i in 0 until party.size - 1) {
            ds.union(party[i], party[i + 1])
        }
    }

    val liarsRootSet = liars.map { ds.find(it) }.toHashSet()
    val answer = m - parties.count { party -> party.any { liarsRootSet.contains(ds.find(it)) } }

    writer.write("$answer")
    writer.flush()
    return
}
