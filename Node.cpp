#include "Node.h"

CNode::CNode()
{
	//id = 0;
	x = 0;
	y = 0;
	tl = NULL;
	tr = NULL;
	bl = NULL;
	br = NULL;
}

CNode::CNode(int x1, int y1, int s)
{
	x = x1;
	y = y1;
	size = s;
	tl = NULL;
	tr = NULL;
	bl = NULL;
	br = NULL;
	listObj = new map<int, CDistinct*>;
}

void CNode::InsertObj(int a, CDistinct* obj)
{
	listObj->insert(pair<int, CDistinct*>(a, obj));
}

CNode::~CNode()
{

}