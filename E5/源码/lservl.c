/*****************************************
* lserv1. C
* License server server program version 1
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <sys/errno.h>
#define MSGLEN 128
/* Size of our datagrams */
int main(int ac, char* av[])
{
	struct sockaddr_in client_addr;
	socklen_t addrlen = sizeof(client_addr);
	char buf[MSGLEN];
	int ret;
	int sock;
	// sock = setbuf();
	sock = setup();
	//printf("setup done\n");
	while (1) 
	{	
		addrlen = sizeof(client_addr);
		ret = recvfrom(sock, buf, MSGLEN, 0, (struct sockaddr*)&client_addr, &addrlen);
		if (ret != -1)
		{
			buf[ret] = '\0';
			narrate("G0T:", buf, &client_addr);
			handle_request(buf, &client_addr, addrlen);
		}
		else if(errno != EINTR)
			perror("recvfrom");
	}
}

