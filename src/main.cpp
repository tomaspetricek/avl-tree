#include <iostream>
#include <avl_tree.hpp>
#include <cassert>

int main()
{
    using value_type = int;
    top::avl_tree<value_type> tree;
    tree.insert(7);
    tree.insert(20);
    tree.insert(5);
    tree.insert(15);
    tree.insert(10);
    tree.insert(4);
    tree.insert(4);
    tree.insert(33);
    tree.insert(2);
    tree.insert(25);
    tree.insert(6);
    assert(!tree.contains(100));
    assert(tree.contains(6));
    assert(!tree.empty());
    tree.clear();
    assert(tree.empty());
    return EXIT_SUCCESS;
}
