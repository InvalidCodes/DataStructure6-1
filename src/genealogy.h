//
// Created by Ge on 2023/3/29.
//

#ifndef CHAPTER6_1_GENEALOGY_H
#define CHAPTER6_1_GENEALOGY_H

#include "facility/information.h"
#include "facility/triple-tree-node.h"

class Genealogy {
public:
    Genealogy();

private:
    ///> Administrator login.
    bool Login();

    //void set_root(Node *root);

    ///> Create a genealogy.
    bool CreateByFile(Node **p);

    ///> Display the genealogy.
    void Display(Node *p, int REF_IN depth);

    ///> Find the original ancestor the family.
    Node *get_root();

    ///> Search for a family member.
    Node *Search(Node *p, std::string REF_IN name);

    ///> Find the parents of a family member.
    Node *FindPre(Node *p);

    ///> Delete a family member.
    bool Delete(Node *p, std::string REF_IN name);

    ///> Update the genealogy.
    bool Update(Node *p, std::string REF_IN name);

    ///> Add a family member.
    bool Add(Node *p, std::string REF_IN name, Rel rel);

    bool MemSearch();        //按成员查询

    ///> Find the relationship of two members.
    bool RelSearch();

    ///> Statistics data.
    bool Statistics(Node *p);

    ///> Get the average values.
    double GetAverageAge();
    double GetAverageHeight();
    double GetSexRatio();
};

#endif //CHAPTER6_1_GENEALOGY_H
