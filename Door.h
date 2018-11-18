#ifndef _DOOR_H_
#define _DOOR_H_
#include"Object.h"

#define DOOR_IMAGE_FILE_1 "Resources/ground/10.png"
#define DOOR_IMAGE_FILE_2 "Resources/ground/10-3.png"
#define DOOR_FRAME 80

class CDoor :public CObject
{
	GSprite * DoorOpen;
public:
	CDoor(int x1, int y1, int w1, int h1);
	~CDoor();
	virtual void Update(int t);
	void virtual Draw(GCamera *camera);
	virtual Box GetBox(GCamera * camera);
};
#endif