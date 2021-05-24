# summary

## 环境配置

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
git clone -b upstream https://gitee.com/mirrors/riscv-newlib.git
git clone -b riscv-glibc-2.29 https://gitee.com/mirrors/riscv-glibc.git
git clone -b riscv-gcc-9.2.0-rvv https://gitee.com/mirrors/riscv-gcc.git
git clone https://gitee.com/mirrors/riscv-dejagnu.git
git clone -b rvv-0.8.x https://gitee.com/mirrors/riscv-binutils-gdb.git riscv-binutils
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

git clone git://github.com/mit-pdos/xv6-riscv-fall19.git
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
