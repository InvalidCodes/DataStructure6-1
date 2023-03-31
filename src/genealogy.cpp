//
// Created by Ge on 2023/3/29.
//

#include "genealogy.h"


Genealogy::Genealogy() {

}

bool Genealogy::Login() {
    return false;
}

bool Genealogy::CreateByFile(Node **p) {
    return false;
}

void Genealogy::Display(Node *p, const int &depth) {

}

Node *Genealogy::get_root() {
    return nullptr;
}

Node *Genealogy::Search(Node *p, const std::string &name) {
    return nullptr;
}

Node *Genealogy::FindPre(Node *p) {
    return nullptr;
}

bool Genealogy::Delete(Node *p, const std::string &name) {
    return false;
}

bool Genealogy::Update(Node *p, const std::string &name) {
    return false;
}

bool Genealogy::Add(Node *p, const std::string &name, Rel rel) {
    return false;
}

bool Genealogy::MemSearch() {
    return false;
}

bool Genealogy::RelSearch() {
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
