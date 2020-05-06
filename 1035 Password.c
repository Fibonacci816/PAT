#include <stdio.h>
#include <string.h>
typedef struct NodeS{
    char name[11];
    char password[11];
    int is_modefied;
} Node;
//替换password中的容易产生混淆的字符，若有替换返回1，否则返回0
int ModifyTheConfusingPasswords(char password[])
{
    int flag = 0;
    for(int i = 0; password[i] != '\0'; i++){
        if(password[i] == '1'){
            password[i] = '@';
            flag = 1;
        } else if(password[i] == '0'){
            password[i] = '%';
            flag = 1;
        } else if(password[i] == 'l'){
            password[i] = 'L';
            flag = 1;
        } else if(password[i] == 'O'){
            password[i] = 'o';
            flag = 1;
        }
    }
    return flag;
}
int main()
{
    int N, modefiedNum = 0;
    scanf("%d", &N);
    Node nodes[N];
    for(int i = 0; i < N; i++){
        scanf("%s %s", nodes[i].name, nodes[i].password);
        if(ModifyTheConfusingPasswords(nodes[i].password)){
            nodes[i].is_modefied = 1;
            modefiedNum++;
        } else {
            nodes[i].is_modefied = 0;
        }
    }
    if(modefiedNum == 0){
        if(N == 1){
            printf("There is 1 account and no account is modified");
        } else {
            printf("There are %d accounts and no account is modified", N);
        }
    } else {
        printf("%d\n", modefiedNum);
        for(int i = 0; i < N; i++){
            if(nodes[i].is_modefied){
                printf("%s %s\n", nodes[i].name, nodes[i].password);
            }
        }
    }
    return 0;
}
