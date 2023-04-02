#include "Assistance.h"                    // 实用程序软件包
#include "ChildSiblingTree.h"            // 孩子兄弟表示树类
//include "conio.h"                      // getche的头文件
//#include "Genealogy.h"

int SearchRelationship(ChildSiblingTreeNode *member, string name) {
    if (member == nullptr) {
        cout << "不存在该成员" << endl;
        return 0;
    }
    return 0;
}

Status PrintInformation(ChildSiblingTreeNode *member) {
    if (member == nullptr)
        return NOT_PRESENT;
    cout << "成员信息：" << endl;
    cout << "姓名：" << member->name_ << endl;
    cout << "地址：" << member->address_ << endl;
    cout << "生日：" << member->birthday_ << endl;
    cout << "生存状况：" << member->condition_ << endl;
    cout << "是否已婚：" << member->marriage_ << endl;
    cout << "死亡时间：" << member->death_date << endl;
    return VISITED;
}

Status JudgeIsEmpty(ChildSiblingTree tree) {
    if (tree.IsEmpty()) {
        cout << "暂无族谱，请创建族谱" << endl;
        return SUCCESS;
    }
    return NOT_PRESENT;
}

void Menu() {
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
    cout << "请输入你的操作 (0~9): " << endl;
}

int main() {
    int a[19];
    cout << "欢迎使用家庭管理系统，下面创建家谱树" << endl;
// 初始化1，把genealogy.txt中的数据输入数组p[]里
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

//初始化2，把parent.txt中的数据传入数组里
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

//开始功能目录
    char name_[10], birthday_[20];
    int position_;

    ChildSiblingTree genealogy(p, a, 19); //创建树
    ChildSiblingTreeNode *genealogy_node;
    cout << "树创建成功啦!" << endl;

    while (true) {
        int choice;
        Menu();
        cin >> choice;
        if (choice == 0) {
            return 0;
        } else {
            switch (choice) {
                case 1:
                    cout << "打印树:" << endl;
                    DisplayTWithConcaveShape(genealogy);
                    cout << "打印树完成" << endl;
                    break;
                case 2:
                    cout << "等着你写了，加油" << endl;
                    break;
                case 3:
                    if (JudgeIsEmpty(genealogy))
                        cout << "请输入要查询的成员名称：" << endl;
                    cin >> name_;
                    genealogy_node = genealogy.FindNodeByName(name_);
                    cout << "查询成功！" << endl;
                    PrintInformation(genealogy_node);
                    break;
                case 4:
                    if (JudgeIsEmpty(genealogy))
                        cout << "请输入要查询的成员生日：" << endl;
                    cin >> birthday_;
                    genealogy_node = genealogy.FindNodeByBirthday(birthday_);
                    cout << "查询成功！" << endl;
                    PrintInformation(genealogy_node);
                    break;
                case 5:
                    if (JudgeIsEmpty(genealogy))
                        cout << "请输入要查询的成员1姓名：" << endl;
                    cin >> name_;
                    genealogy_node = genealogy.FindNodeByName(name_);
                    ChildSiblingTreeNode *member;
                    char name_2[10];
                    cout << "请输入要查询的成员2姓名：" << endl;
                    cin >> name_2;
                    member = genealogy.FindNodeByName(name_2);
                    break;
                case 6:
                    if (JudgeIsEmpty(genealogy))
                        cout << "请输入要添加的成员的父亲名称：" << endl;
                    cin >> name_;
                    cout << "请输入要添加的成员的孩子位置：" << endl;
                    cin >> position_;
                    genealogy_node = genealogy.FindNodeByName(name_);
                    genealogy.AddMember(genealogy_node, position_);
                    break;
                case 7:
                    if (JudgeIsEmpty(genealogy))
                        cout << "请输入要删除的成员名称：" << endl;
                    cin >> name_;
                    genealogy_node = genealogy.FindNodeByName(name_);
                    genealogy.Destroy(genealogy_node);
                    break;
                case 8:
                    if (JudgeIsEmpty(genealogy))
                        cout << "请输入要删除的成员名称：" << endl;
                    cin >> name_;
                    genealogy_node = genealogy.FindNodeByName(name_);
                    break;
            }
        }
    }
}



