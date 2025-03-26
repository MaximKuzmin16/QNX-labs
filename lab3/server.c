// server.c
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <inttypes.h>
#include <errno.h>
#include <sys/neutrino.h>

void reverse(char s[])
{
    int lenght = strlen(s);
    int c, i, j;
    for (i=0, j = lenght -1; i<j;i++,j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void server(void )
{
  int rcvid;         //Ykazivaet komy nado otvechat
  int chid;          //Identifikator kanala
  char message[512]; // 
  
  printf("Server start working \n");
 
 chid=ChannelCreate(0);         //Sozdanie Kanala
 printf("Chanel id: %d \n", chid);
 printf("Pid: %d \n", getpid());
 // vipolniaetsa vechno- dlia servera eto normalno
 while(1) 
    {
    // Polychit i vivesti soobshenie

    rcvid=MsgReceive(chid,message,sizeof(message), NULL);
    printf("Polychili soobshenie, rcvid  %X \n",rcvid  );
    printf("Soobshenie takoe : \"%s\". \n", message  );
    reverse(message);
    MsgReply(rcvid, EOK, message, sizeof(message)) ;
    printf("Server >> %s \n", message);
    }
}

int main(void)
{
printf("Prog server by Maxim Kuzmin I914B \n");
server();
sleep(5);
return(1);
}
