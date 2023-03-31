//
// Created by Ge on 2023/3/29.
//

#ifndef CHAPTER6_1_GENEALOGY_H
#define CHAPTER6_1_GENEALOGY_H

#include "facility/information.h"
#include "facility/triple-tree.h"

class Genealogy {
public:
    Genealogy();

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
    bool Add(Node *p, std::string REF_IN name, Information inf);

    bool MemSearch(); 

    ///> Find the relationship of two members.
    bool RelSearch();

    ///> Statistics data.
    bool Statistics(Node *p);

    ///> Get the average values.
    double GetAverageAge();

    double GetAverageHeight();

    double GetSexRatio();

private:
    Node *root;

    Information information;

    double average_age_;
    double average_height_;
    double sex_ratio_;
};

#endif //CHAPTER6_1_GENEALOGY_H
