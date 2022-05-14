fun main() {
    repeat(readln().toInt()) {
        val input = readln().split(" ")
        println(input[0].toInt() + input[1].toInt())
    }
}