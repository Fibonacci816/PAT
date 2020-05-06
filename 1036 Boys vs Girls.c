#include <stdio.h>
#include <string.h>
int main()
{
    //the information of the female student with the highest grade
    char femaleName[11] = "null";
    char femaleId[11];
    int femaleGrade = 0;
    //the information of the male student with the lowest grade
    char maleName[11] = "null";
    char maleId[11];
    int maleGrade = 100;
    //current input
    int N;
    char curName[11];
    char gender;
    char curId[11];
    int curGrade;
    scanf("%d", &N);
    //find the female student with the highest grade and the male student with the lowest grade
    for(int i = 0; i < N; i++){
        scanf("%s %c %s %d", curName, &gender, curId, &curGrade);
        if(gender == 'F'){
            if(curGrade >= femaleGrade){
                femaleGrade = curGrade;
                strcpy(femaleName, curName);
                strcpy(femaleId, curId);
            }
        } else if(gender == 'M'){
            if(curGrade <= maleGrade){
                maleGrade = curGrade;
                strcpy(maleName, curName);
                strcpy(maleId, curId);
            }
        }
    }
    int flag = 0;
    if(strcmp(femaleName, "null")){
        printf("%s %s\n", femaleName, femaleId);
    } else {
        flag = 1;
        printf("Absent\n");
    }
    if(strcmp(maleName, "null")){
        printf("%s %s\n", maleName, maleId);
    } else {
        flag = 1;
        printf("Absent\n");
    }
    if(flag){
        printf("NA");
    } else {
        printf("%d", femaleGrade - maleGrade);
    }
    return 0;
}
