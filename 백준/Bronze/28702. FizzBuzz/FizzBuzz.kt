fun main() {
    val a = readln()
    val b = readln()
    val c = readln()

    val fz = listOf("Fizz", "Buzz", "FizzBuzz")

    if (!fz.contains(a)) {
        println(fizzBuzz(a.toInt() + 3))
    } else if (!fz.contains(b)) {
        println(fizzBuzz(b.toInt() + 2))
    } else if (!fz.contains(c)) {
        println(fizzBuzz(c.toInt() + 1))
    } else {
        println("asdf")
    }
}

fun fizzBuzz(x: Int): String =
    when {
        x % 3 == 0 && x % 5 == 0 -> "FizzBuzz"
        x % 3 == 0 -> "Fizz"
        x % 5 == 0 -> "Buzz"
        else -> x.toString()
    }
