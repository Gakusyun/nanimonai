; 假设数据段的起始地址为1000h
data segment
    ; 定义一个变量，用来存储要写入的字符串
    str  db 10 dup(?)
data ends

; 假设代码段的起始地址为2000h
code segment
          assume cs:code, ds:data
    start:
    ; 初始化数据段寄存器
          mov    ax, data
          mov    ds, ax
    ; 初始化源寄存器，赋值要写入的字符
          mov    ax, 6547h           ; 'E'
          mov    bx, 736eh           ; 'n'
          mov    cx, 6968h           ; 'h'
          mov    dh, 20h             ; ' '
    ; 初始化目标寄存器，指向数据段中的变量str的首地址
          mov    dl, offset str
    ; 把源寄存器中的值写入内存中
          mov    [dl], ax
          add    dl, 2
          mov    [dl], bx
          add    dl, 2
          mov    [dl], cx
          add    dl, 2
          mov    [dl], bl
          add    dl, 1
          mov    [dl], dh
          add    dl, 1
    ; 结束程序，返回操作系统
          mov    ah, 4ch
          int    21h
code ends
end start
