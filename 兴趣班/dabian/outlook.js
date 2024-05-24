var blo = document.getElementsByTag(div)
for(var i=0;i<blo.length;i++){
    blo[i].onClick=function(){
        this.className="blockBeClick";
    }
}