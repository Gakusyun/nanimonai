var list1 = ['王伟', '李佳', '赵俊杰', '董可'];
var list2;
for (var i in list1) {
    document.write("<li onclick='toList2(i)'>" + list1[i] + "</li>");
}
var toList2 = function (i) {
    list2.push(list1[i]);
    list1.splice(i, i);
};
