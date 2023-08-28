//
// Created by Tomáš Petříček on 27.08.2023.
//

#ifndef AVL_TREE_AVL_TREE_HPP
#define AVL_TREE_AVL_TREE_HPP

#include <memory>
#include <iostream>

namespace top {
    template<class T>
    class avl_tree {
        struct node {
            T value;
            node* right{nullptr}, * left{nullptr};
        };
        node* root_{nullptr};

        void clear(node*& curr)
        {
            if (curr) {
                clear(curr->left);
                clear(curr->right);
                delete curr;
                curr = nullptr;
            }
        }
    public:
        using value_type = T;

        void insert(const T& value)
        {
            if (!root_) {
                root_ = new node{value};
            }
            else {
                node* curr{root_}, * prev{nullptr};
                while (curr) {
                    prev = curr;
                    if (curr->value==value) {
                        return;
                    }
                    if (curr->value>value) {
                        curr = curr->left;
                    }
                    else {
                        curr = curr->right;
                    }
                }
                if (prev->value>value) {
                    prev->left = new node{value};
                }
                else {
                    prev->right = new node{value};
                }
            }
        }

        bool contains(const T& value) const
        {
            node* curr{root_};
            while (curr) {
                if (curr->value==value) {
                    return true;
                }
                if (curr->value>value) {
                    curr = curr->left;
                }
                else {
                    curr = curr->right;
                }
            }
            return false;
        }

        bool empty() const
        {
            return !root_;
        }

        void clear()
        {
            clear(root_);
        }

        ~avl_tree()
        {
            clear(root_);
        }
    };
}

#endif //AVL_TREE_AVL_TREE_HPP
