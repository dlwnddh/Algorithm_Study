#include "run.h"

struct Node{
    char key[100];
    char val[100];
};
struct Node histo[10];
int histo_Ptr = 0;
void run(){

    char cmd[100] ={};
    while(1){
        printf("SSAFY > ");
        gets(cmd);
        if(!strcmp(cmd,"exit")) return ;

        // show
        if(!strcmp(cmd,"show")){
            for(int i = 0; i<histo_Ptr;i++){
                printf("%s=%s\n", histo[i].key, histo[i].val);
            }
        }
        // a=10 format 일 경우
        else if(strstr(cmd,"=")){
            char *key = strtok(cmd,"=");
            char *val = strtok(NULL,"=");
            strcpy(histo[histo_Ptr].key,key);
            strcpy(histo[histo_Ptr].val,val);
            histo_Ptr++;
        }
        // echo ~
        else if(strstr(cmd,"echo")){
            char *echo = strtok(cmd," ");
            char *key = strtok(NULL," ");
            for(int i = 0; i<histo_Ptr;i++){
                if(!strcmp(histo[i].key,key)) {
                    printf("%s\n",histo[i].val);
                    break;
                }
            }
        }
        // 아무것도 아니면
        else{
            printf("%s",cmd);
            system(cmd);
        }
    }
    return ;
}
