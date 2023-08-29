//
// Created by Tomáš Petříček on 27.08.2023.
//

#ifndef AVL_TREE_AVL_TREE_HPP
#define AVL_TREE_AVL_TREE_HPP

#include <memory>
#include <iostream>
#include <iterator>

namespace top {
    template<class T>
    class avl_tree {
        struct node {
            T value;
            node* right{nullptr}, * left{nullptr};
            int height{1}; // the initial height is 1 instead of 0

            void update_height()
            {
                height = std::max(compute_height(left), compute_height(right))+1;
            }

            int balance_factor()
            {
                return compute_height(left)-compute_height(right);
            }
        };
        node* root_{nullptr};
        std::size_t size_{0};

        static int compute_height(node* node)
        {
            return node ? node->height : 0;
        }

        void clear(node*& curr)
        {
            if (curr) {
                clear(curr->left);
                clear(curr->right);
                delete curr;
            }
        }

        node* rotate_left_left(node* curr)
        {
            node* left = curr->left;
            node* left_right = left->right;

            left->right = curr;
            curr->left = left_right;

            curr->update_height();
            left->update_height();
            return left;
        }

        node* rotate_right_right(node* curr)
        {
            node* right = curr->right;
            node* right_left = right->left;

            right->left = curr;
            curr->right = right_left;

            curr->update_height();
            right->update_height();
            return right;
        }

        node* rotate_left_right(node* curr)
        {
            node* left = curr->left;
            node* left_right = left->right;

            left->right = left_right->left;
            curr->left = left_right->right;
            left_right->right = curr;
            left_right->left = left;

            left->update_height();
            curr->update_height();
            left_right->update_height();
            return left_right;
        }

        node* rotate_right_left(node* curr)
        {
            node* right = curr->right;
            node* right_left = right->left;

            right->left = right_left->right;
            curr->right = right_left->left;
            right_left->left = curr;
            right_left->right = right;

            right->update_height();
            curr->update_height();
            right_left->update_height();
            return right_left;
        }

        node* rotate(node* curr)
        {
            if (curr->balance_factor()==2) {
                if (curr->left->balance_factor()==1) {
                    return rotate_left_left(curr);
                }
                else {
                    return rotate_left_right(curr);
                }
            }
            else if (curr->balance_factor()==-2) {
                if (curr->right->balance_factor()==-1) {
                    return rotate_right_right(curr);
                }
                else {
                    return rotate_right_left(curr);
                }
            }
            return curr;
        }

        node* insert(node* curr, const T& value)
        {
            if (curr) {
                if (curr->value==value) {
                    return curr;
                }
                if (curr->value>value) {
                    curr->left = insert(curr->left, value);
                }
                else {
                    curr->right = insert(curr->right, value);
                }
                curr->update_height();
                return rotate(curr);
            }
            size_++;
            return new node{value};
        }

        bool same(node* lhs, node* rhs) const
        {
            if (!lhs || !rhs) {
                return lhs==lhs;
            }
            return (lhs->value==rhs->value) && same(lhs->right, rhs->right) && same(lhs->left, rhs->left);
        }

    public:
        using value_type = T;
        using size_type = std::size_t;

        void insert(const T& value)
        {
            root_ = insert(root_, value);
        }

        bool contains(const T& value) const
        {
            node*curr{root_};
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

        bool operator==(const avl_tree& rhs) const
        {
            return same(root_, rhs.root_);
        }

        bool operator!=(const avl_tree& rhs) const
        {
            return !(rhs==*this);
        }

        bool empty() const
        {
            return !root_;
        }

        void clear()
        {
            clear(root_);
            root_ = nullptr;
            size_ = 0;
        }

        std::size_t size() const
        {
            return size_;
        }

        int height() const
        {
            return compute_height(root_);
        }

        ~avl_tree()
        {
            clear();
        }
    };
}

#endif //AVL_TREE_AVL_TREE_HPP
