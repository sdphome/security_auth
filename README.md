# sm2
sm2 algorithm


《libsm2.a》SM2算法静态库编译步骤：

1、将目录sm2放置于linux的共享目录下，使用cd命令进入miracl目录
2、在miracl目录执行命令：./armlinux.sh  执行完成之后会在当前目录生成libsm2.a静态库文件
3、将刚才生成的.a文件拷贝至sm2目录，然后在sm2目录下执行命令：
    arm-linux-g++ -o test  sm2.c sm2.hpp -L . -lsm2  就会生成sm2测试文件test，将其下载到开发板修改权限后即可运行。

注意：
   1、此libsm2.a文件，可直接替换加密机源码common/lib/下的同一文件；
   2、armlinux.sh编译脚本不要随意更改。
