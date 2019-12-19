//
// Created by Hp-EliteBook on 10/22/2019.
//

#ifndef CNC_2014_SECONDPROBLEM_H
#define CNC_2014_SECONDPROBLEM_H

#include <string.h>
#define MAX 4
char T[MAX][80] = {"File_0","File_1","File_2",""};
int endIndex = -1;

/* Question 5-a */
/****************/
void initialize(){
    for (int i = 0; i < MAX; ++i) {
        strcpy(T[i],"");
    }
    endIndex = -1;
}

/* Question 5-b */
/****************/
int empty(){
    for (int i = 0; i < MAX; ++i) {
        if (strcmp(T[i],"")!=0){
            return 0;
        }
    }
    endIndex = -1;
    return 1;
}

/* Question 5-b */
/****************/
int full(){
    for (int i = 0; i < MAX; ++i) {
        if (strcmp(T[i],"")==0) {
            endIndex = i-1;
            return 0;
        }
    }
    endIndex = MAX-1;
    return 1;
}

/* Question 6 */
/**************/
int add(char fileName[]){
    if (full()==1){
        return 0;
    } else{
        strcpy(T[endIndex+1],fileName);
        endIndex += 1;
        return 1;
    }
}

/* Question 7 */
/**************/
int delete(char fileName[]){
    if (empty()==1){
        return 0;
    } else {
        full();
        strcpy(fileName,T[0]);
        for (int i = 0; i < endIndex; ++i) {
            strcpy(T[i],T[i+1]);
        }
        for (int j = endIndex; j < MAX; ++j) {
            strcpy(T[j],"");
        }
        endIndex -= 1;
        return 1;
    }
}

#endif //CNC_2014_SECONDPROBLEM_H
