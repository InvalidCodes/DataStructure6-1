//
// Created by Ge on 2023/3/29.
//

#include "genealogy.h"

Genealogy::Genealogy() {}

bool Genealogy::CreateByFile(Node **p) {}

void Genealogy::Display(Node *p, int REF_IN depth) {}

bool Genealogy::Add(Node *p, const std::string &name, int rel) {}

Node *Genealogy::FindPre(Node *p) {}

bool Genealogy::Delete(Node *p, const std::string &name) {}

Node *Genealogy::get_root() {}

double Genealogy::GetAge() {}

double Genealogy::GetRatio() {}

bool Genealogy::Login() {}

bool Genealogy::RelSearch() {}

bool Genealogy::MemSearch() {}

bool Genealogy::Statistics(Node *p) {}

bool Genealogy::Update(Node *p, const std::string &name) {}

double Genealogy::GetHeight() {}

