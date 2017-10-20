#pragma once

#include "Node.h"
#include <stack>

//Template declaration

template <typename E, typename T>
class BinarySearchTree
{

public:

	BinarySearchTree();

	~BinarySearchTree();

	//Recursive functions
	void insert_node_recursively(Node<E, T>** tree, Node<E, T> node);
	void print_tree_recursively(Node<E, T>** tree);
	void terminate_tree_recursively(Node<E, T>** tree);
	void delete_node_recursively(Node<E, T>** tree, Node<E, T> node);


	
	//Iterative functions
	void insert_node_iteratively(Node<E, T>** tree, Node<E, T> node);
	void print_tree_iteratively(Node<E, T>** tree);
	void terminate_tree_iteratively(Node<E, T>** tree);
	void delete_node_iteratively(Node<E, T>** tree, Node<E, T> node);





};


//Template implementation

template <typename E, typename T>
BinarySearchTree<E, T>::BinarySearchTree()
{

}

template <typename E, typename T>
BinarySearchTree<E, T>::~BinarySearchTree()
{

}

template <typename E, typename T>
void BinarySearchTree<E, T>::insert_node_recursively(Node<E, T>** tree, Node<E, T> node)
{
	if ((*tree) == nullptr)
	{
		(*tree) = new Node<E, T>(node);
	}

	if (node.key > (*tree)->key)
	{
		if ((*tree)->right == nullptr)
		{
			(*tree)->right = new Node<E, T>(node);
		}
		else
		{
			insert_node_recursively(&((*tree)->right), node);
		}
	}

	if (node.key < (*tree)->key)
	{
		if ((*tree)->left == nullptr)
		{
			(*tree)->left = new Node<E, T>(node);
		}
		else
		{
			insert_node_recursively(&((*tree)->left), node);
		}
	}
}

template <typename E, typename T>
void BinarySearchTree<E, T>::print_tree_recursively(Node<E, T>** tree)
{
	if ((*tree)->left != nullptr)
	{
		print_tree_recursively(&(*tree)->left);
	}

	std::cout << (*tree)->value << " ";

	if ((*tree)->right != nullptr)
	{
		print_tree_recursively(&(*tree)->right);
	}
}

template <typename E, typename T>
void BinarySearchTree<E, T>::terminate_tree_recursively(Node<E, T>** tree)
{
	if ((*tree)->left != nullptr)
	{
		terminate_tree_recursively(&(*tree)->left);
	}

	if ((*tree)->right != nullptr)
	{
		terminate_tree_recursively(&(*tree)->right);
	}

	delete (*tree);
	(*tree) = nullptr;
}

template <typename E, typename T>
void BinarySearchTree<E, T>::insert_node_iteratively(Node<E, T>** tree, Node<E, T> node)
{
	if ((*tree) == nullptr)
	{
		(*tree) = new Node<E, T>(node);
		return;
	}

	Node<E, T>* root = (*tree);

	while (root != nullptr)
	{
		if (node.key > root->key)
		{
			if (root->right == nullptr)
			{
				root->right = new Node<E, T>(node);
				return;
			}
			root = root->right;
			continue;
		}

		if (node.key < root->key)
		{
			if (root->left == nullptr)
			{
				root->left = new Node<E, T>(node);
				return;
			}
			root = root->left;
		}
	}
}

template <typename E, typename T>
void BinarySearchTree<E, T>::print_tree_iteratively(Node<E, T>** tree)
{
	std::stack<Node<E, T>*> s;

	Node<E, T>* node = (*tree);

	bool done = false;

	while (!done)
	{
		while (node != nullptr)
		{
			s.push(node);

			node = node->left;
		}

		if (node == nullptr && (!s.empty()))
		{
			node = s.top();
			s.pop();

			std::cout << node->value << " ";

			node = node->right;
		}

		if (node == nullptr && s.empty())
		{
			done = true;
		}
	}
}

template <typename E, typename T>
void BinarySearchTree<E, T>::terminate_tree_iteratively(Node<E, T>** tree)
{
	std::stack<Node<E, T>*> s;

	Node<E, T>* node = (*tree);

	bool done = false;

	while (!done)
	{
		while (node != nullptr)
		{
			if (node->right)
			{
				s.push(node->right);
			}
			s.push(node);
			node = node->left;
		}

		node = s.top();
		s.pop();

		if (node->right && !s.empty() && node->right == s.top())
		{
			s.pop();
			s.push(node);
			node = node->right;
		}
		else
		{
			delete node;
			node = nullptr;
		}


		if (s.empty())
		{
			done = true;
		}

	}
}