#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define WORD_DELIMITERS " \t"
#define LINE_DELIMITERS "\n"
int wordCount(char *s){
	int count=1;
	char *last;
	if(strtok_r(s,WORD_DELIMITERS,&last)==NULL)
		return 0;
	for(;strtok_r(NULL,WORD_DELIMITERS,&last)!=NULL;count++);
	return count;
}
double wordaverage(char *s){
	int linecount=1;
	int words=0;
	char *nextline;
	char *last;
	nextline=strtok_r(s,LINE_DELIMITERS,&last);
	if(nextline==NULL)
		return 0.0;
	words+=wordCount(nextline);
	while((nextline=strtok_r(NULL,LINE_DELIMITERS,&last))!=NULL){
		words+=wordCount(nextline);
		linecount++;
	}
	printf("words:%d\n",words);
	printf("linecount:%d\n",linecount);
	return (double)words/linecount;
}
int main(){
	char *s="   1 e e\ne\ns";
	char *news=(char *)malloc((strlen(s)+1)*sizeof(char));
	if(!news){
		puts("something wrong");
		return -1;
	}
	strcpy(news,s);
	printf("average:%f\n",wordaverage(news));
	free(news);
	return 0;
}