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
    BOOST_AUTO_TEST_CASE(default_constructor_test)
    {
        using value_type = int;
        top::avl_tree<value_type> tree;
        BOOST_REQUIRE(tree.empty());
        BOOST_REQUIRE(!tree.height());
        BOOST_REQUIRE(!tree.contains(10));
    }

    BOOST_AUTO_TEST_CASE(insert_test)
    {
        using value_type = int;
        top::avl_tree<value_type> tree;
        value_type val{10};
        std::size_t size{0};
        tree.insert(val);
        size++;
        BOOST_REQUIRE(tree.contains(val));
        BOOST_REQUIRE_EQUAL(tree.size(), size);
        val = 11;
        tree.insert(val);
        size++;
        BOOST_REQUIRE(tree.contains(val));
        BOOST_REQUIRE_EQUAL(tree.size(), size);
    }

    BOOST_AUTO_TEST_CASE(insert_duplicates)
    {
        using value_type = int;
        top::avl_tree<value_type> tree;
        value_type val{10};
        tree.insert(val);
        BOOST_REQUIRE(tree.contains(val));
        BOOST_REQUIRE_EQUAL(tree.size(), 1);
        BOOST_REQUIRE(!tree.empty());
        tree.insert(val);
        BOOST_REQUIRE(tree.contains(val));
        BOOST_REQUIRE_EQUAL(tree.size(), 1);
        BOOST_REQUIRE(!tree.empty());
    }

    BOOST_AUTO_TEST_CASE(rotate_left_left_test)
    {
        using value_type = int;
        top::avl_tree<value_type> expect, actual;
        expect.insert(20);
        expect.insert(10);
        expect.insert(30);
        actual.insert(30);
        actual.insert(20);
        actual.insert(10);
        BOOST_REQUIRE(expect==actual);
    }

    BOOST_AUTO_TEST_CASE(rotate_right_right_test)
    {
        using value_type = int;
        top::avl_tree<value_type> expect, actual;
        expect.insert(20);
        expect.insert(10);
        expect.insert(30);
        actual.insert(10);
        actual.insert(20);
        actual.insert(30);
        BOOST_REQUIRE(expect==actual);
    }

    BOOST_AUTO_TEST_CASE(rotate_left_right_test)
    {
        using value_type = int;
        top::avl_tree<value_type> expect, actual;
        expect.insert(20);
        expect.insert(10);
        expect.insert(30);
        actual.insert(30);
        actual.insert(10);
        actual.insert(20);
        BOOST_REQUIRE(expect==actual);
    }

    BOOST_AUTO_TEST_CASE(rotate_right_left_test)
    {
        using value_type = int;
        top::avl_tree<value_type> expect, actual;
        expect.insert(20);
        expect.insert(10);
        expect.insert(30);
        actual.insert(10);
        actual.insert(30);
        actual.insert(20);
        BOOST_REQUIRE(expect==actual);
    }

    BOOST_AUTO_TEST_CASE(clear_test)
    {
        using value_type = int;
        top::avl_tree<value_type> tree;
        std::size_t size{0};
        tree.insert(20), size++;
        tree.insert(10), size++;
        tree.insert(30), size++;
        BOOST_REQUIRE_EQUAL(tree.size(), size);
        tree.clear();
        BOOST_REQUIRE(tree.empty());
    }
BOOST_AUTO_TEST_SUITE_END()

#endif //TEST_AVL_TREE_AVL_TREE_HPP
