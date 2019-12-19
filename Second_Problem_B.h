//
// Created by Hp-EliteBook on 10/23/2019.
//

#ifndef CNC_2014_SECOND_PROBLEM_B_H
#define CNC_2014_SECOND_PROBLEM_B_H

#include <string.h>

typedef struct fileAttente{
    char fileName[80];
    struct fileAttente *next;
}fileAttente_t;

fileAttente_t teteListe_0 = {"File_0.txt,File_1.txt,File_2.txt,File_3.txt",NULL};
fileAttente teteListe_1 = {"File_4.txt,File_5.txt",NULL};
fileAttente teteListe_2 = {"File_6.txt",NULL};
fileAttente teteListe_3 = {"File_7.txt",NULL};

fileAttente *teteListe, *teteListe2;
/* Question 8 */
/**************/
int display(){
    teteListe = &teteListe_0;
    teteListe_0.next = &teteListe_1;
    teteListe_1.next = &teteListe_2;
    teteListe_2.next = &teteListe_3;
    int i = 0;
    while (teteListe != NULL){
        printf("%s\n", teteListe->fileName);
        teteListe = teteListe->next;
        i++;
    }
    return i;
}

/* Question 9 */
/**************/
FILE *pFile_0;

void print(){
    teteListe = &teteListe_2;
/*    teteListe_0.next = &teteListe_1;
    teteListe_1.next = &teteListe_2;*/
    teteListe_2.next = &teteListe_3;
    if (teteListe != NULL){
        pFile_0 = fopen(teteListe->fileName,"r");
        int c = 0;
        while (c != EOF){
            c = fgetc(pFile_0);
            printf("%c", c);
        }
        fclose(pFile_0);
        printf("After Reading\n");
        teteListe = teteListe->next;
    }
}

/* Question 10 */
/**************/
void removeFunc(char fileN[]){
    teteListe2 = &teteListe_0;
    teteListe_0.next = &teteListe_1;
    teteListe_1.next = &teteListe_2;
    teteListe_2.next = &teteListe_3;
    if(teteListe2 != NULL) {
        while (strcmp(teteListe2->fileName, "") == 0) {
            teteListe2 = teteListe2->next;
            if (teteListe2 == NULL) {
                strcpy(fileN,"");
                break;
            }
        }
        if (teteListe2 != NULL) {
            char fil[80] = "";
            int i = 0, j = 0;
            for (i = 0; teteListe2->fileName[i] != '\0'; ++i) {
                if (teteListe2->fileName[i] == ',') {
                    break;
                }
                fil[i] = teteListe2->fileName[i];
            }
            strcpy(fileN, fil);
            for (j = 0; teteListe2->fileName[i] != '\0'; ++j) {
                i++;
                teteListe2->fileName[j] = teteListe2->fileName[i];
            }
            teteListe2->fileName[j] = '\0';
        }
    }
}


#endif //CNC_2014_SECOND_PROBLEM_B_H
