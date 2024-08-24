fun main() {
    val s = readln()
    val KOREA = "KOREA"
    var i = 0
    var ans = 0

    s.forEach {
        if (it == KOREA[i]) {
            i++
            ans++
            if (i > 4) i = 0
        }
    }

    println(ans)
}
