import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

class FastSet {
    private var bit: Int = 0

    fun add(num: Int) {
        bit = bit or (1 shl num)
    }

    fun remove(num: Int) {
        bit = bit and (1 shl num).inv()
    }

    fun contains(num: Int): Boolean = bit and (1 shl num) != 0

    fun toggle(num: Int) {
        bit = bit xor (1 shl num)
    }

    fun all() {
        bit = (1 shl 21) - 1
    }

    fun empty() {
        bit = 0
    }
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val set = FastSet()

    val n = br.readLine().toInt()
    repeat(n) {
        val operation = br.readLine().split(" ")
        when (operation[0]) {
            "add" -> set.add(operation[1].toInt())
            "remove" -> set.remove(operation[1].toInt())
            "check" -> bw.write(if (set.contains(operation[1].toInt())) "1\n" else "0\n")
            "toggle" -> set.toggle(operation[1].toInt())
            "all" -> set.all()
            "empty" -> set.empty()
        }
    }

    bw.flush()
    bw.close()
    br.close()
}
