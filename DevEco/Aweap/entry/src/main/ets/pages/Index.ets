import Todolist from "./ITEM";
import router from '@ohos.router';

let mgs: string = '我爱玩原神';

@Entry
@Component
struct Index {
  @State gen: number = 0
  gens: Array<String> = ['原神', '崩坏', '我的世界', 'Phigros']

  build() {
    Column({ space: 20 }) {
      Text(this.gen.toString()) //实时更新太牛啦
        .fontSize(54)
        .fontWeight(FontWeight.Bolder)
        .fontColor("#66CCFF")
        .onClick(() => {
          this.gen = this.gen + 1
        })
      LoadingProgress()
        .height(60)
        .width(60)
      ForEach(this.gens, (item) => {
        Todolist({ content: item })
      })
      TextInput({ placeholder: '输入几个字试试？' })
        .onChange((value: string) => {
          mgs = value;
        })
        .width('90%')
      Row() {
        Button('Second')
          .width(100)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            router.pushUrl({
              url: 'pages/second',
              params: {
                src: mgs
              }
            })
          })
        Button('Third')
          .width(100)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            router.pushUrl({
              url: 'pages/third',
              params: {
                src: mgs
              }
            })
          })
      }.justifyContent(FlexAlign.SpaceAround)
      .width('100%')
    }.width('100%').height('100%').backgroundColor(0xF1F3F5)
  }
}