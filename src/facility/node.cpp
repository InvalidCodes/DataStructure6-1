//
// Created by Ge on 2023/3/29.
//

#include "node.h"

///> 构造：指针域为空
Node::Node() {
}

///> 拷贝构造：数据域e，指针域link
Node::Node(int REF_IN e, Node *REF_IN firstChild = nullptr, Node *REF_IN nextSibling = nullptr)
        : data_(e), firstChild_(firstChild), nextSibling_(nextSibling) {
}
