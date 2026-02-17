A tree is an abstract data type that models a hierarchical relationship. It’s a collection of nodes connected by edges with one special node called the root. Trees are widely used in file systems, parsers, databases (indexes), and many algorithms.

Below is a focused primer on binary trees and all the common terminology, properties, and types you'll encounter.

What is a binary tree

A binary tree is a tree data structure where each node has at most two children — commonly called the left and right child. There is no ordering implied by the structure itself; ordering (like in a Binary Search Tree) is a separate property.

Simple ASCII example (root = 1):

        1
       / \
      2   3
     / \   \
    4   5   6

Terminology (precise definitions)

Node: an element of the tree that holds data (and links to children).

Edge: a connection between a parent node and a child node.

Root: the top node of the tree (no parent).

Parent: node that has one or more child nodes.

Child: node that has a parent.

Leaf (external node): a node with no children.

Internal node: a node with at least one child.

Siblings: nodes that share the same parent.

Ancestor: any node on the path from a node up to the root (parent, parent’s parent, …).

Descendant: any node in the subtree rooted at a node (children, grandchildren, …).

Subtree: the tree consisting of a node and all its descendants.

Path: sequence of nodes connected by edges. The length of a path is the number of edges on it.

Level (or depth level): nodes at distance d edges from the root are at level d. (Root usually level 0 or 1 by convention — I’ll use level 0 for root.)

Depth of a node: number of edges from root to that node (same as its level).

Height of a node: number of edges on the longest downward path from that node to a leaf.

Height of tree: height of the root. (If leaf has height 0, then tree height = max depth.)

Degree (of a node): number of children of that node (0, 1, or 2 in binary trees).

Useful formulas / observations (binary tree)

Maximum number of nodes at level l (0-based): 2^l.

Maximum number of nodes in a binary tree of height h (0-based height):
max_nodes = 2^{h+1} − 1.

Minimum possible height h for n nodes (perfectly filled tree):
h_min = floor(log2(n)).

For any binary tree with n nodes and L leaves (nodes with degree 0), and I internal nodes (degree ≥1):
n = I + L.

For a full binary tree (every node degree 0 or 2): L = I + 1.

```
Traversals (how we visit nodes)

Preorder: root → left → right

Inorder: left → root → right

Postorder: left → right → root

Level-order (breadth-first): visit nodes level by level (use a queue)

Inorder on a Binary Search Tree yields the keys in sorted order.

```

```
Properties of binary trees

Each node has ≤ 2 children.

A tree with n nodes has exactly n-1 edges (if non-empty).

A binary tree with n nodes has at most n+1 null pointers (useful in pointer-counting arguments).

Balanced trees attempt to keep heights of subtrees small (for O(log n) ops).

Structural vs. ordered: Binary Tree is structural; Binary Search Tree (BST) adds order property (left < root < right).
```

Types / shapes of binary trees - 

Structural classifications:

Full (Proper / Strict) Binary Tree
Every node has either 0 or 2 children. No node has a single child.

Perfect Binary Tree
All internal nodes have two children and all leaves are at the same level. It’s both full and complete.

Complete Binary Tree
All levels except possibly the last are completely filled, and the last level has all nodes as left as possible. (This is the shape used by binary heaps.)

Balanced Binary Tree
A loose term: left and right subtree heights differ at most by a small amount (e.g., AVL trees guarantee difference ≤ 1). “Balanced” generally implies height = O(log n).

Skewed Binary Tree
Every node has only one child (all left or all right). It degenerates to a linked list — worst-case height = n−1.

Binary Search Tree (BST) - ordered type
A binary tree with the property: for every node, keys in left subtree < node.key < keys in right subtree (or ≤ depending on convention). BSTs enable O(h) search/insert/delete where h is tree height.

Heap / Binary Heap - complete + heap-order property
Complete binary tree where parent’s key ≥ (max-heap) or ≤ (min-heap) children’s keys.


```
Complexity (typical operations)

Depends on height h:

Search / Insert / Delete in BST: average O(log n), worst O(n) (skewed). Balanced BSTs (AVL, Red-Black) guarantee O(log n).

Traversal (pre/in/post/level): O(n) time, O(h) auxiliary space (recursion or queue for level-order).

```