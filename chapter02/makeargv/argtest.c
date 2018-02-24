#include <stdio.h>
int main(int argc,char **argv){
	if(argc!=2){
		fprintf(stderr,"Usge: %s n",argv[0]);
		return 1;
	}
	char **myargv;
	int numbertokens;
	if((numbertokens=makeagrv(argv[1],&myargv))==-1){
		fprintf(stderr,"failed to construct an argument array for %s\n",argv[1]);
		return 1;
	}
	printf("the arggumen array contains:\n");
	for(int i=0;i<numbertokens;i++)
		printf("%d: %s\n",i,myargv[i]);
	return 0;
}
