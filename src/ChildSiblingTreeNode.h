#ifndef __CHILD_SIBLING_FOREST_NODE_H__
#define __CHILD_SIBLING_FOREST_NODE_H__
#include <string>
using namespace std;

// �����ֵܱ�ʾ�������
struct ChildSiblingTreeNode { //�����ͥ��Ա��Ϣ
// ���ݳ�Ա:
	string name;								// ����
	string birth;                               // ����
	int marriage;                               // ����״����0��δ�飬1���ѻ飬2�����죬3��ɥż��
	string address;                             // סַ
	int condition;                              // Ŀǰ״����0�����ڣ�1�����ʣ�
	int death;                                  // ��������
	ChildSiblingTreeNode *firstChild;	// ָ���׺���ָ����
	ChildSiblingTreeNode *nextSibling;// ָ�����ֵ�ָ����

// ���캯��:
	ChildSiblingTreeNode();						// �޲����Ĺ��캯��
	ChildSiblingTreeNode(string m_name, string m_birth, int m_marriage,
	                     string m_address, int m_condition, int m_death,			// �в����Ĺ��캯��
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
	name = m_name;
	birth = m_birth;
	marriage = m_marriage;
	address = m_address;
	condition = m_condition;
	death = m_death;
	firstChild = fChild;
	nextSibling = nSibling;
}

#endif
