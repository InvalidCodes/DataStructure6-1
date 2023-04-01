#ifndef CHILD_SIBLING_TREE_H_
#define CHILD_SIBLING_TREE_H_

#include "LinkQueue.h"                    // ������
#include "InformationNode.h"              // ������
#include "ChildSiblingTreeNode.h"         // �����ֵܱ�ʾ�������

struct InformationNode;
// �����ֵܱ�ʾ����

class ChildSiblingTree { //��������
protected:
//  �������ݳ�Ա:
    ChildSiblingTreeNode *root;            // ��ָ��

// ������rΪ������
    ChildSiblingTreeNode *CopyTree(ChildSiblingTreeNode *copy);

    // ������
    ChildSiblingTreeNode *CreateTreeGhelp(InformationNode elems[], int parents[], int r, int n);
    // ��������Ԫ��Ϊitems[],��Ӧ���˫��Ϊparents[],�����λ��Ϊr,������Ϊn�������� �����ĸ�
public:
    ChildSiblingTree(InformationNode elems[], int parents[], int n);

//  �����ֵܱ�ʾ���෽��������:
    ChildSiblingTree();                                    // �޲����Ĺ��캯��
    virtual ~ChildSiblingTree();                        // ��������
    ChildSiblingTreeNode *GetRoot() const;                 // �����ĸ�
    bool IsEmpty() const;                                // �ж����Ƿ�Ϊ��
    ChildSiblingTreeNode *FirstChild(ChildSiblingTreeNode *cur) const;//����firstchild
    ChildSiblingTreeNode *NextSibling(ChildSiblingTreeNode *cur) const;//����nextsibling
    ChildSiblingTreeNode *Parent(ChildSiblingTreeNode *r, const ChildSiblingTreeNode *cur) const;

    Status GetName(ChildSiblingTreeNode *cur, string &e) const;//

    int NodeDegree(ChildSiblingTreeNode *cur) const;

    ChildSiblingTreeNode *FindNodeByName(const string &name) const;

    ChildSiblingTreeNode *FindNodeByBirthday(const string &birthday) const;

    Status AddMember(ChildSiblingTreeNode *member, int i);

    Status DeleteChild(ChildSiblingTree tree, ChildSiblingTreeNode *member) const;

//	��������:
    void Destroy(ChildSiblingTreeNode *r);
};

void DisplayTWithConcaveShape(const ChildSiblingTree &t, ChildSiblingTreeNode *r, int level);
// �������ʾ����ʾ����levelΪ�������������Ĳ����Ϊ1

void DisplayTWithConcaveShape(const ChildSiblingTree &t, int h);
// �������ʾ����ʾ��


// �����ֵܱ�ʾ�����ʵ�ֲ���
ChildSiblingTreeNode *ChildSiblingTree::CreateTreeGhelp(InformationNode elems[], int parents[], int r, int n)
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
                if (rt->firstChild == nullptr) {    // subTreeRootΪrt��һ�������ĸ�
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
        return nullptr;                                    // r�Ƿ�����������
}

ChildSiblingTree::ChildSiblingTree(InformationNode elems[], int parents[], int n)
// �����������������Ԫ��Ϊitems[],��Ӧ���˫��Ϊparents[],�����λ��Ϊ0,������Ϊn����
{
    root = CreateTreeGhelp(elems, parents, 0, n);    // �ø�������������
}

ChildSiblingTree::ChildSiblingTree()
// �������������һ������
{
    root = nullptr;                    // ��ʾ��Ϊ��
}

void ChildSiblingTree::Destroy(ChildSiblingTreeNode *r)
// ���������������rΪ������
{
    ChildSiblingTreeNode *p;
    if (r != nullptr) {
        for (p = FirstChild(r); p != nullptr; p = NextSibling(p))
            Destroy(p);        // ��������
        delete r;                // ���ٸ����
        r = nullptr;
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
    return root == nullptr;
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
        for (p = t.FirstChild(r); p != nullptr; p = t.NextSibling(p))
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
    if (cur == nullptr)
        return nullptr;                // �ս���޺���
    else
        return cur->firstChild;        // firstChildΪ��һ������
}

ChildSiblingTreeNode *ChildSiblingTree::NextSibling(ChildSiblingTreeNode *cur) const
// ���������������curΪ�ջ�û����һ���ֵ�,�򷵻�NULL,���򷵻�cur����һ���ֵ�
{
    if (cur == nullptr)
        return nullptr;                // �ս�����ֵ�
    else
        return cur->nextSibling;    // nextSiblingΪ��һ���ֵ�
}

/// @brief �������������rΪ������, ���cur��˫��
ChildSiblingTreeNode *ChildSiblingTree::Parent(ChildSiblingTreeNode *r,
                                               const ChildSiblingTreeNode *cur) const {
    if (r == nullptr) return nullptr;                // �ն�����
    ChildSiblingTreeNode *p;        // ����
    for (p = FirstChild(r); p != nullptr; p = NextSibling(p))
        if (p == cur) return r;                // cur��r�ĺ���

    for (p = FirstChild(r); p != nullptr; p = NextSibling(p)) {
        ChildSiblingTreeNode *q;
        q = Parent(p, cur);                    // ����������cur��˫��
        if (q != nullptr) return q;            // ˫����������
    }
    return nullptr;                            // δ�ҵ�˫��
}

/// @brief ָ����������������������
/// @return ���ָ��
ChildSiblingTreeNode *ChildSiblingTree::FindNodeByName(const string &name) const {
    LinkQueue<ChildSiblingTreeNode *> q;    // ������ж���
    ChildSiblingTreeNode *cur, *p, *result;

    if (root != nullptr) q.EnQueue(root);               // ������ǿ�,������ָ�������
    while (!q.IsEmpty()) {
        q.DelQueue(cur);                           //  ��ͷ������Ϊ��ǰ���cur
        if (cur->name_ == name)
            return result = cur;
        for (p = FirstChild(cur); p != nullptr; p = NextSibling(p))
            q.EnQueue(p);                           // ���ν�cur�ĺ��ӽ��ָ�������
    }
}

/// @brief ָ�����գ��������������
/// @return ���ָ��
ChildSiblingTreeNode *ChildSiblingTree::FindNodeByBirthday(const string &birthday) const {
    LinkQueue<ChildSiblingTreeNode *> queue;    ///< ������ж���
    ChildSiblingTreeNode *cur, *p, *result;

    if (root != nullptr) queue.EnQueue(root);    ///< ������ǿ�,������ָ�������
    while (!queue.IsEmpty()) {
        queue.DelQueue(cur);     ///<  ��ͷ������Ϊ��ǰ���cur
        if (cur->birthday_ == birthday)
            return result = cur;
        for (p = FirstChild(cur); p != nullptr; p = NextSibling(p))
            queue.EnQueue(p);    ///< ���ν�cur�ĺ��ӽ��ָ�������
    }
}

/// @brief ����Ķ�
/// @return int����
int ChildSiblingTree::NodeDegree(ChildSiblingTreeNode *cur) const {
    ChildSiblingTreeNode *p;
    int count = 0;
    for (p = FirstChild(cur); p != nullptr; p = NextSibling(p))
        count++;    ///< �Ժ��Ӹ������м���
    return count;
}

/// @brief ���ӳ�Ա
Status ChildSiblingTree::AddMember(ChildSiblingTreeNode *member, int i) {
    if (member == nullptr) return NOT_PRESENT;
    if (i < 1 || i > NodeDegree(member) + 1) return FAIL;

    cout << "�����������Ա��Ϣ�����������գ���������ַ" << endl;
    cin >> member->name_;
    cin >> member->birthday_;
    cin >> member->marriage_;
    cin >> member->address_;
    cout << "�ó�Ա�Ƿ����� ��1��0��" << endl;
    cin >> member->condition_;
    if (member->condition_ == 0) {
        cout << "�������������ڣ�" << endl;
        cin >> member->death_date;
    } else member->death_date = 0;
    ChildSiblingTreeNode *fChild, *nSibling = nullptr;
    ChildSiblingTreeNode *new_member = new ChildSiblingTreeNode(member->name_,
                                                                member->birthday_,
                                                                member->marriage_,
                                                                member->address_,
                                                                member->condition_,
                                                                member->death_date,
                                                                fChild, nSibling);
    /// �����½��ռ�
    if (i == 1) {
        new_member->nextSibling = member->firstChild;
        member->firstChild = new_member;      // new_member����Ϊmember�ĵ�һ������
    } else {
        ChildSiblingTreeNode *p = FirstChild(member);    // ȡcur�ĺ���
        for (int k = 1; k < i - 1; k++)
            p = NextSibling(p);       // �����λ�õ�ǰһ���ֵ�p
        new_member->nextSibling = p->nextSibling;
        p->nextSibling = new_member;
    }
    cout << "����³�Ա�ɹ�" << endl;
    return SUCCESS;
}

/*
/// @brief ָ�����ƣ�ɾ����Ա
Status ChildSiblingTree::DeleteChild(ChildSiblingTree tree, ChildSiblingTreeNode *member) const {
    ChildSiblingTreeNode *p, *q, *result;
    int count = 0;
    for (p = FirstChild(member); p != nullptr; p = NextSibling(p))   ///< �Ժ��Ӹ������м���
        count++;
    q = FirstChild(member);
    for (int n = 1; n < count - 1; n++)
        q = NextSibling(q);     ///< ����member�ĺ���
    p = q->nextSibling;
    q->nextSibling = p->nextSibling;
    tree.Destroy(p);    ///< ɾ������
    cout << "ɾ���ɹ�" << endl;
    return SUCCESS;
}
*/

#endif
