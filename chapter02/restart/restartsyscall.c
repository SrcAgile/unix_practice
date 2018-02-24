#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
int main(int argc,char **argv){
	int err;
	//extern int errno;
	if(argc!=2){
		fprintf(stderr,"Usage: %s n\n",argv[0]);
		return 1;
	}
	int fd=atoi(argv[1]);
	while(((err=close(fd))==-1)&&(errno==EINTR));
	if(err==-1){
		perror("Failed to close the file");
		return 1;
	}
	printf("close success\n");
	return 0;
}
