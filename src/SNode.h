#ifndef __SNODE_H__
#define __SNODE_H__
#include <iostream>
using namespace std;

// 结点类
struct SNode {
// 数据成员:
	string name;								// 姓名
	string birth;                               // 生日
	int marriage;                               // 婚姻状况（0：未婚，1：已婚，2：离异，3：丧偶）
	string address;                             // 住址
	int condition;                              // 目前状况（0：健在，1：亡故）
	int death;                                  // 死亡日期
}p[19];
#endif
