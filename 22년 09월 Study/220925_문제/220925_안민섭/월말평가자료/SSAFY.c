#include <stdlib.h>
#include <stdio.h>


char history[100][100];
int history_num= 0;
char cmd[100];
int isSame(char a[100], char b[100]){

	for(int i = 0; i<100;i++){
		if(a[i] != b[i]) return 0;
		if(a[i] == '\0' || b[i] == '\0') break;
	}
	return 1;
}
void insertHistory(int index){
	for(int i = 0; i<100;i++){
		if(cmd[i] == '\0') break;
		history[index][i] = cmd[i];
	}
	return;
}
void setCmd(int index){
	if(index >=history_num){
		cmd[0] = '8';
		return;
	}

	for(int i = 0; i<100;i++){
		cmd[i] = history[index][i];
		if(history[index][i] == '\0') break;
	}
	return;
}
void operand(){

	if(isSame(cmd,"date")|| isSame(cmd,"uptime")) {
		system(cmd);
		insertHistory(history_num++);
	}
	else if(isSame(cmd,"ls")){
		system("ls -al");
		insertHistory(history_num++);
	}
	else if(isSame(cmd,"log")) {
		system("dmesg");
		insertHistory(history_num++);
	}
	else if(isSame(cmd,"history")){
		insertHistory(history_num++);
		for(int i = 0; i<history_num;i++){
			printf("%d %s\n",i,history[i]);
		}
	}
	else if(isSame(cmd,"hclear")){
		history_num = 0;
	}
	else printf("ERROR\n");
	return;
}

int main(){
	while(1){
		printf("SSAFY > ");
		scanf("%s",cmd);
		// while 종료
		if(isSame(cmd,"exit")) break;
		// !숫자
		if(cmd[0] == '!'){
			setCmd(atoi(&cmd[1]));
		}
		operand();
	}
	return 0;
}


