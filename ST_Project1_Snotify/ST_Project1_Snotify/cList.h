#ifndef _LinkedList_HG_
#define _LinkedList_HG_
#include "cNode.h"
#include <Assert.h>
#include <iostream>
template < class T, class U>

// This is linked list

class clinkedList
{
public:
	clinkedList()
	{
		this->pFirstNode = NULL;
		this->pCurrentNode = NULL;
		this->pLastNode = NULL;
		this->numberofNodes = 0;

	}
	~clinkedList()
	{

	}

	// Note these are all pointers
	cNode* pFirstNode;
	cNode* pLastNode;
	cNode* pCurrentNode;
	int numberofNodes;



	void InsertAtFront(T dataToInsert)
	{

		this->pCurrentNode = new cNode();
		if (pFirstNode == NULL)
		{
			pFirstNode = pCurrentNode;
			pCurrentNode->data = dataToInsert;
			pCurrentNode->pNextNode = NULL;
			pCurrentNode->pPrevNode = NULL;
			pLastNode = pCurrentNode;
		}
		else
		{
			pCurrentNode->pNextNode = pFirstNode;
			pCurrentNode->data = dataToInsert;
			pCurrentNode->pPrevNode = NULL;
			// first node previous node to currentNode
			pFirstNode->pPrevNode = pCurrentNode;
			pFirstNode = pCurrentNode;

		}
		numberofNodes++;
	}

	// Add element to the last
	void AddLast(T dataToInsert)
	{

		this->pCurrentNode = new cNode();
		pCurrentNode->data = dataToInsert;

		//// inserts data
		//this->pCurrentNode->data = dataToInsert;
		// if the firstnode is null and sets the previous node to null
		if (pFirstNode == NULL)
		{
			pFirstNode = pCurrentNode;
			pCurrentNode->pNextNode = NULL;
			pCurrentNode->pPrevNode = NULL;
			pLastNode = pCurrentNode;
		}
		else
		{
			// sets the previous Node of the current node to point to the lastnode
			pCurrentNode->pPrevNode = pLastNode;
			pLastNode->pNextNode = pCurrentNode;
			pCurrentNode->pNextNode = NULL;
			pLastNode = pCurrentNode;
		}

		numberofNodes++;
	}

	// Insert at the "current" location
	void Insert(T dataToInsert)
	{
		// Do I have any nodes, yet (like is this the 1st insert)
		// Note: since NULL=0, and if respond to false == 0, 
		//       or if ( ! this->pCurrentNode )
		// then comparing a pointer tells if it's valid

		if (this->pFirstNode == NULL)
		{
			// No nodes, insert the 1st node
			this->pCurrentNode = new cNode;
			// Also set the start and end
			this->pFirstNode = this->pCurrentNode;
			this->pLastNode = this->pCurrentNode;
			this->pCurrentNode->data = dataToInsert;
		}

		// I'm have 1 or more nodes, but I want to add another one.
		// Create a new node at the current one
		// TODO: 
		// 1. Make a new node
		cNode* pNewNode = new cNode();
		// 2. Put the person at that node
		pNewNode->data = dataToInsert;

		// 3. Add this node to the "current" node
		this->pCurrentNode->pNextNode = pNewNode;

		// 5. Doubly linked list - point to previous node, too
		pNewNode->pPrevNode = this->pCurrentNode;

		// 4. Point the "current" to this new node
		this->pCurrentNode = pNewNode;
		// TODO: Maybe look into updating the "last node" (or "tail") as well
		// Question: How do we do this? 
		// Hint: Did we just update the last node? If so, then fix it.
		pLastNode = pCurrentNode;

		numberofNodes++;
		return;
	}

	// Prints in the forward order

	void printList()
	{
		cNode* temp;
		temp = pFirstNode;
		while (temp != NULL)
		{
			std::cout << "Value:" << temp->data << std::endl;
			temp = temp->pNextNode;
		}
	}


	// Prints in the reverse order

	void PrintReverse()
	{

		cNode* temp;
		temp = pLastNode;
		while (temp != NULL)
		{
			std::cout << "Value: " << temp->data << std::endl;
			temp = temp->pPrevNode;
		}


	}

	// Deletes the first node
	void deleteFirst()
	{

		if (pFirstNode == NULL)
		{
			return;
		}

		if (pFirstNode == pLastNode)
		{
			cNode* temp;
			temp = pFirstNode;
			pFirstNode = NULL;
			pLastNode = NULL;
			delete temp;
			return;
		}
		else
		{
			cNode* temp;
			temp = pFirstNode;
			// making the second node or the next NOde the firstNode
			pFirstNode = pFirstNode->pNextNode;
			pFirstNode->pPrevNode = NULL;
			delete temp;
		}

		numberofNodes--;
	}

	void deleteLast()
	{

		if (pFirstNode == NULL)
		{
			return;
		}

		if (pFirstNode == pLastNode)
		{
			cNode* temp;
			// pointer to the pFirstNode;
			temp = pFirstNode;

			// setting both the first and last pointer to null
			pFirstNode = NULL;
			pLastNode = NULL;

			delete temp;
		}
		else
		{

			cNode* temp;
			temp = pLastNode;
			// setting the lastNode as the previous node of the last node
			pLastNode = pLastNode->pPrevNode;
			pLastNode->pNextNode = NULL;
			delete temp;

		}
		numberofNodes--;
	}

	// Inserting data before a particular node
	void insertBeforeNode(cNode* prevNode, T dataToInsert)
	{

		this->pCurrentNode = new cNode();
		// inserting data to the node
		pCurrentNode->data = dataToInsert;
		// current node next node is the node
		pCurrentNode->pNextNode = prevNode;
		//current node previous node is give node previous node 
		pCurrentNode->pPrevNode = prevNode->pPrevNode;
		// now given node previous node is current node 
		prevNode->pPrevNode = pCurrentNode;

		// checks if the previous node of given node is null
		if (prevNode->pPrevNode == NULL)
		{
			pFirstNode = pCurrentNode;
		}

	}

	// Inserting data after a particular node

	void InsertAfterNode(cNode* node, T dataToInsert)
	{
		if (node == NULL)
		{
			std::cout << "The give node cannot be null" << std::endl;
			return;
		}

		this->pCurrentNode = new cNode();
		pCurrentNode->data = dataToInsert;
		// previous node is the given node
		pCurrentNode->pPrevNode = node;
		// next node is the next node of given node
		pCurrentNode->pNextNode = node->pNextNode;
		node->pNextNode = pCurrentNode;

		// checks if the next node of the given node in null
		if (node->pNextNode == NULL)
		{
			pLastNode = pCurrentNode;

		}

		numberofNodes++;
	}


	// Deleting a node
	void deleteItem(U element)
	{
		cNode* temp;
		temp = pFirstNode;

		if (pFirstNode == pLastNode)
		{
			// checks if the firstNOde data is equal to the element
			if (pFirstNode->data != element)
			{
				std::cout << "Could not delete" << std::endl;
				return;
			}

			pFirstNode = NULL;
			pLastNode = NULL;
			delete temp;
			return;
		}

		if (pFirstNode->data == element)
		{
			pFirstNode = pFirstNode->pNextNode;
			pFirstNode->pPrevNode = NULL;
			delete temp;
			return;

		}
		else if (pLastNode->data == element)
		{
			temp = pLastNode;
			pLastNode = pLastNode->pPrevNode;
			pLastNode->pNextNode = NULL;
			delete temp;
			return;

		}

		while (temp->data != element)
		{
			temp = temp->pNextNode;
			if (temp == NULL)
			{
				std::cout << "Could not find the element to delete " << std::endl;
				return;
			}
		}
		temp->pPrevNode->pNextNode = temp->pNextNode;
		temp->pNextNode->pPrevNode = temp->pPrevNode;


		delete temp;

	}
	// Get Current Element
	int getValue(U index)
	{

		cNode* temp;
		temp = pFirstNode;
		int count = 0;
		while (temp != NULL)
		{
			if (count == index)
			{
				return temp->data;

			}
			count++;
			temp = temp->pNextNode;
		}
		// if it is still not found than Assert fail
		assert(0);
	}





	// Searches an element on the list

	bool searchElement(T element)
	{
		cNode* temp;
		temp = pFirstNode;

		while (temp != NULL)
		{
			if (temp->data == element)
			{
				return true;
				break;
			}
			temp = temp->pNextNode;
		}


		return false;
	}


	// Gets the number of nodes
	int GetNumberOfNodes(void)
	{
		return numberofNodes;


	}
	// Moves the currentNode to the front
	void MoveAtFront()
	{
		this->pCurrentNode = pFirstNode;


	}

	// Moves the current Node to the next node 
	bool MoveNext()
	{
		if (this->pCurrentNode == NULL)
		{
			return false;
		}

		if (this->pCurrentNode->pNextNode != NULL)
		{
			this->pCurrentNode = this->pCurrentNode->pNextNode;
		}



	}


	// Moves the currennt to the previos node
	bool MovePrevious()
	{

		if (this->pCurrentNode == NULL)
		{

			return false;
		}

		this->pCurrentNode = this->pCurrentNode->pPrevNode;


	}


	// Moves theh currentNOde to the lastNode
	void MoveAtLast()
	{
		this->pCurrentNode = pLastNode;
	}


};
#endif
