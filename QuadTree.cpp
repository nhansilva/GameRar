#include "QuadTree.h"
void QuadTree::ReadQuadTree(char * filename)
{
	ifstream file;
	file.open(filename, ios::in);
	int size, id, x, y, w, h, idobj, it;
	listObjInMap = new map<int, CDistinct*>();
	listNodeInMap = new map<int, CNode*>();
	listItemInMap = new map<int, CItems*>();
	file >> size;
	//Input: Doc chi so cua Object trong file
	//Output: Danh sach cac object co trong Map
	for (int i = 0; i < size; i++)
	{
		file >> id >> idobj >> x >> y >> w >> h >> it;
		CDistinct *obj = new CDistinct(idobj, x, y + fit, w, h);
		CItems *item = new CItems(it, x, y);
		listObjInMap->insert(pair<int, CDistinct*>(id, obj));
		listItemInMap->insert(pair<int, CItems*>(id, item));
	}

	//Input: Doc chi so cua mot node gom id, x1,x2,size(toa do va kich thuoc
	//cua quadtree)
	//Output: Tao ra mot danh sach node co trong map, dung de duyet o phan sau
	int id2, x1, y1, size2;

	//Đưa đối tượng vào node
	while (!file.eof())// phan nay chưa hiểu
	{
		file >> id2 >> x1 >> y1 >> size2;
		CNode* node = new CNode(x1, y1, size2);
		string stringNodeListObj;
		getline(file, stringNodeListObj);
		istringstream iss(stringNodeListObj, istringstream::in);
		while (iss >> id)
		{
			node->InsertObj(id, listObjInMap->find(id)->second);
		}
		listNodeInMap->insert(pair<int, CNode*>(id2, node));
	}
	file.close();
}

QuadTree::QuadTree(int State)
{
	QTState = State;
	listObj = new map<int, CDistinct*>();
	listItem = new map<int, CItems*>();
	switch (State)
	{
	case 1:
	{
		fit = 0;
		this->ReadQuadTree("./Resources/Maps/QT1.txt");
	}break;
	case 2:
	{
		fit = -32;
		this->ReadQuadTree("./Resources/Maps/QT2.txt");
	}break;
	case 22:
	{
		fit = -32;
		this->ReadQuadTree("./Resources/Maps/QT2b.txt");
	}break;
	case 23:
	{
		fit = -32;
		this->ReadQuadTree("./Resources/Maps/QT2c.txt");
	}break;
	case 3:
	{
	    fit = 0;
		this->ReadQuadTree("./Resources/Maps/QT3.txt");
	}break;
	case 31:
	{
		fit = 0;
		this->ReadQuadTree("./Resources/Maps/QT3b.txt");
	}break;
	case 32:
	{
		fit = 0;
		this->ReadQuadTree("./Resources/Maps/QT3c.txt");
	}break;
	case 33:
	{
		fit = 0;
		this->ReadQuadTree("./Resources/Maps/QT3d.txt");
	}break;
	case 34:
	{
		fit = 0;
		this->ReadQuadTree("./Resources/Maps/QT3e.txt");
	}break;
	case 35:
	{
		fit = 0;
		this->ReadQuadTree("./Resources/Maps/QT3f.txt");
	}break;
	}
	this->LoadQuadTree();
}

QuadTree::~QuadTree()
{

}

void QuadTree::LoadQuadTree()
{
	LoadNode(0, rootNode); // Load cây từ nút root có id =0
}

void QuadTree::LoadNode(int id, CNode*& rootnode)
{
	map<int, CNode*>::iterator rn = listNodeInMap->find(id);
	if (rn != listNodeInMap->end())
	{
		//đưa node vào cây
		rootnode = rn->second;
		LoadNode(id * 10 + 1, rootnode->tl);
		LoadNode(id * 10 + 2, rootnode->tr);
		LoadNode(id * 10 + 3, rootnode->bl);
		LoadNode(id * 10 + 4, rootnode->br);
	}
}

void QuadTree::UpdateQuadTree(GCamera *cam, int t)
{
	//UpdateNode(cam, rootNode, t);
	//this->getListObjInNode(cam);

	for (map<int, CDistinct*>::iterator obj = listObj->begin(); obj != listObj->end(); obj++)
	{
		obj->second->Update(cam, t);
		listItem->find(obj->first)->second->Update(t);
	}
}

void QuadTree::DrawQuadTree(GCamera* cam)
{
	//this->getListObjInNode(cam);
	for (map<int, CDistinct*>::iterator obj = listObj->begin(); obj != listObj->end(); obj++)
	{
		obj->second->Draw(cam);
		listItem->find(obj->first)->second->Draw(cam);
	}
}


void QuadTree::getListObjInNode(GCamera* cam)
{
	listObj->clear();
	listItem->clear();
	GetNode(rootNode, cam);
	int a = 0;
}

void QuadTree::GetNode(CNode* nodeturn, GCamera *cam)
{
	if (nodeturn->tl != NULL)
	{
		//Load node TOP LEFT
		if (cam->viewport.x < nodeturn->tr->getx() && cam->viewport.y < nodeturn->bl->gety())
		{
			GetNode(nodeturn->tl, cam);
		}

		//Load node TOP RIGHT
		if (cam->viewport.x + G_ScreenWidth > nodeturn->tr->getx() && cam->viewport.y > nodeturn->tr->gety())
		{
			GetNode(nodeturn->tr, cam);
		}

		//Load node BOTTON LEFT
		if (cam->viewport.x < nodeturn->br->getx() && cam->viewport.y - G_ScreenHeight < nodeturn->bl->gety())
		{
			GetNode(nodeturn->bl, cam);
		}

		//Load node BOTTON RIGHT
		if (cam->viewport.x + G_ScreenWidth > nodeturn->br->getx() && cam->viewport.y - G_ScreenHeight < nodeturn->br->gety())
		{
			GetNode(nodeturn->br, cam);
		}
	}
	else
	{
		for (map<int, CDistinct*>::iterator obj = nodeturn->getListObj()->begin(); obj != nodeturn->getListObj()->end(); obj++)
		{
			listObj->insert(pair<int, CDistinct*>(obj->first, obj->second));
			listItem->insert(pair<int, CItems*>(listItemInMap->find(obj->first)->first, listItemInMap->find(obj->first)->second));
		}
		return;
	}
}