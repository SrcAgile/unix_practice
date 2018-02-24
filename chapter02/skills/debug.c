#include <stdio.h>
int main(){
	int i=1;
	int n=2;
#ifdef DEBUG
	printf("i is %d,n is %d\n",i,n);
#endif
	printf("the sum of i&n is %d",i+n);
	return 0;
}
