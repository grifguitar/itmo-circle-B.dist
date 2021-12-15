//
// Created by Grigoriy Khlytin on 15.12.2021.
//

#include "SearchTree.h"

inline int get_rand_int() {
    thread_local static std::mt19937 gen{std::random_device{}()};
    thread_local static std::uniform_int_distribution<int> pick{INT32_MIN, INT32_MAX};
    return pick(gen);
}

SearchTree::Tree::Tree(int x) :
        value(x), priority(get_rand_int()), leftSubTree(nullptr), rightSubTree(nullptr) {
}

SearchTree::Tree::Tree(int x, int y) :
        value(x), priority(y), leftSubTree(nullptr), rightSubTree(nullptr) {
}

SearchTree::Tree::Tree(int x, int y, SearchTree::Node left, SearchTree::Node right) :
        value(x), priority(y), leftSubTree(left), rightSubTree(right) {
}

std::pair<SearchTree::Node, SearchTree::Node> SearchTree::split(SearchTree::Node tree) {
    return {nullptr, nullptr};
}

SearchTree::Node SearchTree::merge(SearchTree::Node leftTree, SearchTree::Node rightTree) {
    return nullptr;
}
