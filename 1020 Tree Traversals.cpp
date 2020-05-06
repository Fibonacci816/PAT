#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;
typedef struct NodeS{
    int value;
    struct NodeS * lchild, * rchild;
} Node; //二叉树节点
Node * Create(int * postOrderSequences, int * inOrderSequences, int n); //由后序和中序遍历序列建立一棵二叉树返回其根节点
void LevelTravel(Node * root); //二叉树的层序遍历
void PrintPreOrderSequences(int postOrderSequences[], int inOrderSequences[], int n); //由后序和中序遍历序列输出其前序遍历序列
int flag = 1;
int main()
{
    Node * root;
    int N;
    scanf("%d", &N);
    int postOrderSequences[N];
    int inOrderSequences[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &postOrderSequences[i]);
    }
    for(int i = 0; i < N; i++){
        scanf("%d", &inOrderSequences[i]);
    }
    //PrintPreOrderSequences(postOrderSequences, inOrderSequences, N);
    root = Create(postOrderSequences, inOrderSequences, N);
    LevelTravel(root);
    return 0;
}
void PrintPreOrderSequences(int postOrderSequences[], int inOrderSequences[], int n)
{
    int root = postOrderSequences[n-1];
    printf("%d", root);
    int index;
    for(index = 0; index < n; index++){
        if(inOrderSequences[index] == root){
            break;
        }
    }
    int subPostOrderSequences1[index];
    int subPostOrderSequences2[n - index - 1];
    for(int i = 0; i < index; i++){
        subPostOrderSequences1[i] = postOrderSequences[i];
    }
    for(int i = 0; i < n - 1 - index; i++){
        subPostOrderSequences2[i] = postOrderSequences[i + index];
    }
    int subInOrderSequences1[index];
    int subInOrderSequences2[n - index - 1];
    for(int i = 0; i < index; i++){
        subInOrderSequences1[i] = inOrderSequences[i];
    }
    for(int i = 0; i < n - 1 - index; i++){
        subInOrderSequences2[i] = inOrderSequences[i + index + 1];
    }
    if(index > 0){
        PrintPreOrderSequences(subPostOrderSequences1, subInOrderSequences1, index);
    }
    if(n - index - 1 > 0){
        PrintPreOrderSequences(subPostOrderSequences2, subInOrderSequences2, n - index - 1);
    }
}
Node * Create(int * postOrderSequences, int * inOrderSequences, int n)
{
    if(n == 0){
        return NULL;
    }
    Node * root;
    root = (Node *)malloc(sizeof(Node));
    root->value = postOrderSequences[n - 1];
    int index;
    //在中序序列中寻找分界点（根节点）
    for(index = 0; index < n; index++){
        if(inOrderSequences[index] == root->value){
            break;
        }
    }
    root->lchild = Create(postOrderSequences, inOrderSequences, index);
    root->rchild = Create(postOrderSequences + index, inOrderSequences + index + 1, n - index - 1);
    return root;
}
void LevelTravel(Node * root)
{
    Node * p;
    queue<Node *> que;
    que.push(root);
    while(!que.empty()){
        p = que.front();
        if(flag){
            printf("%d", p->value);
            flag = 0;
        } else {
            printf(" %d", p->value);
        }
        que.pop();
        if(p->lchild){
            que.push(p->lchild);
        }
        if(p->rchild){
            que.push(p->rchild);
        }
    }
}
