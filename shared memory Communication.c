#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define MAX_CHAR 128
#define MAX_SIZE 2048

int main(void) {
    char *line1 = (char *)malloc(MAX_CHAR * sizeof(char));
    char *line2 = (char *)malloc(MAX_CHAR * sizeof(char));
    char *line3 = (char *)malloc(MAX_CHAR * sizeof(char));
    key_t key;
    int shm_id;
    char * shmPtr;
    if((key= ftok("/tmp",'y'))==-1){
        perror("ftok() failed");
        exit(EXIT_FAILURE);
    }

    if((shm_id= shmget(key,MAX_SIZE,IPC_CREAT|IPC_EXCL|0600))==-1){
        perror("error shmget()");
    }
    if((shmPtr=(char *) shmat(shm_id,NULL,0))==(char *)-1){
        perror("shmat failed");
        exit(EXIT_FAILURE);
    }


    fgets(line1, MAX_CHAR, stdin);
    line1[strcspn(line1, "\n")] = 0;

    if (strlen(line1) > MAX_CHAR) {
        printf("ERR\n");
        //continue;
    }

    if (strcmp(line1, "END") == 0) {
        //break;
    }
    strcpy(shmPtr,line1);
    printf("this is the shared memory value %s",shmPtr);

    fgets(line2, MAX_CHAR, stdin);
    line2[strcspn(line2, "\n")] = 0;

    if (strlen(line2) > MAX_CHAR) {
        printf("ERR\n");
        // continue;
    }

    if (strcmp(line2, "END") == 0) {
        //  break;
    }

    fgets(line3, MAX_CHAR, stdin);
    line3[strcspn(line3, "\n")] = 0;

    if (strlen(line3)>MAX_CHAR){
        printf("ERR\n");
        // continue;
    }
    shmdt(shmPtr);

    return 0;
}
