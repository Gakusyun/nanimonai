import router from '@ohos.router';
@Entry
@Component
struct second {
  @State message: string = router.getParams()?.['src'];

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        Button('Back')
          .onClick(()=>{
            router.back()
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}