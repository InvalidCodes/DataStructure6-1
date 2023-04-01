/// @brief Genealogy tree functions.
/// @author Created by Ge on 2023/4/1.

#ifndef INC_6_2_2_GENEALOGY_H
#define INC_6_2_2_GENEALOGY_H

#include "ChildSiblingTree.h"

void Menu(){
    cout << "          *******���׹�����Ŀ¼*******         " << endl;
    cout << "          ------------------------------         " << endl;
    cout << "                  0. �˳�ϵͳ                    " << endl;
    cout << "                  1.��ӡ������                   " << endl;
    cout << "               2.��ʾһ��������������            " << endl;
    cout << "                3.��������ѯ��Ա��Ϣ             " << endl;
    cout << "               4.�����ղ��Ҽ��׳�Ա              " << endl;
    cout << "               5.��������ȷ����ϵ                " << endl;
    cout << "                   6.��Ӻ���                    " << endl;
    cout << "                   7.ɾ����Ա                    " << endl;
    cout << "                 8.�޸ĳ�Ա��Ϣ                  " << endl;
    cout << "         -------------------------------         " << endl;
    cout << "��������Ĳ���(0~9):" << endl;
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
    cout << "��Ա��Ϣ��" << endl;
    cout << "������" << member->name_ << endl;
    cout << "��ַ��" << member->address_ << endl;
    cout << "���գ�" << member->birthday_ << endl;
    cout << "����״����" << member->condition_ << endl;
    cout << "�Ƿ��ѻ飺" << member->marriage_ << endl;
    cout << "����ʱ�䣺" << member->death_date << endl;
}



#endif //INC_6_2_2_GENEALOGY_H
