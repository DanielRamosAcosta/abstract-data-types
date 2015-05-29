#include <iostream>
#include "nodes/binaryNode.hpp"

int main(void)
{
	dra::binaryNode<int>* m_lft = new dra::binaryNode<int>(8);
	dra::binaryNode<int>* m_rht = new dra::binaryNode<int>(2);


	dra::binaryNode<int>* root = new dra::binaryNode<int>(3);

	root->left() = m_lft;
	root->right() = m_rht;

	delete m_lft;
	delete m_rht;
	delete root;
}
