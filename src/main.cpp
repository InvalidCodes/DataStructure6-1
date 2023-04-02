#include "Assistance.h"                    // ʵ�ó��������
#include "ChildSiblingTree.h"            // �����ֵܱ�ʾ����
//include "conio.h"                      // getche��ͷ�ļ�
//#include "Genealogy.h"

int SearchRelationship(ChildSiblingTreeNode *member, string name) {
    if (member == nullptr) {
        cout << "�����ڸó�Ա" << endl;
        return 0;
    }
    return 0;
}

Status PrintInformation(ChildSiblingTreeNode *member) {
    if (member == nullptr)
        return NOT_PRESENT;
    cout << "��Ա��Ϣ��" << endl;
    cout << "������" << member->name_ << endl;
    cout << "��ַ��" << member->address_ << endl;
    cout << "���գ�" << member->birthday_ << endl;
    cout << "����״����" << member->condition_ << endl;
    cout << "�Ƿ��ѻ飺" << member->marriage_ << endl;
    cout << "����ʱ�䣺" << member->death_date << endl;
    return VISITED;
}

Status JudgeIsEmpty(ChildSiblingTree tree) {
    if (tree.IsEmpty()) {
        cout << "�������ף��봴������" << endl;
        return SUCCESS;
    }
    return NOT_PRESENT;
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
    cout << "��������Ĳ��� (0~9): " << endl;
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
    char name_[10], birthday_[20];
    int position_;

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
                    if (JudgeIsEmpty(genealogy))
                        cout << "������Ҫ��ѯ�ĳ�Ա���ƣ�" << endl;
                    cin >> name_;
                    genealogy_node = genealogy.FindNodeByName(name_);
                    cout << "��ѯ�ɹ���" << endl;
                    PrintInformation(genealogy_node);
                    break;
                case 4:
                    if (JudgeIsEmpty(genealogy))
                        cout << "������Ҫ��ѯ�ĳ�Ա���գ�" << endl;
                    cin >> birthday_;
                    genealogy_node = genealogy.FindNodeByBirthday(birthday_);
                    cout << "��ѯ�ɹ���" << endl;
                    PrintInformation(genealogy_node);
                    break;
                case 5:
                    if (JudgeIsEmpty(genealogy))
                        cout << "������Ҫ��ѯ�ĳ�Ա1������" << endl;
                    cin >> name_;
                    genealogy_node = genealogy.FindNodeByName(name_);
                    ChildSiblingTreeNode *member;
                    char name_2[10];
                    cout << "������Ҫ��ѯ�ĳ�Ա2������" << endl;
                    cin >> name_2;
                    member = genealogy.FindNodeByName(name_2);
                    break;
                case 6:
                    if (JudgeIsEmpty(genealogy))
                        cout << "������Ҫ��ӵĳ�Ա�ĸ������ƣ�" << endl;
                    cin >> name_;
                    cout << "������Ҫ��ӵĳ�Ա�ĺ���λ�ã�" << endl;
                    cin >> position_;
                    genealogy_node = genealogy.FindNodeByName(name_);
                    genealogy.AddMember(genealogy_node, position_);
                    break;
                case 7:
                    if (JudgeIsEmpty(genealogy))
                        cout << "������Ҫɾ���ĳ�Ա���ƣ�" << endl;
                    cin >> name_;
                    genealogy_node = genealogy.FindNodeByName(name_);
                    genealogy.Destroy(genealogy_node);
                    break;
                case 8:
                    if (JudgeIsEmpty(genealogy))
                        cout << "������Ҫɾ���ĳ�Ա���ƣ�" << endl;
                    cin >> name_;
                    genealogy_node = genealogy.FindNodeByName(name_);
                    break;
            }
        }
    }
}



