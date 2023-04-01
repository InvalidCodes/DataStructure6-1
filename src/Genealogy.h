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
    cout << "��Ա��Ϣ��" << endl;
    cout << "������" << member->name_ << endl;
    cout << "��ַ��" << member->address_ << endl;
    cout << "���գ�" << member->birthday_ << endl;
    cout << "����״����" << member->condition_ << endl;
    cout << "�Ƿ��ѻ飺" << member->marriage_ << endl;
    cout << "����ʱ�䣺" << member->death_date << endl;
}


#endif //INC_6_2_2_GENEALOGY_H
