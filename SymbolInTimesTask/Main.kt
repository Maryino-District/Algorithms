/**
 * Найти символ, который печатался дольше  всего
 */
fun main() {
    val numberOfLetters = readLine() // количество символов на входе
    val letters = readLine() // непосредственно сами символы
    var inputTimes = readLine() // дельта между воеменем, затраченным на печать между каждым символов
    var timesList: List<Int> = listOf(0)+ inputTimes!!.split(" ").map{it.toInt()}
    var max = 0
    var index = 0
    for (i in 0..timesList.size-2) {
        if (timesList[i+1]-timesList[i] > max) {
            max = timesList[i+1] - timesList[i]
            index = i
        }
    }
    println(letters?.get(index))
    var s = "dddf"
    println(replace(Regex("^df$"),""))
}
