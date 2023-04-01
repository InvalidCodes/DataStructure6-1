#ifndef CHILD_SIBLING_TREE_H_
#define CHILD_SIBLING_TREE_H_

#include "LinkQueue.h"                    // 链队列
#include "InformationNode.h"              // 数组结点
#include "ChildSiblingTreeNode.h"         // 孩子兄弟表示树结点类

struct InformationNode;
// 孩子兄弟表示树类

class ChildSiblingTree { //家谱树类
protected:
//  树的数据成员:
    ChildSiblingTreeNode *root;            // 根指针

// 销毁以r为根的树
    ChildSiblingTreeNode *CopyTree(ChildSiblingTreeNode *copy);

    // 复制树
    ChildSiblingTreeNode *CreateTreeGhelp(InformationNode elems[], int parents[], int r, int n);
    // 建立数据元素为items[],对应结点双亲为parents[],根结点位置为r,结点个数为n的树，并 求树的根
public:
    ChildSiblingTree(InformationNode elems[], int parents[], int n);

//  孩子兄弟表示树类方法的声明:
    ChildSiblingTree();                                    // 无参数的构造函数
    virtual ~ChildSiblingTree();                        // 析构函数
    ChildSiblingTreeNode *GetRoot() const;                 // 求树的根
    bool IsEmpty() const;                                // 判断树是否为空
    ChildSiblingTreeNode *FirstChild(ChildSiblingTreeNode *cur) const;//返回firstchild
    ChildSiblingTreeNode *NextSibling(ChildSiblingTreeNode *cur) const;//返回nextsibling
    ChildSiblingTreeNode *Parent(ChildSiblingTreeNode *r, const ChildSiblingTreeNode *cur) const;

    Status GetName(ChildSiblingTreeNode *cur, string &e) const;//

    int NodeDegree(ChildSiblingTreeNode *cur) const;

    ChildSiblingTreeNode *FindNodeByName(const string &name) const;

    ChildSiblingTreeNode *FindNodeByBirthday(const string &birthday) const;

    Status AddMember(ChildSiblingTreeNode *member, int i);

    Status DeleteChild(ChildSiblingTree tree, ChildSiblingTreeNode *member) const;

//	辅助函数:
    void Destroy(ChildSiblingTreeNode *r);
};

void DisplayTWithConcaveShape(const ChildSiblingTree &t, ChildSiblingTreeNode *r, int level);
// 按凹入表示法显示树，level为层次数，设根结点的层次数为1

void DisplayTWithConcaveShape(const ChildSiblingTree &t, int h);
// 按凹入表示法显示树


// 孩子兄弟表示树类的实现部分
ChildSiblingTreeNode *ChildSiblingTree::CreateTreeGhelp(InformationNode elems[], int parents[], int r, int n)
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
                if (rt->firstChild == nullptr) {    // subTreeRoot为rt第一棵子树的根
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
        return nullptr;                                    // r非法，建立空树
}

ChildSiblingTree::ChildSiblingTree(InformationNode elems[], int parents[], int n)
// 操作结果：建立数据元素为items[],对应结点双亲为parents[],根结点位置为0,结点个数为n的树
{
    root = CreateTreeGhelp(elems, parents, 0, n);    // 用辅助函数建立树
}

ChildSiblingTree::ChildSiblingTree()
// 操作结果：构造一个空树
{
    root = nullptr;                    // 表示树为空
}

void ChildSiblingTree::Destroy(ChildSiblingTreeNode *r)
// 操作结果：销毁以r为根的树
{
    ChildSiblingTreeNode *p;
    if (r != nullptr) {
        for (p = FirstChild(r); p != nullptr; p = NextSibling(p))
            Destroy(p);        // 销毁子树
        delete r;                // 销毁根结点
        r = nullptr;
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
    return root == nullptr;
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
        for (p = t.FirstChild(r); p != nullptr; p = t.NextSibling(p))
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
    if (cur == nullptr)
        return nullptr;                // 空结点无孩子
    else
        return cur->firstChild;        // firstChild为第一个孩子
}

ChildSiblingTreeNode *ChildSiblingTree::NextSibling(ChildSiblingTreeNode *cur) const
// 操作结果：如果结点cur为空或没有下一个兄弟,则返回NULL,否则返回cur的下一个兄弟
{
    if (cur == nullptr)
        return nullptr;                // 空结点右兄弟
    else
        return cur->nextSibling;    // nextSibling为下一个兄弟
}

/// @brief 操作结果：求以r为根的树, 结点cur的双亲
ChildSiblingTreeNode *ChildSiblingTree::Parent(ChildSiblingTreeNode *r,
                                               const ChildSiblingTreeNode *cur) const {
    if (r == nullptr) return nullptr;                // 空二叉树
    ChildSiblingTreeNode *p;        // 孩子
    for (p = FirstChild(r); p != nullptr; p = NextSibling(p))
        if (p == cur) return r;                // cur是r的孩子

    for (p = FirstChild(r); p != nullptr; p = NextSibling(p)) {
        ChildSiblingTreeNode *q;
        q = Parent(p, cur);                    // 在子树上求cur的双亲
        if (q != nullptr) return q;            // 双亲在子树上
    }
    return nullptr;                            // 未找到双亲
}

/// @brief 指定结点名，遍历查找树结点
/// @return 结点指针
ChildSiblingTreeNode *ChildSiblingTree::FindNodeByName(const string &name) const {
    LinkQueue<ChildSiblingTreeNode *> q;    // 定义队列对象
    ChildSiblingTreeNode *cur, *p, *result;

    if (root != nullptr) q.EnQueue(root);               // 如果根非空,则根结点指针入队列
    while (!q.IsEmpty()) {
        q.DelQueue(cur);                           //  队头结点出队为当前结点cur
        if (cur->name_ == name)
            return result = cur;
        for (p = FirstChild(cur); p != nullptr; p = NextSibling(p))
            q.EnQueue(p);                           // 依次将cur的孩子结点指针入队列
    }
}

/// @brief 指定生日，遍历查找树结点
/// @return 结点指针
ChildSiblingTreeNode *ChildSiblingTree::FindNodeByBirthday(const string &birthday) const {
    LinkQueue<ChildSiblingTreeNode *> queue;    ///< 定义队列对象
    ChildSiblingTreeNode *cur, *p, *result;

    if (root != nullptr) queue.EnQueue(root);    ///< 如果根非空,则根结点指针入队列
    while (!queue.IsEmpty()) {
        queue.DelQueue(cur);     ///<  队头结点出队为当前结点cur
        if (cur->birthday_ == birthday)
            return result = cur;
        for (p = FirstChild(cur); p != nullptr; p = NextSibling(p))
            queue.EnQueue(p);    ///< 依次将cur的孩子结点指针入队列
    }
}

/// @brief 求结点的度
/// @return int度数
int ChildSiblingTree::NodeDegree(ChildSiblingTreeNode *cur) const {
    ChildSiblingTreeNode *p;
    int count = 0;
    for (p = FirstChild(cur); p != nullptr; p = NextSibling(p))
        count++;    ///< 对孩子个数进行计数
    return count;
}

/// @brief 增加成员
Status ChildSiblingTree::AddMember(ChildSiblingTreeNode *member, int i) {
    if (member == nullptr) return NOT_PRESENT;
    if (i < 1 || i > NodeDegree(member) + 1) return FAIL;

    cout << "请输入基本成员信息：姓名，生日，婚姻，地址" << endl;
    cin >> member->name_;
    cin >> member->birthday_;
    cin >> member->marriage_;
    cin >> member->address_;
    cout << "该成员是否生者 （1是0否）" << endl;
    cin >> member->condition_;
    if (member->condition_ == 0) {
        cout << "请输入死亡日期：" << endl;
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
    /// 申请新结点空间
    if (i == 1) {
        new_member->nextSibling = member->firstChild;
        member->firstChild = new_member;      // new_member插入为member的第一个孩子
    } else {
        ChildSiblingTreeNode *p = FirstChild(member);    // 取cur的孩子
        for (int k = 1; k < i - 1; k++)
            p = NextSibling(p);       // 求插入位置的前一个兄弟p
        new_member->nextSibling = p->nextSibling;
        p->nextSibling = new_member;
    }
    cout << "添加新成员成功" << endl;
    return SUCCESS;
}

/*
/// @brief 指定名称，删除成员
Status ChildSiblingTree::DeleteChild(ChildSiblingTree tree, ChildSiblingTreeNode *member) const {
    ChildSiblingTreeNode *p, *q, *result;
    int count = 0;
    for (p = FirstChild(member); p != nullptr; p = NextSibling(p))   ///< 对孩子个数进行计数
        count++;
    q = FirstChild(member);
    for (int n = 1; n < count - 1; n++)
        q = NextSibling(q);     ///< 查找member的孩子
    p = q->nextSibling;
    q->nextSibling = p->nextSibling;
    tree.Destroy(p);    ///< 删除子树
    cout << "删除成功" << endl;
    return SUCCESS;
}
*/

#endif
