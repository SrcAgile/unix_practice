#include "listlib.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define TRAV_INIT_SIZE 8


typedef struct list_struct
{
	data_t item;
	struct list_struct *next;
}list_t;

static list_t endlist;//尾
static list_t *headptr=NULL;//首
static list_t *tailptr=NULL;//倒数第二尾
static list_t **travptrs=NULL;//key array
static int travptrs_size=0;
int accessData(){
	int i;
	list_t **newptrs;
	if(headptr==NULL){
		errno=EINVAL;
		puts("nothing...");
		return -1;
	}
	/*set key*/
	if(travptrs_size==0){
		travptrs=(list_t **)calloc(TRAV_INIT_SIZE,sizeof(list_t *));
		if(!travptrs)
			return -1;
		travptrs[0]=headptr;
		travptrs_size=TRAV_INIT_SIZE;
		return 0;
	}
	for(i=0;i<travptrs_size;i++){
		if(travptrs[i]==NULL){
			travptrs[i]=headptr;
			return i;
		}
	}//if not null
	newptrs=realloc(travptrs,2*travptrs_size*sizeof(list_t *));
	if(!newptrs)
		return -1;
	travptrs=newptrs;
	travptrs[travptrs_size]=headptr;
	travptrs_size*=2;
	return travptrs_size/2;
}
int addData(data_t data){
	list_t *newnode;
	int nodesize;
	nodesize=sizeof(list_t)+strlen(data.string)+1;
	if((newnode=(list_t *)(malloc(nodesize)))==NULL)
		return -1;
	newnode->item.time=data.time;
	newnode->item.string=(char *)newnode+sizeof(list_t);
	strcpy(newnode->item.string,data.string);
	newnode->next=NULL;
	if(headptr==NULL)
		headptr=newnode;
	else
		tailptr->next=newnode;
	tailptr=newnode;
	return 0;
}
int getData(int key,data_t *datap){
	/*获取key对应的指针数组并且向前移动*/
	list_t *t;
	if(key<0||key>=travptrs_size||travptrs[key]==NULL){
		errno=EINVAL;
		return -1;
	}
	if(travptrs[key]==&endlist){//
		datap->string=NULL;
		travptrs[key]=NULL;
		return 0;
	}
	t=travptrs[key];
	datap->string=(char *)malloc(sizeof(strlen(t->item.string))+1);
	strcpy(datap->string,t->item.string);
	if(t->next==NULL)
		travptrs[key]=&endlist;
	else
		travptrs[key]=t->next;
	return 0;
}
int freekey(int key){
	if(key<0||key>=travptrs_size){
		errno=EINVAL;
		return -1;
	}
	travptrs[key]==NULL;
	return 0;
}