#ifndef __CHILD_SIBLING_FOREST_NODE_H__
#define __CHILD_SIBLING_FOREST_NODE_H__

#include <string>

using namespace std;

// 孩子兄弟表示树结点类
struct ChildSiblingTreeNode { //定义家庭成员信息
// 数据成员:
    char name_[100];                                // 姓名
    string birthday_;                               // 生日
    int marriage_;                               // 婚姻状况（0：未婚，1：已婚，2：离异，3：丧偶）
    string address_;                             // 住址
    int condition_;                              // 目前状况（0：健在，1：亡故）
    int death_date;                                  // 死亡日期
    ChildSiblingTreeNode *firstChild;    // 指向首孩子指针域
    ChildSiblingTreeNode *nextSibling;// 指向右兄弟指针域

// 构造函数:
    ChildSiblingTreeNode();                        // 无参数的构造函数
    ChildSiblingTreeNode(string m_name, string m_birth, int m_marriage,
                         string m_address, int m_condition, int m_death,            // 有参数的构造函数
                         ChildSiblingTreeNode *fChild = NULL,
                         ChildSiblingTreeNode *nSibling = NULL);

};

// 孩子兄弟表示树结点类的实现部分
ChildSiblingTreeNode::ChildSiblingTreeNode()
// 操作结果：构造指针域为空的结点
{
    firstChild = nextSibling = NULL;
}

ChildSiblingTreeNode::ChildSiblingTreeNode(string m_name, string m_birth, int m_marriage,
                                           string m_address, int m_condition, int m_death,
                                           ChildSiblingTreeNode *fChild, ChildSiblingTreeNode *nSibling)
// 操作结果：构造一个数据域为val、首孩子为fChild、下一兄弟为nChild的结点
{
    for (auto i = 0; i < 100; i++)
        m_name.push_back(name_[i]);
    //name_ = m_name;
    birthday_ = m_birth;
    marriage_ = m_marriage;
    address_ = m_address;
    condition_ = m_condition;
    death_date = m_death;
    firstChild = fChild;
    nextSibling = nSibling;
}

#endif
