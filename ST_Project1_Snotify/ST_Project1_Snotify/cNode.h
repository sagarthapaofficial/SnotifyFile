#ifndef cNode_HG_
#define cNode_HG_

#include "cPerson.h"

class cNode
{
public:
	cNode()
	{
		this->pNextNode = NULL;
		this->pPrevNode = NULL;
	}
	~cNode();

	// The actual data you want to hold
	cPerson thePerson;

	// Also has a pointer to the next node
	cNode* pNextNode;
	cNode* pPrevNode;
};

#endif
