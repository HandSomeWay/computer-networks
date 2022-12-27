/**********************************************************************
* 1clnt1.c
* License server client version 1
* link with 1clnt_funcs1.o dgram.o
*/
#include <stdio.h>
#include <stdlib.h>
int main(int ac, char* av[])
{
	setup();
	if (get_ticket() != 0)
		exit(0);
	do_regular_work();
	release_ticket();
	shut_down();
	/**********************************************************
	*do_regular_work the main work of the appl ication goes here
	*/
}
do_regular_work()
{
	printf("SuperSleep version 1.0 Running - Licensed Software\n");
	sleep(10); /* our patented sleep algorithm */
}
