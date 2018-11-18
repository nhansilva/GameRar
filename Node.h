#define _NODE_H_
#include <map>
#include "Distinct.h"
using namespace std;

class CNode
{
private:
	int x;		   //Tọa độ ox của node
	int y;		   //Tọa độ oy của node
	int size;      //Kích thước của quad tree
	map<int, CDistinct*> *listObj = new map<int, CDistinct*>(); //Danh sách đối tượng có trong một node quadtree
public:
	CNode *tl, *tr, *bl, *br;
	CNode();
	~CNode();

	int			getx() { return this->x; }
	void		setx(int x1) { x = x1; }

	int			gety() { return this->y; }
	void		sety(int x1) { y = x1; }

	int			getsize() { return this->size; }
	void		setsize(int x1) { size = x1; }

	//TOP - LEFT
	CNode*		gettl() { return this->tl; }
	void		settl(CNode* x) { this->tl = x; }

	//TOP - RIGHT
	CNode*		gettr() { return this->tr; }
	void		settr(CNode* x) { this->tr = x; }

	//BOTTOM - LEFT
	CNode*		getbl() { return this->bl; }
	void		setbl(CNode* x) { this->bl = x; }

	//BOTTOM - RIGHT
	CNode*		getbr() { return this->br; }
	void		setbr(CNode* x) { this->br = x; }

	CNode(int x1, int y1, int s);
	map<int, CDistinct*> *getListObj() { return this->listObj; }

	void		InsertObj(int a, CDistinct* obj);
};
