//
// Created by Ge on 2023/3/29.
//

#include "genealogy.h"

Genealogy::Genealogy() : root(nullptr), information(nullptr), average_age_(0), average_height_(0), sex_ratio_(0) {
}

bool Genealogy::AdminLogin() {
    return false;
}

bool Genealogy::CreateByFile(Node **p) {
    int str;
    TripleTree *t;
    FILE *file;

    std::strcpy(family_name, family_name_);
    std::strcat(family_name,);
    file = std::fopen(family_name,);

    if (file) {
        fclose(file);
        std::cout << "Family already exists! Do u want to rebuild? (y/n)" << std::endl;
        int ch = getchar();
        getchar();
        if (ch == 'N' || ch == 'n') {
            t = fopen(family_name);
            return t;
        } else if (ch == 'Y' || ch == 'y') {
            file = fopen(family_name,);
            std::cout << "Please enter family members (one member takes up one row)." << std::endl;
        }
    }
}

void Genealogy::DisplayGenealogy(Node *p, const int &depth) {

}

void Genealogy::SetAncestor(TripleTree *p) {
    this->root = p;
}

TripleTree *Genealogy::SearchMember(Node *p, const std::string &name) {
    return nullptr;
}

TripleTree *Genealogy::SearchParents(Node *p) {
    return nullptr;
}

bool Genealogy::DeleteMember(Node *p, const std::string &name) {
    return false;
}

bool Genealogy::UpdateGenealogy(Node *p, const std::string &name) {
    return false;
}

bool Genealogy::AddMember(Node *p, const std::string &name, Information inf) {
    return false;
}

bool Genealogy::SearchRelationship() {
    return false;
}

bool Genealogy::Statistics(Node *p) {
    return false;
}

double Genealogy::GetAverageAge() {
    return 0;
}

double Genealogy::GetAverageHeight() {
    return 0;
}

double Genealogy::GetSexRatio() {
    return 0;
}


