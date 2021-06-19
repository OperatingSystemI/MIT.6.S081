# summary

## 环境配置

[gdb参考](https://zhuanlan.zhihu.com/p/331492444)
[tool](https://pdos.csail.mit.edu/6.828/2020/tools.html)

```shell
# 基础依赖
sudo apt-get install git build-essential gdb-multiarch qemu-system-misc binutils-riscv64-linux-gnu 

# riscv-gnu-toolchain
## 依赖
sudo apt-get install autoconf automake autotools-dev curl libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev
## 包
[码云拉取riscv-gnu-toolchain](https://blog.csdn.net/ALLap97/article/details/106345045/)
git clone  https://gitee.com/mirrors/riscv-gnu-toolchain
cd riscv-gnu-toolchain
# ubuntu
git clone -b upstream https://gitee.com/mirrors/riscv-newlib.git
git clone -b riscv-glibc-2.29 https://gitee.com/mirrors/riscv-glibc.git
git clone -b riscv-gcc-9.2.0-rvv https://gitee.com/mirrors/riscv-gcc.git
git clone https://gitee.com/mirrors/riscv-dejagnu.git
git clone -b rvv-0.8.x https://gitee.com/mirrors/riscv-binutils-gdb.git riscv-binutils
git clone -b fsf-gdb-8.3-with-sim https://gitee.com/mirrors/riscv-binutils-gdb.git riscv-gdb
# mac
git clone -b upstream https://gitee.com/mirrors/riscv-newlib.git
git clone -b riscv-glibc-2.29 https://gitee.com/mirrors/riscv-glibc.git
git clone -b riscv-gcc-9.2.0-rvv https://gitee.com/mirrors/riscv-gcc.git
git clone https://gitee.com/mirrors/riscv-dejagnu.git
git clone -b riscv-binutils-2.36.1 https://gitee.com/mirrors/riscv-binutils-gdb.git riscv-binutils
git clone -b fsf-gdb-8.3-with-sim https://gitee.com/mirrors/riscv-binutils-gdb.git riscv-gdb


cd riscv-gnu-toolchain
./configure --prefix=/usr/local
sudo make

# qemu
wget https://download.qemu.org/qemu-5.1.0.tar.xz
tar xf qemu-5.1.0.tar.xz
cd qemu-5.1.0
./configure --disable-kvm --disable-werror --prefix=/usr/local --target-list="riscv64-softmmu"
make
sudo make install

git clone git://github.com/mit-pdos/xv6-riscv-book.git
git clone git://g.csail.mit.edu/xv6-labs-2020
git checkout util
进入这个目录再 make qemu


# 卸载qemu方法：
sudo rm -rf /usr/local/bin/qemu-*
sudo rm -rf /usr/local/libexec/qemu-bridge-helper
sudo rm -rf /usr/local/etc/qemu
sudo rm -rf /usr/local/share/qemu

# git梯子海外加速
git config -l # 查看配置

git config --global http.proxy 'socks5://127.0.0.1:1090'
git config --global https.proxy 'socks5://127.0.0.1:1090'

git config --global --unset http.proxy
git config --global --unset https.proxy
```

## 基本使用技巧：

```shell
$ make qemu : 编译运行xv6
$ ls: 列出所有文件
Crtl-p:列出当前存在进程
Crtl-a x：退出xv6系统
./grade-lab-util <可执行文件名>：测试你写的代码（注意这个要在xv6源码根目录下执行）
riscv64-unknown-elf-gdb kernel/kernel 开启gdb指定位置
(gdb) target remote localhost:25000 手动设置
add-auto-load-safe-path .../.gdbinit 自动设置


```
