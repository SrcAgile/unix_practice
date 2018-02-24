#include <time.h>
typedef struct data_struct
{
	char *string;
	time_t time;
}data_t;
int accessData(void);
int addData(data_t data);
int freeKey(int key);
int getData(int key,data_t *datap);