@Entry
@Component
struct Index {
  @State message: string = 'Genshin Impact'

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(40)
          .fontWeight(FontWeight.Bold)
          .fontColor(Color.Blue)
      }
      .width('100%')
    }
    .height('100%')
  }
}