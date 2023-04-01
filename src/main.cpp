#include "Assistance.h"                    // ʵ�ó��������
//#include "ChildSiblingTree.h"			// �����ֵܱ�ʾ����
//include "conio.h"                      // getche��ͷ�ļ�
//#include "Genealogy.h"

#include "ChildSiblingTree.h"

/*ChildSiblingTreeNode *SearchMemberByName(ChildSiblingTreeNode *member, const char *name) {
    if (member == nullptr) {
        cout << "�ó�Ա������" << endl;
        return nullptr;
    }
    if (std::strcmp(member->name_, name) == 0)
        return member;
    if (member->firstChild == nullptr) {
        cout << "�ó�Ա������" << endl;
        return nullptr;
    }
    ChildSiblingTreeNode *iteration = SearchMemberByName(member->firstChild, name);
    if (iteration != nullptr)
        return iteration;
    return SearchMemberByName(member->nextSibling, name);
}*/

int SearchRelationship(ChildSiblingTreeNode *member, string name) {
    if (member == nullptr) {
        cout << "�����ڸó�Ա" << endl;
        return 0;
    }
    return 0;
}

Status PrintInformation(ChildSiblingTreeNode *member, const char *name) {
    cout << "��Ա��Ϣ��" << endl;
    cout << "������" << member->name_ << endl;
    cout << "��ַ��" << member->address_ << endl;
    cout << "���գ�" << member->birthday_ << endl;
    cout << "����״����" << member->condition_ << endl;
    cout << "�Ƿ��ѻ飺" << member->marriage_ << endl;
    cout << "����ʱ�䣺" << member->death_date << endl;
}

void Menu() {
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

int main() {
    int a[19];
    cout << "��ӭʹ�ü�ͥ����ϵͳ�����洴��������" << endl;
// ��ʼ��1����genealogy.txt�е�������������p[]��
    int count = 0;
    ifstream in("genealogy.txt", ios::in);
    if (!in.is_open()) {
        cout << "Error: opening file 'genealogy.txt' fail." << endl;
        exit(1);
    }
    while (!in.eof() && count < 19) {
        in >> p[count].name >> p[count].birth >> p[count].marriage
           >> p[count].address >> p[count].condition >> p[count].death;
        count++;
    }
    //test
    for (int i = 0; i < count; ++i)
        cout << "name_:" << p[i].name
             << "birthday_:" << p[i].birth
             << "marriage_:" << p[i].marriage
             << "address_:" << p[i].address
             << "condition_:" << p[i].condition
             << "death_date:" << p[i].death << endl;
    in.close();

//��ʼ��2����parent.txt�е����ݴ���������
    int m = 0;
    ifstream in_file("parent.txt", ios::in);
    if (!in_file.is_open()) {
        cout << "Error: opening file 'parent.txt' fail." << endl;
        exit(1);
    }
    while (!in_file.eof() && m < 19) {
        in_file >> a[m];
        m++;
    }

    //test
    for (int i = 0; i < 19; ++i)
        cout << "parent:" << a[i] << endl;
    in_file.close();

//��ʼ����Ŀ¼
    char name_[10];
    ChildSiblingTree genealogy(p, a, 19); //������
    ChildSiblingTreeNode *genealogy_node;
    cout << "�������ɹ���!" << endl;

    while (true) {
        int choice;
        Menu();
        cin >> choice;
        if (choice == 0) {
            return 0;
        } else {
            switch (choice) {
                case 1:
                    cout << "��ӡ��:" << endl;
                    DisplayTWithConcaveShape(genealogy);
                    cout << "��ӡ�����" << endl;
                    break;
                case 2:
                    cout << "������д�ˣ�����" << endl;
                    break;
                case 3:
                    if (genealogy.IsEmpty())
                        cout << "�������ף��봴�����ף�" << endl;
                    else
                        cout << "������Ҫ��ѯ�ĳ�Ա���ƣ�" << endl;
                    cin >> name_;

                    genealogy_node = genealogy.FindNodeByName(name_);
                    cout << "��ѯ�ɹ���" << endl;
                    PrintInformation(genealogy_node, name_);
                    break;
                case 4:
                    if (genealogy.IsEmpty())
                        cout << "�������ף��봴�����ף�" << endl;
                    else
                        cout << "������Ҫ��ѯ�ĳ�Ա���ƣ�" << endl;
                    cin >> name_;

                    genealogy_node = genealogy.FindNodeByBirthday(genealogy.GetRoot(), name_);

                    break;
                case 5:
                    cout << "������д�ˣ�����" << endl;
                    break;
                case 6:
                    cout << "������д�ˣ�����" << endl;
                    break;
                case 7:
                    if (genealogy.IsEmpty())
                        cout << "�������ף��봴�����ף�" << endl;
                    else
                        cout << "������Ҫ��ѯ�ĳ�Ա���ƣ�" << endl;
                    //char name_[10];
                    //cin >> name_;
                    break;
                case 8:
                    cout << "������д�ˣ�����" << endl;
                    break;
            }
        }
    }
}



