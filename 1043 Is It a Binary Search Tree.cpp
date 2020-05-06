#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

typedef struct TNode{
    int value;
    struct TNode * left, * right;
} TNode;

vector<int> oriSequence, preSequence, mirPreSequence, postSequence;

void CreateBST(TNode * &root, int value)
{
    if(root == NULL){
        root = (TNode *)malloc(sizeof(TNode));
        root->value = value;
        root->left = NULL;
        root->right = NULL;
        return;
    }
    if(value < root->value){
        CreateBST(root->left, value);
    } else {
        CreateBST(root->right, value);
    }
}

void Mirror(TNode * root)
{
    if(root == NULL){
        return;
    }
    Mirror(root->left);
    Mirror(root->right);
    TNode * temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void PreTravel(TNode * root)
{
    if(root == NULL){
        return;
    }
    preSequence.push_back(root->value);
    PreTravel(root->left);
    PreTravel(root->right);
}

void MirrorPreTravel(TNode * root)
{
    if(root == NULL){
        return;
    }
    mirPreSequence.push_back(root->value);
    MirrorPreTravel(root->right);
    MirrorPreTravel(root->left);
}

void PostTravel(TNode * root)
{
    if(root == NULL){
        return;
    }
    PostTravel(root->left);
    PostTravel(root->right);
    postSequence.push_back(root->value);
}

void MirrorPostTravel(TNode * root)
{
    if(root == NULL){
        return;
    }
    MirrorPostTravel(root->right);
    MirrorPostTravel(root->left);
    postSequence.push_back(root->value);
}

int main()
{
    int N, value;
    TNode * root = NULL;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &value);
        oriSequence.push_back(value);
        CreateBST(root, value);
    }
    PreTravel(root);
    MirrorPreTravel(root);
    if(preSequence == oriSequence || mirPreSequence == oriSequence){
        printf("YES\n");
        if(preSequence == oriSequence){
            PostTravel(root);
        } else {
            //Mirror(root);
            //PostTravel(root);
            MirrorPostTravel(root);
        }
        for(int i = 0; i < postSequence.size(); i++){
            printf("%d", postSequence[i]);
            if(i != postSequence.size()-1){
                printf(" ");
            }
        }
    } else {
        printf("NO");
    }
    return 0;
}
