for (let i = 0; i < 100; i++) {
    if (genshin(i)) {
        console.log(i)
    }
}
function genshin(num: number) {
    if (num % 2) {
        return true
    }
}