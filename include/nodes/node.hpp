/*!
 * \file node.hpp
 * \version 1.0
 * \date 24/04/2015
 * \author Daniel Ramos Acosta
 * \title Templated class node
 * \brief It contains a generic node implementation.
 * \code
 * //Example code
 *
 * template<class T>
 * class listNode : public dra::node<T>{
 *	private:
 *		listNode* next_;
 *		listNode* prev_;
 * public:
 *		//....
 * };
 *
 * \endcode
 */

#ifndef NODE
#define NODE

namespace dra{

	template<class T>
 	class node{
		/*!
		* \class node<T>
		* \brief This class represents a generic node.
		* \details
		* This class represents a generic node of a graph. For using this class, you
		* may inherit this class and add the links you wants. It could be used in a linked
		* list, in a binary tree or in any type of graphs.
		*/
	private:
		T data_;
	public:
		/*! \name Constructors and Destructor*/
		///@{
		/*!
		* \brief This is the default constructor of the node.
		*/
		node(void);

		/*!
		* \brief The constructor that places some data in the node.
		* \param data Is the actual data that's going to be placed in the node.
		*/
		node(const T& data);

		/*!
		* \brief The destructor. Does nothing special.
		*/
		~node(void);
		///@}

		/*! \name Access methods*/
		///@{
		/*!
		* \brief Returns a reference to the data to modify it.
		* \return Returns a reference to the data, so it could be modified.
		*/
		T& data(void);

		/*!
		* \brief Returns a copy of the data of the node, so can be used in const-calls
		* \return Returns a copy of the data of the node.
		*/
		T data(void) const;
		///@}
	};

	template<class T>
	node<T>::node(void)
	{}

	template<class T>
	node<T>::node(const T& data):
	data_(data)
	{}

	template<class T>
	node<T>::~node(void)
	{}

	template<class T>
	T& node<T>::data(void)
	{
		return data_;
	}

	template<class T>
	T node<T>::data(void) const
	{
		return data_;
	}
}

#endif // NODE
