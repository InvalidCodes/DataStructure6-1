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
    bool AdminLogin();

    ///> Create a genealogy.
    bool CreateByFile(Node **p);

    ///> Display the genealogy.
    void DisplayGenealogy(Node *p, int REF_IN depth);

    ///> Set the ancestor.
    void SetAncestor(TripleTree *p);

    ///> Search for a family member.
    TripleTree *SearchMember(Node *p, std::string REF_IN name);

    ///> Find the parents of a family member.
    TripleTree *SearchParents(Node *p);

    ///> Delete a family member.
    bool DeleteMember(Node *p, std::string REF_IN name);

    ///> Update the genealogy.
    bool UpdateGenealogy(Node *p, std::string REF_IN name);

    ///> Add a family member.
    bool AddMember(Node *p, std::string REF_IN name, Information inf);

    ///> Find the relationship of two members.
    bool SearchRelationship();

    ///> Statistics data.
    bool Statistics(Node *p);

    ///> Get the average values.
    double GetAverageAge();

    double GetAverageHeight();

    double GetSexRatio();

private:
    TripleTree *root;
    Information *information;

    double average_age_;
    double average_height_;
    double sex_ratio_;
};

#endif //CHAPTER6_1_GENEALOGY_H
