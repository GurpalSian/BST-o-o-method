#include <iostream>

#include "Node.h"
#include "BinarySearchTree.h"

int main()
{
	

	Node<int, int>** tree;
	BinarySearchTree<int, int>* t = new BinarySearchTree<int, int>();
	Node<int, int>* root = nullptr;  
	tree = &root;


	int x;


	/*t->insert_node_recursively(tree, Node<int, int>(10, 10));
	t->insert_node_recursively(tree, Node<int, int>(20, 20));
	t->insert_node_recursively(tree, Node<int, int>(5, 5));
	t->insert_node_recursively(tree, Node<int, int>(6, 6));
	t->insert_node_recursively(tree, Node<int, int>(1, 1));
	t->insert_node_recursively(tree, Node<int, int>(8, 8));
	t->insert_node_recursively(tree, Node<int, int>(30, 30));
	t->insert_node_recursively(tree, Node<int, int>(14, 14));
	t->insert_node_recursively(tree, Node<int, int>(3, 3));
	t->insert_node_recursively(tree, Node<int, int>(2, 2));

	
	t->print_tree_recursively(tree);
	std::cout << std::endl;

	std::cin >> x;

	t->terminate_tree_recursively(tree);

	std::cin >> x;*/


	Node<int, int>** tree2;
	BinarySearchTree<int, int>* t2 = new BinarySearchTree<int, int>();
	Node<int, int>* root2 = nullptr;
	tree2 = &root2;

	t2->insert_node_iteratively(tree2, Node<int, int>(10, 10));
	t2->insert_node_iteratively(tree2, Node<int, int>(20, 20));
	t2->insert_node_iteratively(tree2, Node<int, int>(5, 5));
	t2->insert_node_iteratively(tree2, Node<int, int>(6, 6));
	t2->insert_node_iteratively(tree2, Node<int, int>(1, 1));
	t2->insert_node_iteratively(tree2, Node<int, int>(8, 8));
	t2->insert_node_iteratively(tree2, Node<int, int>(30, 30));
	t2->insert_node_iteratively(tree2, Node<int, int>(14, 14));
	t2->insert_node_iteratively(tree2, Node<int, int>(3, 3));
	t2->insert_node_iteratively(tree2, Node<int, int>(2, 2));

	t2->print_tree_iteratively(tree2);
	
	std::cout << std::endl;

	std::cin >> x;

	t2->terminate_tree_iteratively(tree2);

	



	std::cin >> x;
	return 0;
}