function enlargeImage(abc) {
    var img = document.getElementById(abc);
    img.style.transform = 'scale(2)';
    img.style.transition = 'transform 0.25s ease';
}
function enDefaultImage(abc) {
    var img = document.getElementById(abc);
    img.style.transform = 'scale(1)';
    img.style.transition = 'transform 0.25s ease';
}
