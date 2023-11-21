@Entry
@Component
struct Index {
  @State message: string = 'Genshin Impact'

  build() {
    Row() {
      Column() {
        Text(this.message)
      }
      .width('100%')
    }
    .height('100%')
  }
}