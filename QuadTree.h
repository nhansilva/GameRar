#pragma once
#include "GCamera.h"
#include <map>
#include <list>
#include "Object.h"
#include "Node.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Items.h"
using namespace std;
class QuadTree
{
private:
	map<int, CDistinct*> *listObjInMap;
	map<int, CNode*> *listNodeInMap;
	map<int, CDistinct*> *listObj;
	//=============================================
	map<int, CItems*> *listItem;
	CNode *rootNode;
	int fit = 0;
	void GetNode(CNode* nodeturn, GCamera *cam);
	int QTState = -1;
public:
	map<int, CItems*> *listItemInMap;
	void getListObjInNode(GCamera* cam);
	void ReadQuadTree(char * filename);
	void LoadQuadTree();
	void LoadNode(int id, CNode*& rootnode);
	void UpdateQuadTree(GCamera *camera, int t);
	void DrawQuadTree(GCamera *camera);
	map<int, CDistinct*> *GetListObj() { return listObj; };
	map<int, CItems*> *getListItem() { return listItem; };
	map<int, CDistinct*> *getListObjInMap() { return listObjInMap; }
	QuadTree(int State);
	int getQT() { return QTState; }
	~QuadTree();
};
