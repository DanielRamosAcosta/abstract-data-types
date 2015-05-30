/*!
 * \file doublyLinkedNode.hpp
 * \version 1.0
 * \date 29/05/2015
 * \author Daniel Ramos Acosta
 * \title Templated class doublyLinkedNode
 * \brief It contains a binary node implementation.
 * \code
 * //Example code
 *
 * template<class T>
 * class binaryTree{
 *	private:
 *		doublyLinkedNode* root_;
 * public:
 *		//....
 * };
 *
 * \endcode
 */

#ifndef DOUBLYLINKEDNODE
#define DOUBLYLINKEDNODE

#include "nodes/node.hpp"

 namespace dra{

	template<class T>
 	class doublyLinkedNode : public dra::node<T>{
		/*!
		* \class node<T>
		* \brief This class represents a binary node based in a generic node.
		* \details
		*  This class represents a binary node based in a generic node. The main
		*  usage for this class is in the class "binaryTree", and acts as each of
		*  the tree nodes.
		*/
	private:
		doublyLinkedNode* next_;
		doublyLinkedNode* prev_;

	public:
		/*! \name Constructors and Destructor*/
		///@{
		/*!
		* \brief This is the default constructor of the node.
		*/
		doublyLinkedNode(void);

		/*!
		* \brief This is the that receives a data that will be stored in the parent's class
		*/
		doublyLinkedNode(const T& data);

		/*!
		* \brief The destructor. Does nothing special.
		*/
		~doublyLinkedNode(void);
		///@}

		/*! \name Access methods*/
		///@{
		/*!
		* \brief Returns a reference to the pinter to the next node to modify it.
		* \return Returns a reference to the pointer to the next node, so it could be modified.
		*/
		doublyLinkedNode*& next(void);

		/*!
		* \brief Returns a copy of the pointer to the next node, so can be used in const-calls
		* \return Returns a copy of the pointer to the next node.
		*/
		doublyLinkedNode* next(void) const;

		/*!
		* \brief Returns a reference to the pinter to the prev node to modify it.
		* \return Returns a reference to the pointer to the prev node, so it could be modified.
		*/
		doublyLinkedNode*& prev(void);

		/*!
		* \brief Returns a copy of the pointer to the previous node, so can be used in const-calls
		* \return Returns a copy of the pointer to the previous node.
		*/
		doublyLinkedNode* prev(void) const;
		///@}
	};

	template <class T>
	doublyLinkedNode<T>::doublyLinkedNode(void):
	node<T>(),
	next_(nullptr),
	prev_(nullptr)
	{}

	template <class T>
	doublyLinkedNode<T>::doublyLinkedNode(const T& data):
	node<T>(data),
	next_(nullptr),
	prev_(nullptr)
	{}

	template<class T>
	doublyLinkedNode<T>::~doublyLinkedNode(void)
	{}

	template<class T>
	doublyLinkedNode<T>*& doublyLinkedNode<T>::next(void)
	{
		return next_;
	}

	template<class T>
	doublyLinkedNode<T>* doublyLinkedNode<T>::next(void) const
	{
		return next_;
	}

	template<class T>
	doublyLinkedNode<T>*& doublyLinkedNode<T>::prev(void)
	{
		return prev_;
	}

	template<class T>
	doublyLinkedNode<T>* doublyLinkedNode<T>::prev(void) const
	{
		return prev_;
	}
}

#endif // DOUBLYLINKEDNODE
