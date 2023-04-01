#ifndef __CHILD_SIBLING_FOREST_NODE_H__
#define __CHILD_SIBLING_FOREST_NODE_H__

#include <string>

using namespace std;

// �����ֵܱ�ʾ�������
struct ChildSiblingTreeNode { //�����ͥ��Ա��Ϣ
// ���ݳ�Ա:
    char name_[100];                                // ����
    string birthday_;                               // ����
    int marriage_;                               // ����״����0��δ�飬1���ѻ飬2�����죬3��ɥż��
    string address_;                             // סַ
    int condition_;                              // Ŀǰ״����0�����ڣ�1�����ʣ�
    int death_date;                                  // ��������
    ChildSiblingTreeNode *firstChild;    // ָ���׺���ָ����
    ChildSiblingTreeNode *nextSibling;// ָ�����ֵ�ָ����

// ���캯��:
    ChildSiblingTreeNode();                        // �޲����Ĺ��캯��
    ChildSiblingTreeNode(string m_name, string m_birth, int m_marriage,
                         string m_address, int m_condition, int m_death,            // �в����Ĺ��캯��
                         ChildSiblingTreeNode *fChild = NULL,
                         ChildSiblingTreeNode *nSibling = NULL);

};

// �����ֵܱ�ʾ��������ʵ�ֲ���
ChildSiblingTreeNode::ChildSiblingTreeNode()
// �������������ָ����Ϊ�յĽ��
{
    firstChild = nextSibling = NULL;
}

ChildSiblingTreeNode::ChildSiblingTreeNode(string m_name, string m_birth, int m_marriage,
                                           string m_address, int m_condition, int m_death,
                                           ChildSiblingTreeNode *fChild, ChildSiblingTreeNode *nSibling)
// �������������һ��������Ϊval���׺���ΪfChild����һ�ֵ�ΪnChild�Ľ��
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
