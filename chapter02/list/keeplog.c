#include <string.h>
#include <limits.h>//Maybe define MAX_CANON
#include <stdio.h>
#include <stdlib.h>
#include "listlib.h"
#ifndef MAX_CANON
#define MAX_CANON 8192
#endif

int runproc(char *cmd);
void showhistory(FILE *f);

int main(int argc,char **argv){
	char cmd[MAX_CANON];
	int history=1;
	if(argc==1)
		history=0;
	else if((argc>2 || strcmp(argv[1],"history"))){
		fprintf(stderr, "Usage: %s [history]\n",argv[0]);
		return 1;
	}

	while(printf("\033[1;31mMeta$ \033[1;32m"),fgets(cmd,MAX_CANON,stdin)!=NULL){//防止缓冲区溢出
		if(*(cmd+strlen(cmd)-1)=='\n'){//判断行尾
			*(cmd+strlen(cmd)-1)=0;
		}
		if(history&&!strcmp(cmd,"history"))
			showhistory(stdout);
		else if(runproc(cmd)){
			perror("failed to execute");
			break;
		}
	}
	puts(">>>>>>>>>the list command execute is:");
	showhistory(stdout);
	return 0;
}