#include <string.h>//use strtok
//strtok会破坏s的完整性,不适合多线程
int makeargv(const char *s,const char *delimiters,char ***argvp){
	int err;
	const char *snew;//reprocessing of s
	char *t;
	if((s==NULL)||(delimiters==NULL)||(argvp==NULL)){/*para valid check*/
		errno=EINVAL;
		return -1;
	}
	*argvp=NULL;//clear argvp
	snew=s+strspn(s,delimiters);//clear delimiters in front of s
	if ((t=(char *)malloc(strlen(snew)+1))==NULL)
		return -1;
	strcpy(t,snew);
	numtokens=0;
	if(strtok(t,delimiters)!=NULL)/*count number */
		for(numtokens=1;strtok(NULL,delimiters)!=NULL;numtokens++)
	if ((*argvp = malloc((numtokens + 1)*sizeof(char *))) == NULL){
		err=errno;//保存上下文
		free(t);
		errno=err;
		return -1;
	}
	if(numtokens==0)
		free(t);
	else{
		strcpy(t,snew);
		**argvp=strtok(t,delimiters);
		for(i=1;i<numtokens;i++)
			((*argvp)+i)=strtok(NULL,delimiters);
	}
	*((*argvp) + numtokens) = NULL; 
	return numtokens;
}