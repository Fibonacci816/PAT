#include <stdio.h>
#include <stdlib.h>
typedef struct NodeS{
    long value;
    struct NodeS * next;
} Node;
int main()
{
    Node * head, * p, *q, *cur;
    head = (Node *)malloc(sizeof(Node));
    head->value = 0L;
    p = head;
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        cur = (Node *)malloc(sizeof(Node));
        scanf("%ld", &cur->value);
        cur->next = NULL;
        p->next = cur;
        p = cur;
        head->value++;
    }
    q = head;
    p = q->next;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        cur = (Node *)malloc(sizeof(Node));
        scanf("%ld", &cur->value);
        cur->next = NULL;
        while(p && p->value < cur->value){
            q = p;
            p = p->next;
        }

        if(p == NULL){
            q->next = cur;
            q = cur;
        } else {
            cur->next = p;
            q->next = cur;
            q = cur;
        }
        head->value++;
    }
    p = head;
    for(int i = 0; i <= (head->value-1)/2.0; i++){
        p = p->next;
    }
    printf("%d", p->value);
    return 0;
}
