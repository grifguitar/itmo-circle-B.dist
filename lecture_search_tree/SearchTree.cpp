//
// Created by Grigoriy Khlytin on 15.12.2021.
//

#include "SearchTree.h"

using namespace std;


// ---- #define ON_ARRAYS ----
// закомментируйте/раскомментируйте:
#define ON_ARRAYS
// чтобы переключить режим
// ---------------------------


#ifdef ON_ARRAYS
// -------- on arrays --------
struct Tree;

vector<Tree> memory;
int memory_head = 0;

typedef int Node;
const Node NUL = -1;
#define get(x, y) memory[x].y

// ---------------------------
#else
// ------- on pointers -------
struct Tree;

typedef Tree *Node;
Node NUL = nullptr;
#define get(x, y) (*(x)).y

// ---------------------------
#endif


int get_rand_int() {
    static mt19937 gen{random_device{}()};
    static uniform_int_distribution<int> pick{-100, 100};
    return pick(gen);
}


struct Tree {
    int value;
    int priority;
    Node left = NUL;
    Node right = NUL;

    Tree() {
        value = INT32_MIN;
        priority = INT32_MIN;
    }

    explicit Tree(int x) {
        value = x;
        priority = get_rand_int();
    }
};


#ifdef ON_ARRAYS
// -------- on arrays --------

Node build(int x0) {
    memory.emplace_back(x0);
    return memory_head++;
}

// ---------------------------
#else
// ------- on pointers -------

Node build(int x0) {
    Node node = new Tree(x0);
    return node;
}

// ---------------------------
#endif


Node merge(Node leftNode, Node rightNode) {
    if (leftNode == NUL) return rightNode;
    if (rightNode == NUL) return leftNode;

    if (get(leftNode, priority) > get(rightNode, priority)) {
        Node node = merge(get(leftNode, right), rightNode);
        get(leftNode, right) = node;
        return leftNode;
    } else {
        Node node = merge(leftNode, get(rightNode, left));
        get(rightNode, left) = node;
        return rightNode;
    }
}

pair<Node, Node> split(Node node, int x0) {
    if (node == NUL) {
        return {NUL, NUL};
    }

    if (get(node, value) <= x0) {
        auto p = split(get(node, right), x0);
        get(node, right) = p.first;
        return {node, p.second};
    } else {
        auto p = split(get(node, left), x0);
        get(node, left) = p.second;
        return {p.first, node};
    }
}

Node add(Node node, int x0) {
    Node address = build(x0);
    auto p1 = split(node, x0 - 1);
    auto p2 = split(p1.second, x0);
    return merge(merge(p1.first, address), p2.second);
}

Node remove_all(Node node, int x0) {
    auto p1 = split(node, x0 - 1);
    auto p2 = split(p1.second, x0);
    return merge(p1.first, p2.second);
}

Node get_min(Node node, int &answer) {
    Node node1 = node;
    while (get(node1, left) != NUL) node1 = get(node1, left);
    answer = get(node1, value);
    return remove_all(node, answer);
}

string do_space(int depth) {
    string s;
    for (int i = 0; i < depth; i++) s += " ";
    return s;
}

void print_tree(Node node, int depth) {
    Node left = get(node, left);
    Node right = get(node, right);
    int x = get(node, value);
    int y = get(node, priority);

    cout << do_space(depth) << "(" << "\n";
    if (left != NUL) {
        print_tree(left, depth + 4);
    } else {
        cout << do_space(depth) << "*" << "\n";
    }
    cout << do_space(depth) << "[" << x << ", " << y << "]" << "\n";
    if (right != NUL) {
        print_tree(right, depth + 4);
    } else {
        cout << do_space(depth) << "*" << "\n";
    }
    cout << do_space(depth) << ")" << "\n";
}

bool SearchTree::solve() {
    Node root = build(INT32_MAX);

    set<int> my_set;
    my_set.insert(INT32_MAX);

    for (int i = 0; i < 10; i++) {
        int elem = get_rand_int();
        my_set.insert(elem);
        root = add(root, elem);
    }

    print_tree(root, 0);
    cout << '\n';

    while (!my_set.empty()) {
        int elem1 = *my_set.begin();
        my_set.erase(my_set.begin());
        int elem2;
        root = get_min(root, elem2);
        if (elem1 == elem2) {
            cout << elem2 << " ";
        } else {
            cout << "проиграли";
            return false;
        }
    }

    if (root != NUL) {
        cout << "проиграли";
        return false;
    }

    return true;
}
