//
// Created by Grigoriy Khlytin on 15.12.2021.
//

#ifndef ITMO_CIRCLE_B_DIST_SEARCHTREE_H
#define ITMO_CIRCLE_B_DIST_SEARCHTREE_H

#include <iostream>
#include <vector>
#include <random>

class SearchTree {
public:

    class Tree {
    public:
        int value;
        int priority;
        Tree *leftSubTree;
        Tree *rightSubTree;

        explicit Tree(int x);

        explicit Tree(int x, int y);

        explicit Tree(int x, int y, Tree *left, Tree *right);

    };

    typedef Tree *Node;

    Node merge(Node leftTree, Node rightTree);

    std::pair<Node, Node> split(Node tree);

};

#endif //ITMO_CIRCLE_B_DIST_SEARCHTREE_H
