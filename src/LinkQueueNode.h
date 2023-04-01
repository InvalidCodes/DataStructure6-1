#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>
using namespace std;

// �����
template <class ElemType>
struct LinkQueueNode
{
// ���ݳ�Ա:
	ElemType data;				// ������
	LinkQueueNode<ElemType> *next;		// ָ����

// ���캯��:
	LinkQueueNode();						// �޲����Ĺ��캯��
	LinkQueueNode(ElemType item, LinkQueueNode<ElemType> *link = NULL);	// ��֪������Ԫ��ֵ��ָ�뽨���ṹ
};

// ������ʵ�ֲ���
template<class ElemType>
LinkQueueNode<ElemType>::LinkQueueNode()
// �������������ָ����Ϊ�յĽ��
{
   next = NULL;
}

template<class ElemType>
LinkQueueNode<ElemType>::LinkQueueNode(ElemType item, LinkQueueNode<ElemType> *link)
// �������������һ��������Ϊitem��ָ����Ϊlink�Ľ��
{
   data = item;
   next = link;
}

#endif
