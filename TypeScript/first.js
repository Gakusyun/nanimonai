for (var i = 0; i < 100; i++) {
    if (genshin(i)) {
        console.log(i);
    }
}
function genshin(num) {
    if (num % 2) {
        return true;
    }
}
