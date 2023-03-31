//
// Created by Ge on 2023/3/29.
//

#include "triple-tree-node.h"

Node::Node() {
    Node *root = new Node();
    root->data_ = 1;
    root->parent_ = nullptr;
    root->firstChild_ = nullptr;
    root->nextSibling_ = nullptr;
}

Node::Node(int REF_IN e,
           Node *REF_IN firstChild = nullptr,
           Node *REF_IN nextSibling = nullptr)
        : data_(e),
        firstChild_(firstChild),
        nextSibling_(nextSibling) {
}
