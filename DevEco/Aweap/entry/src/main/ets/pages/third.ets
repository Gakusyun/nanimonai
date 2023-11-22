import router from '@ohos.router';

@Entry
@Component
struct Third {
  @State message: string = 'Genshin Impact'

  build() {

    Tabs({ barPosition: BarPosition.End }) {
      TabContent() {
        Column({space:10}) {
          Button('Back')
            .onClick(() => {
              router.back()
            })
          Text(this.message)
            .fontColor(0xff0000)
            .fontSize(33)
            .onClick(()=>{
              if(this.message=="Genshin Impact"){
                this.message="启动"
              }else{
                this.message="Genshin Impact"
              }
            })
        }.width('100%')
        .height('100%')
        .backgroundColor(Color.Green)
      }
      .tabBar('Green')

      TabContent() {
        Column()
          .width('100%')
          .height('100%')
          .backgroundColor(0x66CCFF)
      }
      .tabBar('Blue')

      TabContent() {
        Column()
          .width('100%')
          .height('100%')
          .backgroundColor(0xff6699)
      }
      .tabBar('Pink')

    }
    .barWidth('100%')
    .barHeight(60)
  }
}