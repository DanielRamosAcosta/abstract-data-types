/*!
 * \file binaryNode.hpp
 * \version 1.0
 * \date 29/05/2015
 * \author Daniel Ramos Acosta
 * \title Templated class binaryNode
 * \brief It contains a binary node implementation.
 * \code
 * //Example code
 *
 * template<class T>
 * class binaryTree{
 *	private:
 *		binaryNode* root_;
 * public:
 *		//....
 * };
 *
 * \endcode
 */

#ifndef BINARYNODE
#define BINARYNODE

#include "nodes/node.hpp"

 namespace dra{

	template<class T>
 	class binaryNode : public dra::node<T>{
		/*!
		* \class node<T>
		* \brief This class represents a binary node based in a generic node.
		* \details
		*  This class represents a binary node based in a generic node. The main
		*  usage for this class is in the class "binaryTree", and acts as each of
		*  the tree nodes.
		*/
	private:
		binaryNode* left_;
		binaryNode* right_;

	public:
		/*! \name Constructors and Destructor*/
		///@{
		/*!
		* \brief This is the default constructor of the node.
		*/
		binaryNode(void);

		/*!
		* \brief This is the that receives a data that will be stored in the parent's class
		*/
		binaryNode(const T data);

		/*!
		* \brief The destructor. Does nothing special.
		*/
		~binaryNode(void);
		///@}

		/*! \name Access methods*/
		///@{
		/*!
		* \brief Returns a reference to the pinter to the left node to modify it.
		* \return Returns a reference to the pointer to the left node, so it could be modified.
		*/
		binaryNode*& left(void);

		/*!
		* \brief Returns a copy of the pointer to the left node, so can be used in const-calls
		* \return Returns a copy of the pointer to the left node.
		*/
		binaryNode* left(void) const;

		/*!
		* \brief Returns a reference to the pinter to the right node to modify it.
		* \return Returns a reference to the pointer to the right node, so it could be modified.
		*/
		binaryNode*& right(void);

		/*!
		* \brief Returns a copy of the pointer to the right node, so can be used in const-calls
		* \return Returns a copy of the pointer to the right node.
		*/
		binaryNode* right(void) const;
		///@}
	};

	template <class T>
	binaryNode<T>::binaryNode(void):
	node<T>(),
	left_(nullptr),
	right_(nullptr)
	{}

	template <class T>
	binaryNode<T>::binaryNode(const T data):
	node<T>(data),
	left_(nullptr),
	right_(nullptr)
	{}

	template<class T>
	binaryNode<T>::~binaryNode(void)
	{}

	template<class T>
	binaryNode<T>*& binaryNode<T>::left(void)
	{
		return left_;
	}

	template<class T>
	binaryNode<T>* binaryNode<T>::left(void) const
	{
		return left_;
	}

	template<class T>
	binaryNode<T>*& binaryNode<T>::right(void)
	{
		return right_;
	}

	template<class T>
	binaryNode<T>* binaryNode<T>::right(void) const
	{
		return right_;
	}
}

#endif // BINARYNODE
