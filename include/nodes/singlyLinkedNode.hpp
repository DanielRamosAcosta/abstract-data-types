/*!
 * \file singlyLinkedNode.hpp
 * \version 1.0
 * \date 30/05/2015
 * \author Daniel Ramos Acosta
 * \title Templated class singlyLinkedNode
 * \brief It contains the implementation of a simple linked node.
 * \code
 * //Example code
 *
 * template<class T>
 * class simpleLinkedList{
 *	private:
 *		singlyLinkedNode* begin_;
 *		singlyLinkedNode* end_;
 * public:
 *		//....
 * };
 *
 * \endcode
 */

#ifndef SINGLYLINKEDNODE
#define SINGLYLINKEDNODE

#include "nodes/node.hpp"

namespace dra{

	template<class T>
 	class singlyLinkedNode : public dra::node<T>{
		/*!
		* \class node<T>
		* \brief This class represents a node of a simple linked list based in a generic node.
		* \details
		*  This class represents a node of a simple linked list based in a generic node. The main
		*  usage for this class is in the class "simpleLinkedList", and acts as each of
		*  the list nodes.
		*/
	private:
		singlyLinkedNode* next_;

	public:
		/*! \name Constructors and Destructor*/
		///@{
		/*!
		* \brief This is the default constructor of the node.
		*/
		singlyLinkedNode(void);

		/*!
		* \brief This is the that receives a data that will be stored in the parent's class
		*/
		singlyLinkedNode(const T& data);

		/*!
		* \brief The destructor. Does nothing special.
		*/
		~singlyLinkedNode(void);
		///@}

		/*! \name Access methods*/
		///@{
		/*!
		* \brief Returns a reference to the pinter to the next node to modify it.
		* \return Returns a reference to the pointer to the next node, so it could be modified.
		*/
		singlyLinkedNode*& next(void);

		/*!
		* \brief Returns a copy of the pointer to the next node, so can be used in const-calls
		* \return Returns a copy of the pointer to the next node.
		*/
		singlyLinkedNode* next(void) const;
		///@}
	};

	template <class T>
	singlyLinkedNode<T>::singlyLinkedNode(void):
	node<T>(),
	next_(nullptr)
	{}

	template <class T>
	singlyLinkedNode<T>::singlyLinkedNode(const T& data):
	node<T>(data),
	next_(nullptr)
	{}

	template<class T>
	singlyLinkedNode<T>::~singlyLinkedNode(void)
	{}

	template<class T>
	singlyLinkedNode<T>*& singlyLinkedNode<T>::next(void)
	{
		return next_;
	}

	template<class T>
	singlyLinkedNode<T>* singlyLinkedNode<T>::next(void) const
	{
		return next_;
	}
}

#endif // SINGLYLINKEDNODE
