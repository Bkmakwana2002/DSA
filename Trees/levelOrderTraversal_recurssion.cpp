#include <bits/stdc++.h>
using namespace std;

struct treeNode
{
    int data;
    treeNode *left;
    treeNode *right;
    treeNode(int val)
    {
        data =val;
        treeNode *left =NULL;
        treeNode *right =NULL;
    }
};

int main()
{
    treeNode *root = new treeNode(1);
    return 0;
}