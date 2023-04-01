/// @brief Genealogy tree functions.
/// @author Created by Ge on 2023/4/1.

#ifndef INC_6_2_2_GENEALOGY_H
#define INC_6_2_2_GENEALOGY_H

#include "ChildSiblingTree.h"

ChildSiblingTreeNode *SearchMember(ChildSiblingTreeNode *member, const char *name) {
    if (member == nullptr) return nullptr;
    if (std::strcmp(member->name_, name) == 0)
        return member;
    if (member->firstChild == nullptr) return nullptr;
    ChildSiblingTreeNode *iteration = SearchMember(member->firstChild, name);
    if (iteration != nullptr)
        return iteration;
    return SearchMember(member->nextSibling, name);
}

Status PrintInformation(ChildSiblingTreeNode *member, const char *name) {
    ChildSiblingTreeNode *p = SearchMember(member, name);
    cout << "成员信息：" << endl;
    cout << "姓名：" << member->name_ << endl;
    cout << "地址：" << member->address_ << endl;
    cout << "生日：" << member->birthday_ << endl;
    cout << "生存状况：" << member->condition_ << endl;
    cout << "是否已婚：" << member->marriage_ << endl;
    cout << "死亡时间：" << member->death_date << endl;
}


#endif //INC_6_2_2_GENEALOGY_H
