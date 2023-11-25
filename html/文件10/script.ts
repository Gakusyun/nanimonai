let list1: string[] = ['王伟', '李佳', '赵俊杰', '董可']
let list2: string[]
for (let i in list1) {
    document.write("<li onclick='toList2(i)'>" + list1[i] + "</li>")
}

let toList2 = (i) => {
    list2.push(list1[i])
    list1.splice(i, i)
}