//
// Created by Hp-EliteBook on 10/23/2019.
//

#ifndef CNC_2014_SECOND_PROBLEM_B_H
#define CNC_2014_SECOND_PROBLEM_B_H

#include <string.h>

typedef struct queue{
    char fileName[80];
    struct queue *next;
}queue_t;

queue_t pList_0 = {"File_0.txt,File_1.txt,File_2.txt,File_3.txt",NULL};
queue_t pList_1 = {"File_4.txt,File_5.txt",NULL};
queue_t pList_2 = {"File_6.txt",NULL};
queue_t pList_3 = {"File_7.txt",NULL};

queue_t *pList, *pList2;
/* Question 8 */
/**************/
int display(){
    pList = &pList_0;
    pList_0.next = &pList_1;
    pList_1.next = &pList_2;
    pList_2.next = &pList_3;
    int i = 0;
    while (pList != NULL){
        printf("%s\n", pList->fileName);
        pList = pList->next;
        i++;
    }
    return i;
}

/* Question 9 */
/**************/
FILE *pFile_0;

void print(){
    pList = &pList_2;
/*    pList_0.next = &pList_1;
    pList_1.next = &pList_2;*/
    pList_2.next = &pList_3;
    if (pList != NULL){
        pFile_0 = fopen(pList->fileName,"r");
        int c = 0;
        while (c != EOF){
            c = fgetc(pFile_0);
            printf("%c", c);
        }
        fclose(pFile_0);
        printf("After Reading\n");
        pList = pList->next;
    }
}

/* Question 10 */
/**************/
void removeFunc(char fileN[]){
    pList2 = &pList_0;
    pList_0.next = &pList_1;
    pList_1.next = &pList_2;
    pList_2.next = &pList_3;
    if(pList2 != NULL) {
        while (strcmp(pList2->fileName, "") == 0) {
            pList2 = pList2->next;
            if (pList2 == NULL) {
                strcpy(fileN,"");
                break;
            }
        }
        if (pList2 != NULL) {
            char fil[80] = "";
            int i = 0, j = 0;
            for (i = 0; pList2->fileName[i] != '\0'; ++i) {
                if (pList2->fileName[i] == ',') {
                    break;
                }
                fil[i] = pList2->fileName[i];
            }
            strcpy(fileN, fil);
            for (j = 0; pList2->fileName[i] != '\0'; ++j) {
                i++;
                pList2->fileName[j] = pList2->fileName[i];
            }
            pList2->fileName[j] = '\0';
        }
    }
}


#endif //CNC_2014_SECOND_PROBLEM_B_H
