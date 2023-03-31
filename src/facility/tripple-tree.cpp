//
// Created by Ge on 2023/3/31.
//

#include <cstdlib>
#include "triple-tree.h"

void TripleTree::InitTriTree(Node *t) {
    t = nullptr;
}

void TripleTree::DestroyTriTree(Node *t) {
    if (t) {
        if (t->firstChild_)
            DestroyTriTree(t->firstChild_);
        if (REF_OUT t->nextSibling_)
            DestroyTriTree(t->nextSibling_);
        free(t);    ///< Release the root.
        t = nullptr;    ///< Place the null ptr as nullptr.
    }
}

void TripleTree::CreateTriTree(Node *t) {
    int ch;
    scanf("%d", REF_OUT ch);
    if (ch == 0)
        t = nullptr;
    else {
        t = (Node) malloc(sizeof(*Node));
        if (!t) {
            std::cout << "Failed to create root node!" << std::endl;
            exit(-1);
        }
        t->data_ = ch;
        t->parent_ = nullptr;   ///< Root has no parent.
        CreateTriTree(t->firstChild_);
        if (!t->firstChild_) {
            std::cout << "Failed to create left child!" << std::endl;
            exit(-1);
        }
        t->firstChild_->parent_ = t;   ///< Assign value to left child's parent.
        if (!t->nextSibling_) {
            std::cout << "Failed to create next sibling!" << std::endl;
            exit(-1);
        }
        t->nextSibling_->parent_ = t;
    }
}

Status TripleTree::IsEmpty(Node REF_IN t) const {
    if (t.data_)
        EXIT_SUCCESS;
    else
        EXIT_FAILURE;
}

int TripleTree::GetDepth(Node REF_IN t) const {
    int left_depth, right_depth;
    if (IsEmpty(t))
        EXIT_FAILURE;
    if (!t.firstChild_) {
        std::cout << "The left tree depth is zero." << std::endl;
        left_depth = 0;
    }
    left_depth = GetDepth(*t.firstChild_);
    if (!t.nextSibling_) {
        std::cout << "The right tree depth is zero." << std::endl;
        right_depth = 0;
    }
    right_depth = GetDepth(*t.nextSibling_);

    return left_depth > right_depth ? (left_depth + 1) : (right_depth + 1);
}

int TripleTree::ReturnRoot(const Node &t) const {
    if (IsEmpty(t))
        EXIT_FAILURE;
    else
        return t.data_;
}

int TripleTree::GetValue(Node REF_IN p) {
    return p.data_;
}

void TripleTree::AssignValue(Node p, int value) {
    p.data_ = value;
}
