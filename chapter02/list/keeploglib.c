#include <stdio.h>
#include <stdlib.h>
#include "listlib.h"
int runproc(char *cmd){
	data_t execute;
	execute.string=cmd;
	if(time(&execute.time)==-1)
		return -1;
	if(system(cmd)==-1)
		return -1;
	return addData(execute);
}

void showhistory(FILE *f){
	data_t data;
	int key;
	key=accessData();
	if(key==-1){
		fprintf(f, "No History\n");
		return;
	}
	while(!getData(key,&data)&&data.string!=NULL){
		fprintf(f, "\033[1;33mCommand:%s\nTime: %s\n",data.string,ctime(&(data.time)));
		free(data.string);
	}
}