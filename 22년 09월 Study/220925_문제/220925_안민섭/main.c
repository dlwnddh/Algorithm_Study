#include "run.h"

	
int main(){
	char cmd[100] ={};
	while(1){
		printf("SSAFY > ");
		gets(cmd);
		system(cmd);
		if(run(cmd))break;
	}


	return 0;
}

