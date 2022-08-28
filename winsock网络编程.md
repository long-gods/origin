```c++
struct sockaddr_in{
    short   sin_family;
    unsigned short   sin_port;
    struct  in_addr  sin_addr;
    char       sin_zero[8];
};
```

sin_family 指定AF_INET,代表所属的地址家族是TCP/IP地址家族；

sin_port代表端口号。在TCP/IP协议中，有65536个端口，定义为无符号short类型；

in_addr同样是结构体，为

```c++
struct in_addr{
    union{
        struct {u_char s_bl,s_b2,s_b3,s_b4;} S_un_b;
        struct{u_short s_wl,s_w2;}           S_un_w;
        u_long                               S_addr;
    }S_un;
}
```

![img](https://img-blog.csdn.net/20150722152710839?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQv/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center)

int getaddrinfo( const char *hostname, const char *service, const struct addrinfo *hints, struct addrinfo **result );

参数说明

hostname:一个[主机名](https://baike.sogou.com/lemma/ShowInnerLink.htm?lemmaId=7536474&ss_c=ssc.citiao.link)或者地址串(IPv4的[点分十进制](https://baike.sogou.com/lemma/ShowInnerLink.htm?lemmaId=71269717&ss_c=ssc.citiao.link)串或者IPv6的[16进制](https://baike.sogou.com/lemma/ShowInnerLink.htm?lemmaId=7532053&ss_c=ssc.citiao.link)串)

service：服务名可以是[十进制](https://baike.sogou.com/lemma/ShowInnerLink.htm?lemmaId=3006559&ss_c=ssc.citiao.link)的[端口号](https://baike.sogou.com/lemma/ShowInnerLink.htm?lemmaId=17312&ss_c=ssc.citiao.link)，也可以是已定义的服务名称，如ftp、http等

hints：可以是一个空指针，也可以是一个指向某个addrinfo[结构体](https://baike.sogou.com/lemma/ShowInnerLink.htm?lemmaId=126847&ss_c=ssc.citiao.link)的指针，调用者在这个结构中填入关于期望返回的信息类型的暗示。举例来说：指定的服务既可支持TCP也可支持UDP，所以调用者可以把hints结构中的ai_socktype成员设置成SOCK_DGRAM使得返回的仅仅是适用于[数据报](https://baike.sogou.com/lemma/ShowInnerLink.htm?lemmaId=3939125&ss_c=ssc.citiao.link)[套接口](https://baike.sogou.com/lemma/ShowInnerLink.htm?lemmaId=57749149&ss_c=ssc.citiao.link)的信息。

result：本函数通过result指针参数返回一个指向addrinfo结构体链表的指针。

