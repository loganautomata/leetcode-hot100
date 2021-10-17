struct DListNode
{
    int val;
    DListNode *pre;
    DListNode *next;
    DListNode(int k, int v) :val(v), pre(nullptr), next(nullptr){};
};
