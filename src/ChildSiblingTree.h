#ifndef CHILD_SIBLING_TREE_H_
#define CHILD_SIBLING_TREE_H_

#include "LinkQueue.h"                    // 链队列
#include "SNode.h"                        // 数组结点
#include "ChildSiblingTreeNode.h"        // 孩子兄弟表示树结点类

struct SNode;
// 孩子兄弟表示树类

class ChildSiblingTree { //家谱树类
protected:
//  树的数据成员:
    ChildSiblingTreeNode *root;            // 根指针

//	辅助函数:
    void Destroy(ChildSiblingTreeNode *&r);        // 销毁以r为根的树
    ChildSiblingTreeNode *CopyTree(ChildSiblingTreeNode *copy);

    // 复制树
    ChildSiblingTreeNode *CreateTreeGhelp(SNode elems[], int parents[], int r, int n);
    // 建立数据元素为items[],对应结点双亲为parents[],根结点位置为r,结点个数为n的树，并 求树的根
public:
    ChildSiblingTree(SNode elems[], int parents[], int n);

//  孩子兄弟表示树类方法的声明:
    ChildSiblingTree();                                    // 无参数的构造函数
    virtual ~ChildSiblingTree();                        // 析构函数
    ChildSiblingTreeNode *GetRoot() const;                 // 求树的根
    bool IsEmpty() const;                                // 判断树是否为空
    ChildSiblingTreeNode *FirstChild(ChildSiblingTreeNode *cur) const;//返回firstchild
    ChildSiblingTreeNode *NextSibling(ChildSiblingTreeNode *cur) const;//返回nextsibling
    Status GetName(ChildSiblingTreeNode *cur, string &e) const;//
    ChildSiblingTreeNode *FindNodeByBirthday(ChildSiblingTreeNode *root, string birthday);
    ChildSiblingTreeNode* FindNodeByName(string name) const;
};

void DisplayTWithConcaveShape(const ChildSiblingTree &t, ChildSiblingTreeNode *r, int level);
// 按凹入表示法显示树，level为层次数，设根结点的层次数为1

void DisplayTWithConcaveShape(const ChildSiblingTree &t, int h);
// 按凹入表示法显示树


// 孩子兄弟表示树类的实现部分

ChildSiblingTreeNode *ChildSiblingTree::CreateTreeGhelp(SNode elems[], int parents[], int r, int n)
// 操作结果：建立数据元素为items[],对应结点双亲为parents[],根结点位置为r,结点个数为n的树，并返回树的根
{
    if (r >= 0 && r < n) {
        ChildSiblingTreeNode *rt = new ChildSiblingTreeNode(elems[r].name, elems[r].birth,
                                                            elems[r].marriage, elems[r].address, elems[r].condition,
                                                            elems[r].death);    // 复制根结点
        ChildSiblingTreeNode *subTreeRoot, *cur;
        for (int i = 0; i < n; i++) {    // 查找r的孩子
            if (parents[i] == r) {    // 建立以pos为根的子树
                subTreeRoot = CreateTreeGhelp(elems, parents, i, n);
                if (rt->firstChild == NULL) {    // subTreeRoot为rt第一棵子树的根
                    rt->firstChild = subTreeRoot;
                    cur = subTreeRoot;            // cur最新复制的子树的根
                } else {                // subTreeRoot为cur的下一个兄弟
                    cur->nextSibling = subTreeRoot;
                    cur = subTreeRoot;
                }
            }
        }
        return rt;
    } else
        return NULL;                                    // r非法，建立空树
}

ChildSiblingTree::ChildSiblingTree(SNode elems[], int parents[], int n)
// 操作结果：建立数据元素为items[],对应结点双亲为parents[],根结点位置为0,结点个数为n的树
{
    root = CreateTreeGhelp(elems, parents, 0, n);    // 用辅助函数建立树
}

ChildSiblingTree::ChildSiblingTree()
// 操作结果：构造一个空树
{
    root = NULL;                    // 表示树为空
}

void ChildSiblingTree::Destroy(ChildSiblingTreeNode *&r)
// 操作结果：销毁以r为根的树
{
    ChildSiblingTreeNode *p;
    if (r != NULL) {
        for (p = FirstChild(r); p != NULL; p = NextSibling(p))
            Destroy(p);        // 销毁子树
        delete r;                // 销毁根结点
        r = NULL;
    }
}

ChildSiblingTree::~ChildSiblingTree()
// 操作结果：销毁树--析造函数
{
    Destroy(root);
}

ChildSiblingTreeNode *ChildSiblingTree::GetRoot() const
// 操作结果： 求树的根
{
    return root;
}


bool ChildSiblingTree::IsEmpty() const
// 操作结果：判断树是否为空
{
    return root == NULL;
}


Status ChildSiblingTree::GetName(ChildSiblingTreeNode *cur, string &e) const
// 操作结果：用e求结点cur名字,如果不存在结点cur,函数 求NOT_PRESENT,否则 求ENTRY_FOUND
{
    if (cur == NULL)
        return NOT_PRESENT;
    else {
        e = cur->name_;            // 用e 求元素值
        return ENTRY_FOUND;        //  求ENTRY_FOUND
    }
}

void DisplayTWithConcaveShape(const ChildSiblingTree &t,
                              ChildSiblingTreeNode *r, int level)
// 操作结果：按凹入表示法显示树，level为层次数，设根结点的层次数为1
{
    ChildSiblingTreeNode *p;
    if (r != NULL) {
        cout << endl;                                    //显示新行
        for (int i = 0; i < level - 1; i++)
            cout << " ";                                //确保在第level列显示结点
        string e;
        t.GetName(r, e);                            // 取出结点r的名字
        cout << e;                                    // 显示结点元素值
        for (p = t.FirstChild(r); p != NULL; p = t.NextSibling(p))
            DisplayTWithConcaveShape(t, p, level + 1);// 依次显示各棵子树
    }
}

void DisplayTWithConcaveShape(const ChildSiblingTree &t)
// 操作结果：按凹入表示法显示树
{
    DisplayTWithConcaveShape(t, t.GetRoot(), 1);// 调用辅助函数实现按凹入表示法显示树
    cout << endl;                                    // 换行
}

ChildSiblingTreeNode *ChildSiblingTree::FirstChild(ChildSiblingTreeNode *cur) const
// 操作结果：如cur无孩子,则返回NULL,否则返回树结点cur的第一个孩子,
{
    if (cur == NULL)
        return NULL;                // 空结点无孩子
    else
        return cur->firstChild;        // firstChild为第一个孩子
}

ChildSiblingTreeNode *ChildSiblingTree::NextSibling(ChildSiblingTreeNode *cur) const
// 操作结果：如果结点cur为空或没有下一个兄弟,则返回NULL,否则返回cur的下一个兄弟
{
    if (cur == NULL)
        return NULL;                // 空结点右兄弟
    else
        return cur->nextSibling;    // nextSibling为下一个兄弟
}

/// @brief 指定结点名，遍历查找树结点
/// @return 结点指针
ChildSiblingTreeNode* ChildSiblingTree::FindNodeByName(string name) const
// 操作结果：层次遍历树
{
    LinkQueue<ChildSiblingTreeNode *> q;	// 定义队列对象
    ChildSiblingTreeNode *cur, *p, *result;

    if (root != NULL) q.EnQueue(root);			   // 如果根非空,则根结点指针入队列
    while (!q.IsEmpty())	{
        q.DelQueue(cur);						   //  队头结点出队为当前结点cur
        if(cur->name_==name)
            return result = cur;
        for (p = FirstChild(cur); p != NULL;  p = NextSibling(p))
            q.EnQueue(p);					       // 依次将cur的孩子结点指针入队列
    }
}

/// @brief 指定生日，遍历查找树结点
/// @return 结点指针
ChildSiblingTreeNode *ChildSiblingTree::FindNodeByBirthday(ChildSiblingTreeNode *root, string birthday) {
    return nullptr;
}

#endif
