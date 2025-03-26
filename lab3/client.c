//client
#include <stdio.h>
#include <pthread.h>
#include <inttypes.h>
#include <errno.h>
#include <sys/neutrino.h>
#include <string.h>

int main(void)
{
    char smsg[20];
    char rmsg[200];
    int coid;
    long serv_pid;
    printf("Prog client, Vvedite PID servera\n");
    scanf("%d", &serv_pid);
    printf ("Vveli %d \n", serv_pid);
    coid = ConnectAttach(0, serv_pid, 1, 0, 0);
    while (1)
    {
        printf("Client >> ");
        fflush(stdout):
        getchar();
        fgets(smsg, sizeof(smsg), stdin);
        if (MsgSend(coid, smsg, strlen(smsg)+1, rmsg, sizeof(rmsg)==-1))
        {
            printf("Error MsgSend\n");
        }
        printf("Server >> %s\n", rmsg);
    }
    return (1);
}
