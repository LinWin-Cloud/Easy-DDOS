
#include "config.h"

void print_document_1() {
    string content = R"(
# 文档1: 了解EasyDDOS以及DDOS

#### 什么是 DDOS
分散式阻断服务攻击通常简称为DDOS ，即“Distributed Denial of Service” 的缩写。顾名思义, 它利用网络上已被攻陷的电脑作为傀儡机, 向某一特定的目标电脑发动密集式的“ 拒绝服务” 要求, 借以把目标电脑的网络资源及系统资源耗尽。一旦目标电脑负荷过重而倒下, 攻击者即可透过系统的漏洞而入侵目标电脑。
*该段摘选自百度百科*

#### 了解EasyDDOS
EasyDDOS设计用于便捷的摧毁局域网和热点。并可以给公网网站造成较大的网络压力。实际上EasyDDOS对局域网和热点的摧毁效果是非常显著的，轻则可以造成局域网网络及其卡顿，重则局域网和热点内的所有设备都不能访问互联网了。


作者在编写这款软件的时候还在读初中，编写这款软件的想法是因为在2024年除夕的时候对*上海日本人学校*发起DDOS网络进攻的时候用了家里的计算机和路由器，发出去的大量网络数据都是经过家里的路由器，导致家里面网络直接瘫痪。这次事情过后突发奇想，原来这就是DOS攻击啊。

<a href='./2.md'>下一章: EasyDDOS操作</a>
    )";
    cout << content.c_str() << endl;
}
void print_document_2() {
    string content = R"(
# EasyDDOS操作
#### 所有 EasyDDOS功能列表
```
 -1- HTTP攻击          按下 1         模拟若干用户不停发送HTTP请求
 -2- 死亡之ping        按下 2         模拟若干用户不停发送ping攻击
 -3- 局域网扫描         按下 3         扫描所有局域网网段，并且获取目标的基础信息
 -4- 局域网/热点破坏     按下 4         利用局域网扫描信息实施局域网/热点网络环境破坏
 -5- Whois工具         按下 5         通过 whois 工具查询网站信息
```
- 按下 q 退出
- 输入 help 输出帮助信息
- 输入 doc 输出文档

<a href='./3.md'>下一章: 该在什么情况下使用什么功能以及量</a>
    )";
    cout << content.c_str() << endl;
}

void print_document_3() {
        string content = R"(
# 该在什么情况下使用什么功能以及量
#### Http攻击
- 建议对一个IP用 1000 个线程 + max不间断攻击
- 输入的网址要带 https:// 或者 http://

#### 死亡之ping
- 一直运行 , 如果要停下按下 Ctrl + C
- 建议新建 1000 个线程
- 输入的网址不要包含 http:// 或者https:// 和 /

#### 局域网扫描
- 这个会对局域网内的IP进行扫描,无操作

#### 局域网/热点破坏
- arp扫描局域网内的所有IP，并给每个IP分配 800 个线程进行死亡之ping.


#### Whois工具
- 获取网站的信息
- 输入的网址不要包含 http:// 或者https:// 和 /
    )";
    cout << content.c_str() << endl;
}



void documents_console() {
    string console_print = R"(
 1. 文档1: 了解EasyDDOS以及DDOS                 按下1
 2. 文档2: EasyDDOS操作                         按下2
 3. 文档3: 该在什么情况下使用什么功能以及量     按下3
[!] Input 'q' to return the main console.
    )";
    cout << console_print.c_str() << endl;
    while (true) {
        string command = trim(input("EasyDDOS Console (Document) $ "));
        if (command == "q") {
            break;
        }
        else if (command == "1") { print_document_1(); }
        else if (command == "2") { print_document_2(); }
        else if (command == "3") { print_document_3(); }
    }
}