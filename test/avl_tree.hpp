//
// Created by Tomáš Petříček on 27.08.2023.
//

#ifndef TEST_AVL_TREE_AVL_TREE_HPP
#define TEST_AVL_TREE_AVL_TREE_HPP

#include <boost/test/unit_test.hpp>
#include <avl_tree.hpp>
#include <algorithm>
#include <random>

BOOST_AUTO_TEST_SUITE(avl_tree_test)
    BOOST_AUTO_TEST_CASE(tutorial_based_test) {
        using value_type = int;
        using tree_type = top::avl_tree<value_type>;
        tree_type tree;
        tree_type::node_type* expect_root;

    }
BOOST_AUTO_TEST_SUITE_END()

#endif //TEST_AVL_TREE_AVL_TREE_HPP
