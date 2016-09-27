#include "solution.h"
#include <stddef.h>
#include <stdlib.h>
#include <math.h>

/**
 * Check if a binary tree is balanced
 * @returns 0: if the tree is not balanced
 * @returns 1: if the tree is balanced
 */

int my_min (int a, int b) {

  if (a < b) {
    return a;
  } else {
    return b;
  }

}

int my_max (int a, int b) {

  if (a > b) {
    return a;
  } else {
    return b;
  }

}

int min_subtree_height(btree_node_t *root) {
  
  if (root == NULL) {

    return 0;

  } else {

    return my_min( min_subtree_height(root->left), min_subtree_height(root->right) ) + 1;
    
  }

}

int max_subtree_height(btree_node_t *root) {
  
  if (root == NULL) {

    return 0;

  } else {

    return my_max( max_subtree_height(root->left, max_subtree_height(root->right) ) + 1;
   
  }

}

int check_if_balanced(btree_t *tree) {

  // if input tree is null, return true
  if ( tree == NULL ) {

    return 1;

  }

  // if root node is null, return true
  if ( tree->root == NULL ) {

    return 1;

  }

  // compare the max subtree height and min subtree height
  if ( max_subtree_height(tree->root) - min_subtree_height(tree->root) > 1 ) {

    return 0;

  } else {

    return 1;

  }

}
