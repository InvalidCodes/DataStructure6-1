//
// Created by Ge on 2023/3/29.
//

#ifndef CHAPTER6_1_TRIPLE_TREE_NODE_H
#define CHAPTER6_1_TRIPLE_TREE_NODE_H

#include "syntactic-sugar.h"
#include <cstdio>
#include <iostream>

class Node {
public:
    Node();

    Node(int REF_IN e,
         Node *REF_IN firstChild,
         Node *REF_IN nextSibling);

    /**attr_reader_val(data_, Inf)

    attr_reader_val(parent_, Parent)

    attr_reader_ref(firstChild_, FirstChild)

    attr_reader_ref(nextSibling_, NextSibling)*/

    int data_;
    Node *parent_;
    Node *firstChild_, *nextSibling_;
};

#endif //CHAPTER6_1_TRIPLE_TREE_NODE_H
