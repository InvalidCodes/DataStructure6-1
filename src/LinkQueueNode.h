#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>
using namespace std;

// 结点类
template <class ElemType>
struct LinkQueueNode
{
// 数据成员:
	ElemType data;				// 数据域
	LinkQueueNode<ElemType> *next;		// 指针域

// 构造函数:
	LinkQueueNode();						// 无参数的构造函数
	LinkQueueNode(ElemType item, LinkQueueNode<ElemType> *link = NULL);	// 已知数数据元素值和指针建立结构
};

// 结点类的实现部分
template<class ElemType>
LinkQueueNode<ElemType>::LinkQueueNode()
// 操作结果：构造指针域为空的结点
{
   next = NULL;
}

template<class ElemType>
LinkQueueNode<ElemType>::LinkQueueNode(ElemType item, LinkQueueNode<ElemType> *link)
// 操作结果：构造一个数据域为item和指针域为link的结点
{
   data = item;
   next = link;
}

#endif
