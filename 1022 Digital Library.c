#include <stdio.h>
#include <string.h>
typedef struct NodeS{
    int ID;
    char title[81];
    char author[81];
    char keyWords[55];
    char publisher[81];
    char year[5];
} Book;
int main()
{
    int N, M;
    scanf("%d", &N);
    Book books[N];
    int id;
    int index;
    for(int i = 0; i < N; i++){
        if(i == 0){
            scanf("%d\n", &books[0].ID);
            gets(books[0].title);
            gets(books[0].author);
            gets(books[0].keyWords);
            gets(books[0].publisher);
            gets(books[0].year);
        } else {
            scanf("%d\n", &id);
            for(index = i; index > 0; index--){
                if(books[index-1].ID < id){
                    break;
                }
                books[index] = books[index -1];
            }
            books[index].ID = id;
            gets(books[index].title);
            gets(books[index].author);
            gets(books[index].keyWords);
            gets(books[index].publisher);
            gets(books[index].year);
        }
    }
    scanf("%d", &M);
    char str[81];
    int flag;
    for(int i = 0; i < M; i++){
        flag = 0;
        scanf("%d: ", &index);
        gets(str);
        printf("%d: %s\n", index, str);
        switch(index){
            case 1:
                for(int j = 0; j < N; j++){
                    if(strcmp(books[j].title, str) == 0){
                        printf("%07d\n", books[j].ID);
                        flag++;
                    }
                }
                break;
            case 2:
                for(int j = 0; j < N; j++){
                    if(strcmp(books[j].author, str) == 0){
                        printf("%07d\n", books[j].ID);
                        flag++;
                    }
                }
                break;
            case 3:
                for(int j = 0; j < N; j++){
                    if(strstr(books[j].keyWords, str) != NULL){
                        printf("%07d\n", books[j].ID);
                        flag++;
                    }
                }
                break;
            case 4:
                for(int j = 0; j < N; j++){
                    if(strcmp(books[j].publisher, str) == 0){
                        printf("%07d\n", books[j].ID);
                        flag++;
                    }
                }
                break;
            case 5:
                for(int j = 0; j < N; j++){
                    if(strcmp(books[j].year, str) == 0){
                        printf("%07d\n", books[j].ID);
                        flag++;
                    }
                }
        }
        if(flag == 0){
            printf("Not Found\n");
        }
    }
    return 0;
}
