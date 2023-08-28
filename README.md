# C - Binary trees

* [Project Description](#Project-Description)
* [Description of the command interpreter](#Description-of-the-command-interpreter)
* [How to start it, How to use it](#How-to-start-it,-How-to-use-it)
* [Contributors](#Contributors)
* [Usage](#Usage)

## <!-- ubuntu -->
<a href="https://ubuntu.com/" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=Ubuntu&color=E95420&logo=Ubuntu&logoColor=E95420&labelColor=2F333A" alt="Suite CRM"></a> <!-- bash --> <a href="https://www.gnu.org/software/bash/" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=GNU%20Bash&color=4EAA25&logo=GNU%20Bash&logoColor=4EAA25&labelColor=2F333A" alt="terminal"></a> <!-- python--> <a href="https://www.python.org" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=Python&color=FFD43B&logo=python&logoColor=3776AB&labelColor=2F333A" alt="python"></a> </a> <!-- vim --> <a href="https://www.vim.org/" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=Vim&color=019733&logo=Vim&logoColor=019733&labelColor=2F333A" alt="Suite CRM"></a> <!-- vs code --> <a href="https://code.visualstudio.com/" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=Visual%20Studio%20Code&color=5C2D91&logo=Visual%20Studio%20Code&logoColor=5C2D91&labelColor=2F333A" alt="Suite CRM"></a> </a><!-- git --> <a href="https://git-scm.com/" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=Git&color=F05032&logo=Git&logoColor=F05032&labelColor=2F333A" alt="git distributed version control system"></a> <!-- github --> <a href="https://github.com" target="_blank"> <img height="" src="https://img.shields.io/static/v1?label=&message=GitHub&color=181717&logo=GitHub&logoColor=f2f2f2&labelColor=2F333A" alt="Github"></a>

<br />

## Data structures For Header
**Basic Binary Tree**

```
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
```

**Binary Search Tree**

```
typedef struct binary_tree_s bst_t;
```

**AVL Tree**
```
typedef struct binary_tree_s avl_t;
```

**Max Binary Heap**
```
typedef struct binary_tree_s heap_t;
```

<br />

## Authors :black_nib:

* __Yousef Bakier__ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[<img height="" src="https://img.shields.io/static/v1?label=&message=GitHub&color=181717&logo=GitHub&logoColor=f2f2f2&labelColor=2F333A" alt="Github">](https://github.com/Y-Baker)
* __MohamedElftah__&nbsp;&nbsp;&nbsp;&nbsp; [<img height="" src="https://img.shields.io/static/v1?label=&message=GitHub&color=181717&logo=GitHub&logoColor=f2f2f2&labelColor=2F333A" alt="Github">](https://github.com/MohamedElshafae)
