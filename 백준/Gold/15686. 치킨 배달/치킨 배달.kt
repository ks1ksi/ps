import kotlin.math.abs

fun IntArray.nextPermutation(): Boolean {
    val n = this.size
    var i = n - 2
    while (i >= 0 && this[i] >= this[i + 1]) {
        i--
    }
    if (i < 0) {
        return false
    }
    var j = n - 1
    while (this[j] <= this[i]) {
        j--
    }
    swap(i, j)
    reverse(i + 1, n - 1)
    return true
}

fun IntArray.swap(
    i: Int,
    j: Int,
) {
    val temp = this[i]
    this[i] = this[j]
    this[j] = temp
}

fun IntArray.reverse(
    start: Int,
    end: Int,
) {
    var i = start
    var j = end
    while (i < j) {
        swap(i, j)
        i++
        j--
    }
}

fun main() {
    val reader = System.`in`.bufferedReader()
    val writer = System.out.bufferedWriter()

    val (n, m) = reader.readLine().split(" ").map { it.toInt() }
    val arr = Array(n) { IntArray(n) }

    repeat(n) { i ->
        arr[i] =
            reader
                .readLine()
                .split(" ")
                .map { it.toInt() }
                .toIntArray()
    }

    val chickenList: List<Pair<Int, Int>> =
        arr.flatMapIndexed { rowIndex, row ->
            row
                .mapIndexed { colIndex, cell ->
                    if (cell == 2) Pair(rowIndex, colIndex) else null
                }.filterNotNull()
        }

    val combination = IntArray(chickenList.size) { 0 }
    for (i in 0 until m) {
        combination[chickenList.size - i - 1] = 1
    }

    var answer = Int.MAX_VALUE

    do {
        val selectedChickenList =
            chickenList.filterIndexed { index, _ -> combination[index] == 1 }
        var sum = 0
        for (i in 0 until n) {
            for (j in 0 until n) {
                if (arr[i][j] == 1) {
                    var min = Int.MAX_VALUE
                    for (chicken in selectedChickenList) {
                        val (r, c) = chicken
                        min = minOf(min, abs(i - r) + abs(j - c))
                    }
                    sum += min
                }
            }
        }
        answer = minOf(answer, sum)
    } while (combination.nextPermutation())

    writer.write("$answer\n")
    writer.flush()
}
