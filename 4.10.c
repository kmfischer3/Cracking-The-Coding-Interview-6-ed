#include <stddef.h>
#include "solution.h"

/**
 * Check if a binary tree contains another binary tree.
 * @param t1: attempt to find `t2` in this tree.
 * @param t2: check if `t1` contains this tree.
 * @returns 0: if `t2` is not contained in `t1`.
 * @returns 1: if `t2` is contained in `t1`.
 */

int match_trees(btree_node_t *t1, btree_node_t *t2) {

  if (t1 == NULL && t2 == NULL){
    return 1;
  }
  if (t1 == NULL || t2 == NULL){
    return 0;
  }

  if (t1->value == t2->value) { 
    return match_trees(t1->left, t2->left) && match_trees(t1->right, t2->right);
  } else {
    return 0;
  }

}

int check_if_contains(btree_t *t1, btree_t *t2) {

  if (t1 == NULL || t1->root == NULL) {
    return 0;
  }
  if (t2 == NULL|| t2->root == NULL) {
    return 1;
  }

  btree_node_t curr = *t1->root;
  btree_t curr_left_tree, curr_right_tree;
  curr_left_tree.root = curr.left;
  curr_right_tree.root = curr.right;
  
  if ( (curr.value == t2->root->value) && match_trees(t1->root, t2->root) ) {

    return 1;

  } else {

    return check_if_contains(&curr_left_tree, t2) || check_if_contains(&curr_right_tree, t2);

  }
  
  return 0;

}
