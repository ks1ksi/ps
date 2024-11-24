fun main() {
    val n = readln().toInt()
    val list = readln().split(" ").map { it.toInt() }
    val (t, p) = readln().split(" ").map { it.toInt() }

    println(
        list.fold(0) { acc, item ->
            acc + (item / t) + if (item > 0 && item % t > 0) 1 else 0
        },
    )
    println("${n / p} ${n % p}")
}
