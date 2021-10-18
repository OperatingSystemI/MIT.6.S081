# MIT6.S081课程学习

## 介绍
课程是MIT6.S081，主要是收集了一些中文版的学习资料方便学习，以及记录一下学习的过程。该课程主要分成以下几个部分：
1. **预习**：这个主要是看Xv6文档（有中文版）
2. **教学视频**：YouTube上，可以点自动翻译（也可以看中文字幕）
3. **实验**：这个是最重要的，后面详细介绍一下

## 课程地址
1. [官方地址](https://pdos.csail.mit.edu/6.828/2020/schedule.html) (包括视频、学习讲义、实验等所有资料，只不过是英文的)
2. [视频中文字幕文档](https://github.com/OperatingSystemI/MIT.6.S081/tree/main/MIT6.S081课程中文字幕)（把视频翻译成了中文字幕，可以直接学习，fork别人的）
3. [xv6文档中文版](https://github.com/OperatingSystemI/MIT.6.S081/tree/main/xv6-chinese)（每次上课前，可能会要求读这个文档，这里提供了中文版的，fork别人的）
4. [xv6文档官方英文版](https://pdos.csail.mit.edu/6.828/2020/xv6/book-riscv-rev1.pdf)(建议优先看英文版，有不懂的地方再对照中文版看，因为英文版提到的代码部分可以直接点击跳转到源码)
5. [实验环境搭建](https://pdos.csail.mit.edu/6.828/2020/tools.html)（官方教你如何下载配套软件）
6. [他人学习经历](https://zhuanlan.zhihu.com/p/251366985?utm_source=ZHShareTargetIDMore&utm_medium=social&utm_oi=827541041199583232)（看一看）

## 实验
实验才是最重要、最有趣的，所以这里单独讲一下实验的注意事项。
### 环境搭建
看[官方教程](https://pdos.csail.mit.edu/6.828/2020/tools.html)就可以了，但是可能下载速度会比较慢，最好要挂梯子，或者寻找别的下载路径。下完记得测试一下版本号。

### xv6源码下载
环境搭建的文档最后少了一小段关于下xv6源码的内容，大家可以看一下[实验一](https://pdos.csail.mit.edu/6.828/2020/labs/util.html)，前面有介绍如何下载。下面截取重要部分。
```shell
Fetch the xv6 source for the lab and check out the util branch:

$ git clone git://g.csail.mit.edu/xv6-labs-2020
Cloning into 'xv6-labs-2020'...
...
$ cd xv6-labs-2020
$ git checkout util
Branch 'util' set up to track remote branch 'util' from 'origin'.
Switched to a new branch 'util'
```

### 代码测试
一定要把[实验指南](https://pdos.csail.mit.edu/6.828/2020/labs/guidance.html)和[实验一](https://pdos.csail.mit.edu/6.828/2020/labs/util.html)着重看一遍，写的非常详细，他会告诉你怎么编译、运行、测试、调试代码、题目难度分级。
基本使用技巧：
1. `$ make qemu` : 编译运行xv6
2. `$ ls`: 列出所有文件
3. `Crtl-p`:列出当前存在进程
4. `Crtl-a x`：退出xv6系统
5. `./grade-lab-util <可执行文件名>`：测试你写的代码（注意这个要在xv6源码根目录下执行）

### gdb调试
gdb是一个非常不错的调试工具，本课程第二章就专门介绍了gdb的使用。

### 实验地址
1. [实验一](https://pdos.csail.mit.edu/6.828/2020/labs/util.html)
2. [实验二](https://pdos.csail.mit.edu/6.828/2020/labs/syscall.html)

## 持续更新
我也是刚刚起步，之后还会继续更新

