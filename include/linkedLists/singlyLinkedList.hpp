/*!
 * \file singlyLinkedList.hpp
 * \version 1.0
 * \date 24/04/2015
 * \author Daniel Ramos Acosta
 * \title Templated class singlyLinkedList
 * \brief It contains a generic singlyLinkedList implementation.
 * \code
 * //Example code
 *
 * dra::singlyLinkedList<int> mylist;
 *
 *	mylist.push_back(new dra::singlyLinkedNode<int>(1));
 *	mylist.push_back(new dra::singlyLinkedNode<int>(2));
 *	mylist.push_back(new dra::singlyLinkedNode<int>(3));
 *	
 *	mylist.push_front(new dra::singlyLinkedNode<int>(4));
 *	mylist.push_front(new dra::singlyLinkedNode<int>(5));
 *
 *	mylist.toStream(std::cout);
 *	std::cout << std::endl;
 *
 *	delete mylist.extract_front();
 *	delete mylist.extract_front();
 *
 *	mylist.toStream(std::cout);
 *	std::cout << std::endl;
 *
 * \endcode
 */

#ifndef SINGLYLINKEDLIST
#define SINGLYLINKEDLIST

#include "nodes/singlyLinkedNode.hpp"
#include "utils/exceptions.hpp"

#include <iostream>

namespace dra{

	template<class T>
 	class singlyLinkedList{
 		/*!
		* \class singlyLinkedList<T>
		* \brief This class represents the singly linked list data type.
		* \details
		*  Singly linked lists contain nodes which have a data field as well as
		*  a 'next' field, which points to the next node in line of nodes.
		*  Operations that can be performed on singly linked lists include
		*  insertion, deletion and traversal.
		*/
	private:
		singlyLinkedNode<T>* head_;
		singlyLinkedNode<T>* tail_;
	private:
		void first(singlyLinkedNode<T>*);
	public:
		/*! \name Constructors and Destructor*/
		///@{
		/*!
		* \brief This is the default constructor of the singly linked list.
		*/
		singlyLinkedList(void);

		/*!
		* \brief The destructor.
		*/
		~singlyLinkedList(void);
		///@}

		void insert_back(singlyLinkedNode<T>*);
		void insert_front(singlyLinkedNode<T>*);
		void insert_pos(singlyLinkedNode<T>*, unsigned);
		void insert_pos(singlyLinkedNode<T>*, int);

		singlyLinkedNode<T>* extract_back(void);
		singlyLinkedNode<T>* extract_front(void);
		singlyLinkedNode<T>* extract_pos(unsigned);
		singlyLinkedNode<T>* extract_pos(int);

		bool empty(void) const;

		singlyLinkedList<T>& operator=(const singlyLinkedList<T>&);

		std::ostream& toStream(std::ostream&) const;
	};

	template<class T>
	singlyLinkedList<T>::singlyLinkedList(void):
	head_(nullptr),
	tail_(nullptr)
	{}

	template<class T>
	singlyLinkedList<T>::~singlyLinkedList(void)
	{
		singlyLinkedNode<T>* tmp = head_;
		while(head_ != nullptr)
		{
			head_ = head_->next();
			delete tmp;
			tmp = head_;
		}
	}

	template<class T>
	void singlyLinkedList<T>::first(singlyLinkedNode<T>* node)
	{
		node->next() = nullptr;
		head_ = node;
		tail_ = node;
	}

	template<class T>
	bool singlyLinkedList<T>::empty(void) const
	{
		return (head_ == nullptr);
	}

	template<class T>
	void singlyLinkedList<T>::insert_back(singlyLinkedNode<T>* node)
	{
		if(empty()) first(node);
		else{
			node->next() = nullptr;
			tail_->next() = node;
			tail_ = node;
		}
	}

	template<class T>
	void singlyLinkedList<T>::insert_front(singlyLinkedNode<T>* node)
	{
		if(empty()) first(node);
		else{
			node->next() = head_;
			head_ = node;
		}
	}

	template<class T>
	void singlyLinkedList<T>::insert_pos(singlyLinkedNode<T>* node, unsigned pos)
	{
		std::cout << "Voy a introducr un nodo en " << pos << std::endl;

		if(pos == 0){
			insert_front(node);
			return;
		}

		if(empty()) throw exception::access_error(pos);

		singlyLinkedNode<T>* tmp = head_;
		unsigned npos = pos-1;
		while(npos != 0){
			if(tmp->next() == nullptr)
				throw exception::access_error(pos);
			else{
				tmp = tmp->next();
				npos--;
			}
		}

		if(tmp == tail_){
			insert_back(node);
			return;
		}

		node->next() = tmp->next();
		tmp->next() = node;
	}

	template<class T>
	void singlyLinkedList<T>::insert_pos(singlyLinkedNode<T>* node, int pos)
	{
		if(pos < 0)
			throw exception::length_error();
		else
			insert_pos(node, unsigned(pos));
	}

	template<class T>
	singlyLinkedNode<T>* singlyLinkedList<T>::extract_back(void)
	{
		if(empty()) throw exception::length_error("List was empty");

		singlyLinkedNode<T>* tmp = head_;
		if(head_ == tail_){
			head_ = nullptr;
			tail_ = nullptr;
		}
		else{
			while(tmp->next() != nullptr)
				tmp = tmp->next();
			tail_ = tmp;
			tmp = tmp->next();
			tail_->next() = nullptr;
		}
		return tmp;
	}

	template<class T>
	singlyLinkedNode<T>* singlyLinkedList<T>::extract_front(void)
	{
		if(empty()) throw exception::length_error("List was empty");

		singlyLinkedNode<T>* tmp = head_;
		if(head_ == tail_){
			head_ = nullptr;
			tail_ = nullptr;
		}
		else{
			head_ = head_->next();
			tmp->next() = nullptr;
		}
		return tmp;
	}

	template<class T>
	singlyLinkedNode<T>* singlyLinkedList<T>::extract_pos(unsigned pos)
	{
		if(pos == 0)
			return extract_front();

		if(empty()) throw exception::length_error("List was empty");
	}

	template<class T>
	std::ostream& singlyLinkedList<T>::toStream(std::ostream& os) const
	{
		singlyLinkedNode<T>* tmp = head_;
		while(tmp != nullptr)
		{
			os << "["<< tmp->data() << "][" << tmp << "]";
			if(tmp->next() != nullptr)
				os << "->";
			tmp = tmp->next();
		}
		return os;
	}
}

#endif // SINGLYLINKEDLIST