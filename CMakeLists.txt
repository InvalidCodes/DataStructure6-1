cmake_minimum_required(VERSION 3.24)
project(6_2_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(6_2_2 main.cpp
        Assistance.h
        Node.h SNode.h
        LinkQueue.h
        ChildSiblingTreeNode.h ChildSiblingTree.h
        Genealogy.h)
