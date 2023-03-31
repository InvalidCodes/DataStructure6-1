//
// Created by Ge on 2023/3/31.
//

#ifndef CHAPTER6_1_TRIPLE_TREE_H
#define CHAPTER6_1_TRIPLE_TREE_H

#include "triple-tree-node.h"

class TripleTree {
public:
    [[nodiscard]] Status IsEmpty(Node REF_IN t) const;

    [[nodiscard]] int GetDepth(Node REF_IN t) const;

    [[nodiscard]] static int GetValue(Node REF_IN p) ;

    static void AssignValue(Node p, int value);

protected:
    static void InitTriTree(Node *t);

    void DestroyTriTree(Node *t);

    void CreateTriTree(Node *t);

    [[nodiscard]] int ReturnRoot(Node REF_IN t) const;

    Node *root;
};

#endif //CHAPTER6_1_TRIPLE_TREE_H
