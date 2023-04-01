#ifndef CHILD_SIBLING_TREE_H_
#define CHILD_SIBLING_TREE_H_

#include "LinkQueue.h"                    // ������
#include "SNode.h"                        // ������
#include "ChildSiblingTreeNode.h"        // �����ֵܱ�ʾ�������

struct SNode;
// �����ֵܱ�ʾ����

class ChildSiblingTree { //��������
protected:
//  �������ݳ�Ա:
    ChildSiblingTreeNode *root;            // ��ָ��

//	��������:
    void Destroy(ChildSiblingTreeNode *&r);        // ������rΪ������
    ChildSiblingTreeNode *CopyTree(ChildSiblingTreeNode *copy);

    // ������
    ChildSiblingTreeNode *CreateTreeGhelp(SNode elems[], int parents[], int r, int n);
    // ��������Ԫ��Ϊitems[],��Ӧ���˫��Ϊparents[],�����λ��Ϊr,������Ϊn�������� �����ĸ�
public:
    ChildSiblingTree(SNode elems[], int parents[], int n);

//  �����ֵܱ�ʾ���෽��������:
    ChildSiblingTree();                                    // �޲����Ĺ��캯��
    virtual ~ChildSiblingTree();                        // ��������
    ChildSiblingTreeNode *GetRoot() const;                 // �����ĸ�
    bool IsEmpty() const;                                // �ж����Ƿ�Ϊ��
    ChildSiblingTreeNode *FirstChild(ChildSiblingTreeNode *cur) const;//����firstchild
    ChildSiblingTreeNode *NextSibling(ChildSiblingTreeNode *cur) const;//����nextsibling
    Status GetName(ChildSiblingTreeNode *cur, string &e) const;//
    ChildSiblingTreeNode *FindNodeByBirthday(ChildSiblingTreeNode *root, string birthday);
    ChildSiblingTreeNode* FindNodeByName(string name) const;
};

void DisplayTWithConcaveShape(const ChildSiblingTree &t, ChildSiblingTreeNode *r, int level);
// �������ʾ����ʾ����levelΪ�������������Ĳ����Ϊ1

void DisplayTWithConcaveShape(const ChildSiblingTree &t, int h);
// �������ʾ����ʾ��


// �����ֵܱ�ʾ�����ʵ�ֲ���

ChildSiblingTreeNode *ChildSiblingTree::CreateTreeGhelp(SNode elems[], int parents[], int r, int n)
// �����������������Ԫ��Ϊitems[],��Ӧ���˫��Ϊparents[],�����λ��Ϊr,������Ϊn���������������ĸ�
{
    if (r >= 0 && r < n) {
        ChildSiblingTreeNode *rt = new ChildSiblingTreeNode(elems[r].name, elems[r].birth,
                                                            elems[r].marriage, elems[r].address, elems[r].condition,
                                                            elems[r].death);    // ���Ƹ����
        ChildSiblingTreeNode *subTreeRoot, *cur;
        for (int i = 0; i < n; i++) {    // ����r�ĺ���
            if (parents[i] == r) {    // ������posΪ��������
                subTreeRoot = CreateTreeGhelp(elems, parents, i, n);
                if (rt->firstChild == NULL) {    // subTreeRootΪrt��һ�������ĸ�
                    rt->firstChild = subTreeRoot;
                    cur = subTreeRoot;            // cur���¸��Ƶ������ĸ�
                } else {                // subTreeRootΪcur����һ���ֵ�
                    cur->nextSibling = subTreeRoot;
                    cur = subTreeRoot;
                }
            }
        }
        return rt;
    } else
        return NULL;                                    // r�Ƿ�����������
}

ChildSiblingTree::ChildSiblingTree(SNode elems[], int parents[], int n)
// �����������������Ԫ��Ϊitems[],��Ӧ���˫��Ϊparents[],�����λ��Ϊ0,������Ϊn����
{
    root = CreateTreeGhelp(elems, parents, 0, n);    // �ø�������������
}

ChildSiblingTree::ChildSiblingTree()
// �������������һ������
{
    root = NULL;                    // ��ʾ��Ϊ��
}

void ChildSiblingTree::Destroy(ChildSiblingTreeNode *&r)
// ���������������rΪ������
{
    ChildSiblingTreeNode *p;
    if (r != NULL) {
        for (p = FirstChild(r); p != NULL; p = NextSibling(p))
            Destroy(p);        // ��������
        delete r;                // ���ٸ����
        r = NULL;
    }
}

ChildSiblingTree::~ChildSiblingTree()
// ���������������--���캯��
{
    Destroy(root);
}

ChildSiblingTreeNode *ChildSiblingTree::GetRoot() const
// ��������� �����ĸ�
{
    return root;
}


bool ChildSiblingTree::IsEmpty() const
// ����������ж����Ƿ�Ϊ��
{
    return root == NULL;
}


Status ChildSiblingTree::GetName(ChildSiblingTreeNode *cur, string &e) const
// �����������e����cur����,��������ڽ��cur,���� ��NOT_PRESENT,���� ��ENTRY_FOUND
{
    if (cur == NULL)
        return NOT_PRESENT;
    else {
        e = cur->name_;            // ��e ��Ԫ��ֵ
        return ENTRY_FOUND;        //  ��ENTRY_FOUND
    }
}

void DisplayTWithConcaveShape(const ChildSiblingTree &t,
                              ChildSiblingTreeNode *r, int level)
// ����������������ʾ����ʾ����levelΪ�������������Ĳ����Ϊ1
{
    ChildSiblingTreeNode *p;
    if (r != NULL) {
        cout << endl;                                    //��ʾ����
        for (int i = 0; i < level - 1; i++)
            cout << " ";                                //ȷ���ڵ�level����ʾ���
        string e;
        t.GetName(r, e);                            // ȡ�����r������
        cout << e;                                    // ��ʾ���Ԫ��ֵ
        for (p = t.FirstChild(r); p != NULL; p = t.NextSibling(p))
            DisplayTWithConcaveShape(t, p, level + 1);// ������ʾ��������
    }
}

void DisplayTWithConcaveShape(const ChildSiblingTree &t)
// ����������������ʾ����ʾ��
{
    DisplayTWithConcaveShape(t, t.GetRoot(), 1);// ���ø�������ʵ�ְ������ʾ����ʾ��
    cout << endl;                                    // ����
}

ChildSiblingTreeNode *ChildSiblingTree::FirstChild(ChildSiblingTreeNode *cur) const
// �����������cur�޺���,�򷵻�NULL,���򷵻������cur�ĵ�һ������,
{
    if (cur == NULL)
        return NULL;                // �ս���޺���
    else
        return cur->firstChild;        // firstChildΪ��һ������
}

ChildSiblingTreeNode *ChildSiblingTree::NextSibling(ChildSiblingTreeNode *cur) const
// ���������������curΪ�ջ�û����һ���ֵ�,�򷵻�NULL,���򷵻�cur����һ���ֵ�
{
    if (cur == NULL)
        return NULL;                // �ս�����ֵ�
    else
        return cur->nextSibling;    // nextSiblingΪ��һ���ֵ�
}

/// @brief ָ����������������������
/// @return ���ָ��
ChildSiblingTreeNode* ChildSiblingTree::FindNodeByName(string name) const
// �����������α�����
{
    LinkQueue<ChildSiblingTreeNode *> q;	// ������ж���
    ChildSiblingTreeNode *cur, *p, *result;

    if (root != NULL) q.EnQueue(root);			   // ������ǿ�,������ָ�������
    while (!q.IsEmpty())	{
        q.DelQueue(cur);						   //  ��ͷ������Ϊ��ǰ���cur
        if(cur->name_==name)
            return result = cur;
        for (p = FirstChild(cur); p != NULL;  p = NextSibling(p))
            q.EnQueue(p);					       // ���ν�cur�ĺ��ӽ��ָ�������
    }
}

/// @brief ָ�����գ��������������
/// @return ���ָ��
ChildSiblingTreeNode *ChildSiblingTree::FindNodeByBirthday(ChildSiblingTreeNode *root, string birthday) {
    return nullptr;
}

#endif
