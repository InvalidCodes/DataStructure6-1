//
// Created by Ge on 2023/3/29.
//

#ifndef CHAPTER6_1_NODE_H
#define CHAPTER6_1_NODE_H

#include "syntactic-sugar.h"

class Node {
public:
    Node();

    Node(int REF_IN e,
         Node *REF_IN leftChild,
         Node *REF_IN rightSibling);

    ///> 只读语法糖
    attr_reader_val(data_, Inf)

    attr_reader_val(parent_, Parent)

    attr_reader_ref(leftChild_, LeftChild)

    attr_reader_ref(rightSibling_, RightSibling)

private:
    int data_;
    Node *parent_;
    Node *leftChild_, *rightSibling_;
};

#endif //CHAPTER6_1_NODE_H
