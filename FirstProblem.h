//
// Created by Hp-EliteBook on 10/18/2019.
//

#ifndef CNC_2014_FIRSTPROBLEM_H
#define CNC_2014_FIRSTPROBLEM_H


/* First Question */
/******************/
int addressIP(const int TO[4]){
    for (int i = 0; i < 4; ++i) {
        if (TO[i] < 0 || TO[i] > 255)
            return 0;
    }
    return 1;
}

/* Second Question 2-a */
/******************/
long nbMachinesA(void){
    return (1<<24)-(1<<17)+(1<<10)-2;
}

/* Second Question 2-b */
/******************/
char classIP(int TO[4]){
    if (addressIP(TO)==0 || TO[3]==255 || TO[3]==0 || TO[0] == 0 || TO[0] == 127)
        return 'X';
    if (1<=TO[0] && TO[0]<=126)
        return 'A';
    if (128<=TO[0] && TO[0]<=191)
        return 'B';
    if (192<=TO[0] && TO[0]<=223)
        return 'C';
    return 'X';
}

/* Third Question 3-a */
/******************/
void binary(int byte, int bin[8]){
    for (int i = 0; i < 8; ++i) {
        bin[7-i] = byte % 2;
        byte /= 2;
    }
}

/* Third Question 3-b */
/******************/
int power(int a, int b){
    int i = 0, p =1;
    while(i < b){
        p *= a;
        i++;
    }
    return p;
}
int binaryAnd(int x, int y){
    int xbin[8] = {0}, ybin[8] = {0}, s = 0;
    binary(x,xbin);
    binary(y,ybin);
    for (int i = 0; i < 8; ++i) {
        s += xbin[i]*ybin[i]*power(2,7-i);
    }
    return s;
}

/* Third Question 3-c */
/******************/
void idNetwork(int TO[4], int NetId[4]){
    if (classIP(TO) == 'A'){
        NetId[0] = binaryAnd(TO[0],255);
        NetId[1] = NetId[2] = NetId[3] = 0;
    }
    if (classIP(TO) == 'B'){
        NetId[0] = binaryAnd(TO[0],255);
        NetId[1] = binaryAnd(TO[1],255);
        NetId[2] = NetId[3] = 0;
    }
    if (classIP(TO) == 'C'){
        NetId[0] = binaryAnd(TO[0],255);
        NetId[1] = binaryAnd(TO[1],255);
        NetId[2] = binaryAnd(TO[2],255);
        NetId[3] = 0;
    }
}

/* Fourth Question 4-a */
/******************/
int dichotomousSearch(int N, int T[], int inf, int sup, int x){
    int m = (inf + sup)/2;
    if ((inf >= sup) && x != T[m])
        return -1;
    if (x == T[m])
        return m;
    else if (x < T[m])
        return dichotomousSearch(m,T,inf,m-1,x);
    else
        return dichotomousSearch(m,T,m+1,sup,x);
}

/* Fourth Question 4-b */
/******************/
typedef struct {
    int hostId;
    char name[100];
}machine_t;

//machine_t tabMachine[N_tab];

int machineName(int N, machine_t tabMachine[], int x, char *nameR[]){
    int tab[N];
    for (int i = 0; i < N; ++i) {
        tab[i] = tabMachine[i].hostId;
    }
    int result = dichotomousSearch(N, tab, 0, N - 1, x);
    if(result == -1){
        *nameR = "";
        return -1;
    } else {
        *nameR = tabMachine[result].name;
        return result;
    }
}

#endif //CNC_2014_FIRSTPROBLEM_H
