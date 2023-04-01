/// @brief Genealogy tree functions.
/// @author Created by Ge on 2023/4/1.

#ifndef INC_6_2_2_GENEALOGY_H
#define INC_6_2_2_GENEALOGY_H

#include "ChildSiblingTree.h"

void Menu(){
    cout << "          *******家谱管理功能目录*******         " << endl;
    cout << "          ------------------------------         " << endl;
    cout << "                  0. 退出系统                    " << endl;
    cout << "                  1.打印家谱树                   " << endl;
    cout << "               2.显示一代人姓名和人数            " << endl;
    cout << "                3.按姓名查询成员信息             " << endl;
    cout << "               4.按生日查找家谱成员              " << endl;
    cout << "               5.根据姓名确定关系                " << endl;
    cout << "                   6.添加孩子                    " << endl;
    cout << "                   7.删除成员                    " << endl;
    cout << "                 8.修改成员信息                  " << endl;
    cout << "         -------------------------------         " << endl;
    cout << "请输入你的操作(0~9):" << endl;
}

/*ChildSiblingTreeNode *SearchMemberByName(ChildSiblingTreeNode *member, const char *name) {
    if (member == nullptr) return nullptr;
    if (std::strcmp(member->name_, name) == 0)
        return member;
    if (member->firstChild == nullptr) return nullptr;
    ChildSiblingTreeNode *iteration = SearchMemberByName(member->firstChild, name);
    if (iteration != nullptr)
        return iteration;
    return SearchMemberByName(member->nextSibling, name);
}*/

Status PrintInformation(ChildSiblingTreeNode *member, const char *name) {
    ChildSiblingTreeNode *p = SearchMemberByName(member, name);
    cout << "成员信息：" << endl;
    cout << "姓名：" << member->name_ << endl;
    cout << "地址：" << member->address_ << endl;
    cout << "生日：" << member->birthday_ << endl;
    cout << "生存状况：" << member->condition_ << endl;
    cout << "是否已婚：" << member->marriage_ << endl;
    cout << "死亡时间：" << member->death_date << endl;
}



#endif //INC_6_2_2_GENEALOGY_H
