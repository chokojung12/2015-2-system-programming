#include  <sys/types.h>  /* tellwait1.c */
#include  "ourhdr.h"
#include  "tellwait.h"

static void charatatime(char *);

int main(void) {
	pid_t  pid;

	if ( (pid = fork()) < 0) perror("fork error");
	else if (pid == 0)  charatatime("output from child\n");
        else                charatatime("output from parent\n");
	
	exit(0);
}

static void charatatime(char *str) {
	char  *ptr;
	int    c;

	setbuf(stdout, NULL);      /* set unbuffered */
      	for (ptr = str; c = *ptr++; ){
		putc(c, stdout);
	        usleep(10000);
	}
}
			
