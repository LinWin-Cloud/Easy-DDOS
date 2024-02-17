# EasyDDOS 流量杀手
EasyDDOS高性能DDOS工具-流量杀手。专门设计用于在一段时间内(攻击与结束后) 
局域网或者手机电脑热点瘫痪、流量欠费、局域网内所有互联网设备的网络全部掉线
或者网络及慢。在ddos方案中，该软件提供 http 高度攻击、死亡之ping、局域网
/热点扫描与信息收集等。

### 关于软件
- 作者: 王相卿
- 软件名称: EasyDDOS
- 编写语言: C++
- 适用平台: Linux
- 项目地址: https://gitee.com/LinWin-Cloud/easy-ddos
- 联系方式:
    1. QQ: 2382546858
    2. 邮箱: 2382546858@qq.com

### 文档
- https://gitee.com/LinWin-Cloud/easy-ddos/wiki/

### 攻击内容
- 1 HTTP攻击: 模拟若干用户不停发送HTTP请求
- 2 死亡之ping: 模拟若干用户不停发送ping攻击
- 3 局域网扫描: 扫描所有局域网网段，并且获取目标的基础信息
- 4 局域网/热点破坏: 利用局域网扫描信息实施局域网/热点网络环境破坏
- 5 Whois工具: 通过 whois 工具查询网站信息
- 6 网络资源攻击: 通过一个数据包携带大量数据来堵塞对方网络资源（对局域网压力很大）

### Linux 安装
克隆源代码，默认的编译版本为 amd64 架构 (x86_64)
> git clone https://gitee.com/LinWin-Cloud/easy-ddos

进入源代码目录
> cd easy-ddos

运行库安装程序 (建议使用Ubuntu , 因为Ubuntu支持最好，开发测试全部采用Ubuntu22.03版本)
> python3 ./install_lib.py

运行EasyDDOS
> sudo ./bin/easy_ddos  #必须以root运行，否则无法运行

### Android Termux安装
需要在Termux环境下安装小型Ubuntu系统，在Termux内运行以下命令.
- 这个教程在: https://gitee.com/KudouShinnyan/ubuntu-in-termux
```angular2html
apt install git proot -y

git clone --depth=1 -b ubuntu22.04 https://gitee.com/KudouShinnyan/ubuntu-in-termux

mv ubuntu-in-termux ubuntu22.04

cd ubuntu-in-termux

chmod +x ubuntu.sh

./ubuntu.sh -y

sed -i 's/ports.ubuntu.com/mirrors.bfsu.edu.cn/g' /etc/apt/sources.list

apt update && apt upgrade -y
```

在 Ubuntu 中执行以上安装指令
克隆源代码，默认的编译版本为 amd64 架构 (x86_64)
> git clone https://gitee.com/LinWin-Cloud/easy-ddos

进入源代码目录
> cd easy-ddos

运行库安装程序 (建议使用Ubuntu , 因为Ubuntu支持最好，开发测试全部采用Ubuntu22.03版本)
> python3 ./install_lib.py

运行EasyDDOS
> sudo ./bin/easy_ddos  #必须以root运行，否则无法运行

### 编译软件
当然如果架构不符合，那就编译一个：安装必要的库
> python3 ./install_lib.py

依赖的库
```
libcurl4-openssl-dev
net-tools
whois
arp-scan
```
启动编译脚本
> ./build-linux.sh # 自动编译到 ./bin/easy_ddos