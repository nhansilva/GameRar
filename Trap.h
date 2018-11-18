#ifndef _Trap_H_
#define _Trap_H_
#include "Object.h"

#define TRAP_IMAGE_FILE "Resources/ground/7.png"
#define TRAP_GRAVITY 1
#define TRAP_VY 3
#define sm_X 856

class CTrap : public CObject
{
	int Status, Waiting, Dy, sm;
public:
	CTrap(int x1, int y1, int w1, int h1);
	~CTrap();

	virtual void Update(GCamera *camera, int t);
	virtual void Draw(GCamera * cam);
	virtual void Go();
	virtual Box GetBox(GCamera *camera);
};
#endif
