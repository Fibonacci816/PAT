#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode{
    int exponent;
    double coefficient;
    struct ListNode* next;
}Node, *List;
int main()
{
    int K;
    List head = NULL;
    List p, pre, current;
    current = (Node *)malloc(sizeof(Node));
    current->exponent = 0;
    current->next = NULL;
    head = current;
    p = head;
    scanf("%d", &K);
    while(K){
        current = (Node *)malloc(sizeof(Node));
        scanf("%d %lf", &current->exponent, &current->coefficient);
        current->next = NULL;
        p->next = current;
        p = current;
        ++head->exponent;
        --K;
    }
    pre = head;
    p = pre->next;
    scanf("%d", &K);
    while(K){
        current = (Node *)malloc(sizeof(Node));
        scanf("%d %lf", &current->exponent, &current->coefficient);
        current->next = NULL;
        while(p!=NULL && current->exponent<p->exponent){   //输入的指数小于链表的元素指数
            pre = p;
            p = p->next;
        }
        if(p==NULL){
            pre->next = current;
            pre = current;
            ++head->exponent;
        }else{
            if(current->exponent>p->exponent){
                current->next = p;
                pre->next = current;
                pre = current;
                ++head->exponent;
            }else{
                if(current->coefficient+p->coefficient){
                    p->coefficient += current->coefficient;
                }else{
                    pre->next = p->next;
                    free(current);
                    free(p);
                    p =  pre->next;
                    --head->exponent;
                }
            }
        }
        --K;
    }
    printf("%d", head->exponent);
    current = head->next;
    while(current != NULL){
        printf(" %d %0.1lf", current->exponent, current->coefficient);
        current = current->next;
    }
    current = head->next;
    while(current != NULL){
        free(current);
        current = current->next;
    }
    return 0;
}
