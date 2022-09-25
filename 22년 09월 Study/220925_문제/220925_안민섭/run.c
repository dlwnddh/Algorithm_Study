#include "run.h"

int run(char cmd[100]){
	if(!strcmp(cmd,"exit")) return 1;
	//if(!strcmp(cmd,"ls")) system("ls -al");
	return 0;
}
