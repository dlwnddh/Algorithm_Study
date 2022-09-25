#include "run.h"

int run(char cmd[100]){
	while(1){
		printf("SSAFY > ");
		gets(cmd);
		if(!strcmp(cmd,"exit")) return 1;
		system(cmd);
	}
	//if(!strcmp(cmd,"ls")) system("ls -al");
	return 0;
}
