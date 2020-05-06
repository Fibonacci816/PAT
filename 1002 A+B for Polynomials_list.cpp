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
    int counter = 0;
    List head = NULL;
    List p, pre, current;
	scanf("%d", &K);
	while(K){
        current = (Node *)malloc(sizeof(Node));
        scanf("%d %lf", &current->exponent, &current->coefficient);
        current->next = NULL;
        if(head == NULL){
            head = current;
        }else{
            p->next = current;
        }
	    p = current;
        ++counter;
	    --K;
    }
    p = head;
    scanf("%d", &K);
    int flag = 1;
    while(K){
    	current = (Node *)malloc(sizeof(Node));
        scanf("%d %lf", &current->exponent, &current->coefficient);
        current->next = NULL;
        --K;
        if(flag){
            if(current->exponent > p->exponent){
                current->next = p;
                head = pre = current;
                ++counter;
                flag = 0;
                continue;
            } else if(current->exponent == p->exponent){
                if(current->coefficient+p->coefficient){
                    p->coefficient += current->coefficient;
                }else{
                    free(current);
                    current = p;
                    head = p = p->next;
                    free(current);
                    --counter;
                }
                continue;
            } else {
                pre = head;
                p = pre->next;
                flag = 0;
            }
        }
    	while(p!=NULL && current->exponent<p->exponent){   //输入的指数小于链表的元素指数
    		pre = p;
    		p = p->next;
		}
		if(p==NULL){
            pre->next = current;
            pre = current;
            ++counter;
        }else{
            if(current->exponent>p->exponent){
                current->next = p;
			    pre->next = current;
			    pre = current;
			    ++counter;
            }else{
			    if(current->coefficient+p->coefficient){
                    p->coefficient += current->coefficient;
                }else{
                    pre->next = p->next;
                    free(current);
                    free(p);
                    p =  pre->next;
                    --counter;
                }
		    }
		}
	}
	printf("%d", counter);
	current = head;
	while(current != NULL){
		printf(" %d %0.1lf", current->exponent, current->coefficient);
		current = current->next;
	}
    current = head;
    while(current != NULL){
		free(current);
		current = current->next;
	}
    return 0;
}
