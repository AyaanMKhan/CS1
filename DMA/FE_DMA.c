#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct StringType {
    char *string;
    int length;
}StringType;

typedef struct Employee{
    StringType *ename;
    double salary
}Employee;


Employee* createEmployees(char names[][50], double *salaries, int empCount){

    Employee *e = (Employee *)(empCount * sizeof(Employee));

    for(int i = 0; i < empCount; i++){
        e[i].salary = salaries[i];

        e[i].ename = malloc(sizeof(StringType));

        int length = strlen(e[i].ename) + 1;


        e[i].ename->string = malloc(length * sizeof(char));

        strcpy(e[i].ename->string, names[i]);
    }

    return e;
}

void freeMem(Employee* e, int n){


    for(int i = 0; i < n; i++){
        free(e[i].ename->string);
        free(e[i].ename);
    }

    free(e);

}

int main(){

    char nameList[][50] = {"Adam", "Josh", "Kyle", "Ali", "Mohammed"};

    double salaries[5] = {15.80, 13.5, 20.9, 12.99, 10.5}; 

    Employee *employees = createEmployees(nameList, salaries, 5);

    return 0;
}