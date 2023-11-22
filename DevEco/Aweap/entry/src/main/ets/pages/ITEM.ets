@Component
export default struct Todolist {
  private content: string;
  @State isClick: boolean = false;

  build() {
    Row() {
      Text("  哈罗哈罗")
      Text(this.content.toString())
        .opacity(this.isClick ? 0.4 : 1.0)
    }.borderRadius(24)
    .backgroundColor(this.isClick ? "#66ccff" : "#ffffff")
    .onClick(() => {
      this.isClick = !this.isClick
    })
    .justifyContent(FlexAlign.Start)
    .width('90%')
    .height(40)
  }
}