#include "SceneMain.h"
#include "Map.h"
SceneMain::SceneMain(int _nCmdShow) : CGame(_nCmdShow)
{
}

void SceneMain::RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int t)
{
	minT++;
	if (minT > 30)
	{
		score->Calculator1Sec();
		minT = -1;
	}
	if (eatOrb) {// xu ly an trứng simon delay 1 khoan thoi gian tinh diem chuan bi chuyen sang man khac
		minC++;
		if (minC > 60) {
			minS++;
			if (minS > 0) {
				score->CalculatorOrb();
				minS = -1;
				simon->Stop();
				stopsimon = true;
			}
			minC = 61;
		}
	}
	
	d3ddv->ColorFill(G_BackBuffer, NULL, D3DCOLOR_XRGB(0, 0, 0));
	G_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	maps->DrawMap(cam, State);
	{

		if (EndingScene == 1 || stepOpenTheGate == 2)//Kiểm tra khi va chạm cổng màn 1 thì tự động di chuyển vào cổng không cần nhấn nút
			simon->Go();
		//Kiểm tra khi simon va chạm item là IWhip thì vẽ màu sắc mới cho simon
		if (CollectMorningStar == 0)
		{
			simon->Update(cam, t);
		}
		else
		{
			//CollectMorningStar++;
			//if (CollectMorningStar == 21) CollectMorningStar = 0;
		}
		RenderStage(d3ddv, State);
		UpdateObject(cam, t);
	}
	G_SpriteHandler->End();
}


void SceneMain::ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta)
{
	if (IsKeyDown(DIK_1)) { State = 1; LoadMap1(); }
	if (IsKeyDown(DIK_2)) { State = 2; LoadMap2(); }
	if (IsKeyDown(DIK_Z)) { score->SetSimonBlood(100); }
	if (IsKeyDown(DIK_X)) { score->SetSimonBlood(16); }
	if (IsKeyDown(DIK_C)) { score->SetEnemyBlood(4); }
	if (IsKeyDown(DIK_TAB))
	{
		score->SetHeart(10);
	}
	
	if (stopsimon == false) {
		if (isOpenTheGate) return;
		if (simon->GetOnStair()) {
			MoveCamera(IsKeyDown(DIK_UP), IsKeyDown(DIK_DOWN));
			if (simon->stairTrend == -1)
			{
				if (IsKeyDown(DIK_LEFT) || IsKeyDown(DIK_DOWN))
				{
					simon->MoveLeft();
					simon->Go();
				}
				if (IsKeyDown(DIK_RIGHT) || IsKeyDown(DIK_UP))
				{
					simon->MoveRigh();
					simon->Go();
				}
			}
			else // stairtrend
			{
				if (IsKeyDown(DIK_RIGHT) || IsKeyDown(DIK_DOWN))
				{
					simon->MoveRigh();
					simon->Go();
				}
				if (IsKeyDown(DIK_LEFT) || IsKeyDown(DIK_UP))
				{
					simon->MoveLeft();
					simon->Go();
				}
			}

			if (!IsKeyDown(DIK_LEFT) && !IsKeyDown(DIK_DOWN) && !IsKeyDown(DIK_RIGHT) && !IsKeyDown(DIK_UP) && !(simon->Auto))
			{
				simon->Stop();
			}
			if (IsKeyDown(DIK_T)) {
				if (simon->getAttacking() == 0) {
					simon->Attack(weapons.at(0)); 
				}
			}
		}
		else {
			if (IsKeyDown(DIK_LEFT))
			{
				simon->MoveLeft();
				simon->Go();
			}
			if (IsKeyDown(DIK_RIGHT))
			{
				simon->MoveRigh();
				simon->Go();
			}

			if (!IsKeyDown(DIK_LEFT) && !IsKeyDown(DIK_RIGHT) && !(simon->Auto)) // simon->autu == 0
			{
				simon->Stop();
			}
			if (IsKeyDown(DIK_SPACE) && !IsKeyDown(DIK_DOWN)) {
				simon->Jump();
			}
			if (!IsKeyDown(DIK_SPACE) && IsKeyDown(DIK_DOWN)) {
				simon->Sit();
			}
			if (IsKeyDown(DIK_T)) {
				if (simon->getAttacking() == 0) {
					simon->Attack(weapons.at(0));
					
				}
			}
			//////////////

			//Dùng vũ khí
			if (IsKeyDown(DIK_Y)) {
				if (simon->getAttacking() == 0) {
					if (typeWeapon == 1)
						weapons.push_back(new CSword());
					//Tính trái tim trừ điểm
					if (score->GetHeart() > 0 && typeWeapon != 0)
						simon->Attack(weapons.back());  
					if (typeWeapon != 0 && score->GetHeart() > 0) {
						score->_Heart--; 
					}
				}
			}

			if (IsKeyDown(DIK_UP)) {
				if (PreUpStair == 0) {
					simon->isUpStair = 1;
				}
			}
			else {
				simon->isUpStair = 0;
			}
			if (IsKeyDown(DIK_DOWN)) {
				if (PreDownStair == 0) {
					simon->isDownStair = 1;
				}
			}
			else {
				simon->isDownStair = 0;
			}
		}
	}
	
}
void SceneMain::LoadOther()
{
	score = new CScore();
	board = new CBoard();
	boardItem = new CBoardItem();
	blood = new CBlood();
	white = new CWhite();
	listObjDist = new map<int, CDistinct*>();
	listItemDist = new map<int, CItems*>();
	Grounds = new map < int, CDistinct*>();
	Enemys = new map<int, CDistinct*>();
	weapons.push_back(new CWhip());
	CollectMorningStar = 0;
}
void SceneMain::LoadResources(LPDIRECT3DDEVICE9 d3ddv)
{
	LoadOther();
	switch (State)
	{
	case 1:
		LoadMap1();
		break;
	case 2:
		LoadMap2();
		break;
	default:
		break;
	}
}

void SceneMain::LoadMap1()
{
	maps = new Map(State);
	AutoFit = 0; //Sử dụng biến này khi viewport.y của màn 2 khác với width của màn hình nên tọa độ item cộng thêm AutoFit
	QT = new QuadTree(State);
	simon = new CSimon(G_ScreenWidth, 76, 1);
	Enemys->clear();
	//weapons.push_back(new CWhip());
	simon->setx(20);
	simon->sety(100);
	cam = new GCamera(simon->getx(), 1);
	camObj = new GCamera(simon->getx(), 1);
	cam->SetSizeMap(0, 1536);
	camObj->SetSizeMap(0, 1536);
	simon->Jump();
	simon->Go();
	//
}

int SceneMain::EndScene1()
{
	
	EndingScene = 1;
	//simon->Go();
	//simon->SetAnimation(1.5, 0, 60);
	test = G_MapWidth - 150;
	if (simon->getx() >= test) return 1;
	return 0;
}

void SceneMain::LoadMap2()
{
	maps = new Map(State);
	AutoFit = 416;//Sử dụng biến này khi viewport.y của màn 2 khác với width của màn hình nên tọa độ item cộng thêm AutoFit
	simon = new CSimon(G_ScreenWidth, 76, 1);
	Enemys->clear();
	cohieu = true;
	//Load QT2
	QT = new QuadTree(State);
	simon->setx(16);
	simon->sety(474);
	cam = new GCamera(simon->getx(), 2);
	camObj = new GCamera(simon->getx(), 1);
	cam->SetSizeMap(0, 3072);
	camObj->SetSizeMap(0, 3072);
	Floor = 2;
	score->SetHeart(5); // Qua màn 2 thì tim auto cho 5 quả
	score->SetTime(300);
	score->SetEnemyBlood(16);
	score->SetSimonBlood(16);
	simon->Jump();
}
//Màn 2 chuyển cổng thứ 1(QT2b)
void SceneMain::LoadMap21()
{
	QT = new QuadTree(22);
	simon->setx(3087);
	simon->sety(608);
	cam = new GCamera(simon->getx(), 2);
	camObj = new GCamera(simon->getx(), 1);
	cam->SetSizeMap(3072, 4098);
	camObj->SetSizeMap(3072, 4098);
	Floor = 2;
}


void SceneMain::RenderStage(LPDIRECT3DDEVICE9 d3ddv, int t)
{

	//QT->UpdateQuadTree(cam, t);
	int t1 = rand() % 255;
	if (CollectMorningStar) simon->GSObject->SetARGB(255, rand() % 255, t1, t1 / 2);
	else{
		simon->GSObject->SetARGB();
	}
	simon->Draw(cam);
	/////////////////////////////////////////
	//Gọi hàm DrawMap2(Tiền updated khi chuyển màn)
	if (EndingScene == 1 && EndScene1()){
		maps->DrawMap2(d3ddv, cam);
		simon->MoveRigh();
		simon->Go();
	}
	//Cập nhật source khi mà xét vật di chuyển tràn qt
	QT->getListObjInNode(camObj);
	listObjDist = QT->GetListObj();
	listItemDist = QT->getListItem();
	//Nếu enemy vẫn còn sống thì cho chèn tiếp vào danh sách
	for (map<int, CDistinct*>::iterator obj = Enemys->begin(); obj != Enemys->end(); obj++) {
		if ((obj->second->getwhichObj() == 10 || obj->second->getwhichObj() == 12
			|| obj->second->getwhichObj() == 13 || obj->second->getwhichObj() == 14) && obj->second->getIsDie() == 0){
			listObjDist->insert(pair<int, CDistinct*>(obj->first, obj->second));
			listItemDist->insert(pair<int, CItems*>(QT->listItemInMap->find(obj->first)->first, QT->listItemInMap->find(obj->first)->second));
		}
	}
	//Khởi tạo các Enemy, Gounds
	Enemys->clear();
	Grounds->clear();
	for (map<int, CDistinct*>::iterator obj = listObjDist->begin(); obj != listObjDist->end(); obj++)
	{
		//Lấy con chó(whichObj = 7) và con ma(whichObj = 10) ở màn 2, con cá (whichObj = 8) ở màn dưới nước
		if (obj->second->getwhichObj() == 7 || obj->second->getwhichObj() == 8 || obj->second->getwhichObj() == 9
			|| obj->second->getwhichObj() == 10 || obj->second->getwhichObj() == 11 || obj->second->getwhichObj() == 12
			|| obj->second->getwhichObj() == 13 || obj->second->getwhichObj() == 14
			|| obj->second->getwhichObj() == 15) {
			if (obj->second->getwhichObj() == 8 && obj->second->enemyDie == false){
				if (obj->second->getObjX() + obj->second->getObjW() / 2 <= G_ScreenWidth + cam->viewport.x + 32 && cam->viewport.y <= 480){
					obj->second->setIsDie(0);
					obj->second->coliBrick = false;
					Enemys->insert(pair<int, CDistinct*>(obj->first, obj->second));
				}
			}
			if (obj->second->getwhichObj() != 8){
				Enemys->insert(pair<int, CDistinct*>(obj->first, obj->second));
			}
			if (obj->second->getwhichObj() == 10 || obj->second->getwhichObj() == 12
				|| obj->second->getwhichObj() == 13 || obj->second->getwhichObj() == 14)
				obj->second->coliBrick = false;
		}
		//Lấy gạch (Trong đó có cái đưa qua đưa lại và đánh gạch)
		//31: cục gạch số 3
		if (obj->second->getwhichObj() == 0 ||
			obj->second->getwhichObj() == 29||
			obj->second->getwhichObj() == 16||
			obj->second->getwhichObj() == 30||
			obj->second->getwhichObj() == 41||
			obj->second->getwhichObj() == 31){
			Grounds->insert(pair<int, CDistinct*>(obj->first, obj->second));
		}

		//=========================================================TRAP
		//Khởi tạo trap lên xuống ở màn 3
		if (obj->second->getwhichObj() == 17){
			obj->second->Go();
		}
	}
	for (map<int, CDistinct*>::iterator obj = Enemys->begin(); obj != Enemys->end(); obj++) {
		
		//Khởi tạo sự chuyển động của con chó
		if (obj->second->getwhichObj() == 7 && abs(obj->second->getObjX() - simon->getx()) <= 120 && obj->second->getTimeFall() >= -90 || obj->second->coliDog == true)
		{
			obj->second->Go();
		}
		else if (obj->second->getwhichObj() == 7 && obj->second->getIsGoing() && obj->second->coliDog == false){
			//Xét khoảng thời gian rơi của con chó giữa(tại node = 23) trong 3 con chó sẽ dài hơn
			if ((obj->first != 23 && obj->second->getTimeFall() <= -90) || (obj->second->getTimeFall() <= -120 && obj->first == 23)){
				obj->second->Jump();
				obj->second->Fall();
			}
		}
	}
	QT->DrawQuadTree(cam);
	//Draw weapon of simon
	for (int i = 0; i < weapons.size(); i++)
	{
		if (weapons.at(i)->GetFinish() == 0){
			if (weapons.at(i)->GetType() == 1){
				weapons.at(i)->SetXY(simon->getx(), simon->gety());
			}
			weapons.at(i)->Draw(cam);
		}
		if (weapons.at(i)->getcurentFrame() == 2){
			int a = 0;
		}
	}
	//Vẽ weaponsEnemy
	for (int i = 0; i < weaponsEnemy.size(); i++)
	{
		if (weaponsEnemy.at(i)->GetFinish() == 0){
			weaponsEnemy.at(i)->Draw(cam);
		}
	}
	//Vẽ Effects
	for (int i = 0; i < Effects.size(); i++)
	{
		Effects.at(i)->Draw(cam);
	}
	if (stepOpenTheGate == 2 || isBoss || isColliFood)
	{
		simon->Draw(cam);
	}

	FlashAnimation();
	G_SpriteHandler->End();
	CollisionState(State);// triển khai hàm ở bên dưới
}
//////////////////////////////////////////
//Source code thêm hàm UpdateObject(Tiền updated)
void SceneMain::UpdateObject(GCamera * cam, int t){
	if (EndingScene == 1 && EndScene1() && simon->getx() >= 1450){
		State = 2;
		LoadMap2();
		EndingScene = 0;
	}
	else if (State != 0 && !isOpenTheGate){
		if (countSimondied) {
			if (State == 2) {
				LoadMap2();
			}

			simondied = false;//simon song lại
			countSimondied = false;//kết thúc chuyển màn
			simon->setSimonDie(false);//thôi vẻ trạng thái chết
			stopsimon = false;//nút được thao tác
		}

		cam->SetFolowPos(simon->getx(), simon->gety());
		camObj->SetFolowPos(simon->getx(), simon->gety());
		if (PreUpStair)
			cam->SetVCam(simon->getTrend()*0.13* t, simon->GetVy());//Xét khi mà va chạm cầu thang để chuẩn bị lên cầu thang
		else{
			cam->SetVCam(simon->getVx() * t, simon->GetVy());
		}
		camObj->SetVCam(simon->getVx() * t, simon->GetVy());
		cam->UpdateCamera();
		camObj->UpdateCamera();
		//Updated weapons of simon
		for (int i = 0; i < weapons.size(); i++){
			if (weapons.at(i)->GetFinish() == 0){
				weapons.at(i)->Update(cam, t);
			}
			if (weapons.at(i)->getcurentFrame() == 2){
				int a = 0;
			}
		}
		//Updated weaponsEnemy
		for (int i = 0; i < weaponsEnemy.size(); i++){
			if (weaponsEnemy.at(i)->GetFinish() == 0){
				weaponsEnemy.at(i)->Update(cam, t);
			}
		}
		for (int i = 0; i < Effects.size(); i++)
		{
			Effects.at(i)->Update(t);
		}
	}
	QT->UpdateQuadTree(cam, t);
	//Xét simon Auto khi đứng trên thanh đung đưa mà chưa có ấn phím
	for (map<int, CDistinct*>::iterator obj = Grounds->begin(); obj != Grounds->end(); obj++)
	{
		if (obj->second->getwhichObj() == 16){
			if (simon->getIsGoing() == 0 && simon->getisOnbrick9()){
				simon->setvOnBrick9(obj->second->getVx()*t);
			}
		}
	}
}

void SceneMain::OnKeyDown(int KeyCode)
{
	if (lockKeyboard == 0) {
		if (IsKeyDown(DIK_UP)) {
			isPlay_Exit = true;
		}
		if (IsKeyDown(DIK_DOWN)) {
			isPlay_Exit = false;
		}
		if (IsKeyDown(DIK_RETURN)) {
			if (isPlay_Exit) {
				State = 0;
				maps = new Map(State);
				simon = new CSimon(G_ScreenWidth - 10, 370, -1);
			}
			else PostMessage(G_hWnd, WM_QUIT, 0, 0);
		}
	}
}

void SceneMain::CollisionState(int State)
{
	int IsCollision;
	float CollisionTime, nx, ny;
	if (PreDownStair) {
		GoDownStair(simon->xStairDown, simon->yStairDown, simon->stairTrend);
	}
	if (PreUpStair) {
		GoUpStair(simon->xStairUp, simon->yStairUp, simon->stairTrend);
	}
	//I. XÉT XA CHẠM 
	//=====================================================================================================
	//1.1 Xét va chạm với gạch
	onBrick = false;
	for (map<int, CDistinct*>::iterator obj = Grounds->begin(); obj != Grounds->end(); obj++)//2012
	{
		//1.1 VA CHẠM LIÊN QUAN SIMON
		//Va chạm simon với gạch khi simon nhảy và rơi xuống thì va chạm với gạch
		//====================================================================
		if (simon->GetOnStair() == 0){
			IsCollision = Collide(simon->GetBox(cam), obj->second->GetBox(cam), CollisionTime, nx, ny);
			if (obj->second->getwhichObj() == 41) {
				if (IsCollision) {
					State = 2;
					LoadMap2();
					
				}
			}
			if (obj->second->getwhichObj() == 16)
			{
				if (IsCollision == 4 || (IsCollision && simon->getisOnbrick9())) //^^^ brick9
				{
					float k = obj->second->getObjY() + obj->second->getObjH() / 2 + simon->getHeight() / 2 + 5;
					simon->StopFall(k);
					simon->setisOnBrick9(true);
				}

			}
			if (obj->second->getwhichObj() != 16)
			{
				if (IsCollision == 4 || (IsCollision == 5 && (simon->getIsFalling() == 1 && (abs(simon->gety() - 32 - (obj->second->getObjY() + obj->second->getObjH() / 2))) <= 16))){
					if (simon->gety() > obj->second->getObjY()){
						float k = obj->second->getObjY() + obj->second->getObjH() / 2 + simon->getHeight() / 2 + 5;
						simon->StopFall(k); 
					}
				}
				else if (IsCollision == 5){
					//Simon va chạm với gạch ben hong				
					if (abs(simon->gety() - (obj->second->getObjY() + obj->second->getObjH() / 2)) <= 2 || simon->gety() <= (obj->second->getObjY() + obj->second->getObjH() / 2)){
						if (simon->getTrend() == -1 && simon->getx() > obj->second->getObjX()) {
							simon->Stop();
							if (!simon->getIsJumping() && !simon->getIsFalling()) {//giai quyet gach o tren cao nhay bi lui lai 
								simon->setx(simon->getx() + 6);
							}
						}
						else if (simon->getTrend() == 1 && simon->getx() < obj->second->getObjX()) {
							simon->Stop();
							if (!simon->getIsJumping() && !simon->getIsFalling()) {
								simon->setx(simon->getx() - 6);
							}
						}
						if (simon->getIsJumping() && simon->getx() < (obj->second->getObjX() - obj->second->getObjW() / 2)){
							/*if (State == 3 && obj->second->getObjX()!= 1856 && obj->second->getObjX()!= 2272 && obj->second->getObjY()!=976)
							simon->Stop();*/
							//if (obj->second->getObjX() == 5616){//Xét gạch chỗ con boss
							simon->setx(simon->getx() - 6);
							//}
						}
					}
				}
			}
			if (!simon->getIsFalling() && !simon->getIsJumping()){
				if (IsCollision != 0){
					onBrick = true;
					if (obj->second->getwhichObj() != 16){
						simon->setisOnBrick9(false);
					}
				}
			}
		}
		//========================================================================
		//1.1.2 Va chạm gạch với các item =>item dừng lại
		for (map<int, CItems*>::iterator it = QT->getListItem()->begin(); it != QT->getListItem()->end(); it++)
		{
			IsCollision = Collide(it->second->GetBox(cam), obj->second->GetBox(cam), CollisionTime, nx, ny);
			if (IsCollision && it->second->getIsDie() == 0) {
				it->second->StopFall();
			}
		}
		//1.1.3 Va chạm với gạch thì các object chuyển động dừng lại
		for (map<int, CDistinct*>::iterator obj1 = Enemys->begin(); obj1 != Enemys->end(); obj1++){
			IsCollision = Collide(obj1->second->GetBox(cam), obj->second->GetBox(cam), CollisionTime, nx, ny);
			if (State == 2){
				float y;
				//Xét con chó thứ 2 khi rơi nó va chạm với gạch ở tại node 7
				if (obj->first == 7){
					if (obj1->second->getwhichObj() == 7 && obj1->first == 23){
						if ((IsCollision == 5 && obj->second->getIsFalling())|| IsCollision == 4){
							y = obj->second->getObjY() + obj->second->getObjH() / 2 -8;
							obj1->second->StopFall(y);						
							obj1->second->moveRigh();
							obj1->second->coliDog = true;
							trendFallDog = true;
						}
						else if (IsCollision == 0 && trendFallDog){
							obj1->second->Jump();
							obj1->second->Fall();
							obj1->second->coliDog = false;
						}
					}
				}
				//Va chạm chó, con ma với gạch ở node 0
				if (obj->first == 0){
					//Va chạm chó màn 2 với gạch ở node 0
					if (obj1->second->getwhichObj() == 7){
						if (IsCollision){
							if (obj1->first == 23){
								trendFallDog = false;
								obj1->second->coliDog = true;
							}
							obj1->second->StopFall(22 + AutoFit);
							if (obj1->second->getObjX() <= simon->getx())
								obj1->second->moveRigh();
							obj1->second->coliDog = true;
						}
					}
				}
			}
			//Va chạm enemy mà không phải là con chó với gạch(Type = 8(cá), type = 10(ma), type=13(Ironman), type=12(đầu bay))		
			if (obj1->second->getwhichObj() != 16)
			{
				if (IsCollision == 4)
				{
					obj1->second->StopFall(obj1->second->getObjY() - 14);
					if (obj1->second->getwhichObj() == 8)					
					Effects.clear();
				}
				if (obj1->second->getIsGoing() == 1){
					if (IsCollision != 0 && obj1->second->getObjY() > obj->second->getObjY() + obj->second->getObjH() / 2){
						obj1->second->coliBrick = true;
					}
				}
				if (obj1->second->getwhichObj() == 12) IsCollision = 0;
				//Va chạm  quái(type = 10), lính(type = 13) với gạch thì quay đầu lại			
				if (IsCollision == 2 || IsCollision == 5){
					if (IsCollision == 5){
						if (obj1->second->getwhichObj() == 10 && obj1->second->getObjY() <= obj->second->getObjY() + obj->second->getObjH() / 2 && obj1->second->gettrend() == 1){
							obj1->second->settrend(-obj1->second->gettrend());
						}
						//Đổi chiều khi mà min và Max của SIronMan nhỏ hơn hoặc lớn hơn gạch mà chỗ đó có va chạm
						else /*if (obj1->second->getwhichObj() == 13 && (obj1->second->getMax() > obj->second->getObjX()- obj->second->getObjW()/2 || obj1->second->getMin() < obj->second->getObjX() + obj->second->getObjW()/2)){
							obj1->second->settrend(-obj1->second->gettrend());
						}*/
						{
							/*if (obj1->second->getwhichObj() == 13 && (obj1->second->getMin() != obj->second->getObjX() - obj->second->getObjW() / 2 || obj1->second->getMax() != obj->second->getObjX() + obj->second->getObjW() / 2))
							{
								obj1->second->settrend(-obj1->second->gettrend());
							}*/
						}
					}
					else{
						obj1->second->settrend(-obj1->second->gettrend());
					}
				}
			}
		}
		//=========================================================================
		//Xét va chạm vũ khí quái với gạch
	}
	//====================================================================================Lam man 3
	if (onBrick == false)
	{
		if (!simon->getIsFalling() && !simon->getIsJumping() && !(simon->GetOnStair()))
		{
			simon->Jump(); // Jump cho ĐÚNG QUY TRÌNH :v
			simon->Fall();
		}
	}
	//=========================================================================
	//1.2 Xét va chạm chai nc vs nền
	for (int i = 0; i < weapons.size(); i++){
		if (weapons.at(i)->GetType() == 6)
		{
			for (map<int, CDistinct*>::iterator obj = Grounds->begin(); obj != Grounds->end(); obj++)
			{
				int t = Collide(weapons.at(i)->GetBox(cam), obj->second->GetBox(cam), CollisionTime, nx, ny);
				if (t == 4)
				{
					weapons.at(i)->y = obj->second->getObjY() + obj->second->getObjH() + 7;
					weapons.at(i)->Boom();
				}
			}
		}
	}
	//1.3 Xét va chạm enemy vs nền
	for (map<int, CDistinct*>::iterator obj = Enemys->begin(); obj != Enemys->end(); obj++){
		if (obj->second->getwhichObj() == 8 && obj->second->getIsGoing() == 1){
			if (obj->second->coliBrick == false){
				obj->second->Jump();
				obj->second->Fall();
			}
		}
		if ((obj->second->getwhichObj() == 10
			|| obj->second->getwhichObj() == 13 || obj->second->getwhichObj() == 14)
			&& obj->second->getIsGoing() == 1){
			if (obj->second->coliBrick == false){
				obj->second->Fall();
			}
		}
	}
	//1.4 Va chạm roi vs đối tượng
	for (map<int, CDistinct*>::iterator obj = listObjDist->begin(); obj != listObjDist->end(); obj++)
	{
		//Va chạm simon với cục gạch ảo ở cổng chuyển cổng màn 1 sang màn 2
		if (obj->second->getwhichObj() == 20) {
			IsCollision = Collide(simon->GetBox(cam), obj->second->GetBox(cam), CollisionTime, nx, ny);
			if (IsCollision) {
				EndScene1();
			}
		}
		//Va chạm simon với tráp (Đi lên xuống màn 3)
		if (obj->second->getwhichObj() == 17) {
			IsCollision = Collide(simon->GetBox(cam), obj->second->GetBox(cam), CollisionTime, nx, ny);
			if (IsCollision && simon->GetHurt() == 0) {
				simon->Hurt(simon->getTrend());
				score->CalculatorHurt(1);
			}
		}
		
		//Va chạm roi với object, sau khi object chết thì show item ra
		if ((obj->second->getwhichObj() == 29||obj->second->getwhichObj()==30 || obj->second->getwhichObj()==31|| obj->second->getwhichObj() == 5 || obj->second->getwhichObj() == 6) && obj->second->getIsDie() == 0)
		{
			//29 là brick2 
			//2 là frame lúc đánh của roi cấp 1, 6 là frame lúc đánh của roi cấp 2, 10 là frame lúc đánh của roi cấp 3
			IsCollision = Collide(weapons.at(0)->GetBox(cam), obj->second->GetBox(cam), CollisionTime, nx, ny);
			if (IsCollision)
			{
				if ((obj->second->getwhichObj() == 29 && cam->viewport.y != 480)|| obj->second->getwhichObj() == 30||obj->second->getwhichObj() == 31){//Cục gạch ẩn có cục thịt, cục gạch ẩn
					obj->second->breakBrick();
					isColliFood = true; //Bien cho cuc thit ve thi simon ve o truoc do
					if (obj->second->getBreakBrick() == 4){
						QT->getListItem()->find(obj->first)->second->setX(obj->second->getObjX());
						if (obj->second->getwhichObj() == 31 && State == 3){//Xét tọa độ y của cục thịt
							QT->getListItem()->find(obj->first)->second->setY(obj->second->getObjY()+16);
						}
						QT->getListItem()->find(obj->first)->second->setIsDie(0);
					}
				}
				else if (obj->second->getwhichObj() != 29){
					obj->second->setIsDie(1);
					QT->getListItem()->find(obj->first)->second->setX(obj->second->getObjX());
					QT->getListItem()->find(obj->first)->second->setIsDie(0);
					QT->getListItem()->find(obj->first)->second->Fall();
					QT->getListItem()->find(obj->first)->second->setFireDie(0);
				}

			}
		}
		//Va chạm với cổng thứ 1 ở stage2
		if (obj->second->getwhichObj() == 22){
			if (Collide(simon->GetBox(cam), obj->second->GetBox(cam), CollisionTime, nx, ny) > 0)
			{
				if (!simon->getIsFalling() && !simon->getIsJumping())
				{
					simon->Stop();
					xToOpen = cam->viewport.x + G_ScreenWidth / 2 * simon->getTrend();
					if (obj->second->getObjX() < G_MapWidth - G_ScreenWidth / 2)
					{
						isOpenTheGate = true;
						stepOpenTheGate = 0;
					}
				}
			}
		}
		if (isOpenTheGate)
		{
			OpenTheGate();
			return;
		}
	}
	//=================================================================================
	//1.5 Simon va chạm với quái, tính toán máu(trung2)
	for (map<int, CDistinct*>::iterator obj3 = Enemys->begin(); obj3 != Enemys->end(); obj3++){
		//Đối với con quái khác bossMedusa(type = 15) thì cho va chạm khi nó di chuyển, co the khong de obj 11 vi boss doi o tren cao nen vacham luc dung yen khong xay ra
		if ((obj3->second->getwhichObj() != 15  
			|| (
			(obj3->second->getwhichObj() == 15 || obj3->second->getwhichObj() == 11) && obj3->second->getIsGoing())) 
			&& obj3->second->getIsDie() == 0 && simon->GetHurt() == 0)
		{
			if ((Collide(simon->GetBox(cam), obj3->second->GetBox(cam), CollisionTime, nx, ny)))
			{
				score->CalculatorHurt(obj3->second->getwhichObj());
				if (score->GetSimonBlood() <= 0) {
					simon->setSimonDie(true);//ve hinh simon chet;
					simondied = true;
					simon->SetHurt(25);
				}
				else {
					simon->Hurt(simon->getx() > obj3->second->getObjX());
				}
			}
		}
	}
	//====================================================================================
	//1.6 Simon va chạm với vũ khí quái(Ngọn lửa, con rắn)
	for (int i = 0; i < weaponsEnemy.size(); i++){
		if (weaponsEnemy.at(i)->GetFinish() == 0 && simon->GetHurt() == 0){
			if ((Collide(simon->GetBox(cam), weaponsEnemy.at(i)->GetBox(cam), CollisionTime, nx, ny)))
			{
				simon->Hurt(simon->getx() > weaponsEnemy.at(i)->x);
				score->CalculatorHurt(1);
			}
		}
	}
	//II. DUYỆT DANH SÁCH ENEMY
	// Xét va chạm vũ khí simon với quái enemy || Trừ máu nếu đụng //Tien
	for (int i = 0; i < weapons.size(); i++){
		for (map<int, CDistinct*>::iterator obj = Enemys->begin(); obj != Enemys->end(); obj++){
			IsCollision = Collide(weapons.at(i)->GetBox(cam), obj->second->GetBox(cam), CollisionTime, nx, ny);
			if (IsCollision && obj->second->getIsDie() == 0 && weapons.at(i)->GetFinish() == 0) {
				//Va chạm roi với quái
					if (obj->second->getwhichObj() != 15 && obj->second->getwhichObj() != 11) {
						if (obj->second->getwhichObj() == 14 || obj->second->getwhichObj() == 13) {
							//obj->second->setHealth();//quai nay danh >2 cai moi chet
							//if (obj->second->getHealth() == 0) {
							//	obj->second->setIsDie(1);
							//}
						}
						else {
							obj->second->setIsDie(1);
							obj->second->enemyDie = true;
						}
					}
					//Va chạm với bossmedusa va boss doi(trung)
					if ((obj->second->getwhichObj() == 15 || obj->second->getwhichObj() == 11) && obj->second->GetHurt() == 0 && obj->second ->getIsGoing() == 1)//Va chạm với boss medusa
					{
						obj->second->SetHurt(25);//delay time va cham cho đỡ mất máu
						score->CalculatorHurtBoss(2);
						if (score->GetEnemyBlood() == 0) {
							obj->second->setIsDie(1);
							score->CalculatorWhenBossDie();
						}
					}
					if (obj->second->getIsDie() == 1) {
						QT->getListItem()->find(obj->first)->second->setIsDie(0);
						QT->getListItem()->find(obj->first)->second->Fall();
						QT->getListItem()->find(obj->first)->second->setXFire(obj->second->getObjX());
						QT->getListItem()->find(obj->first)->second->setYFire(obj->second->getObjY());
						QT->getListItem()->find(obj->first)->second->setFireDie(0);
						if (obj->second->getwhichObj() == 15 || obj->second->getwhichObj() == 11){
							QT->getListItem()->find(obj->first)->second->setCountTime();
						}
						if (obj->second->getwhichObj() != 15 && obj->second->getwhichObj() != 11){
							QT->getListItem()->find(obj->first)->second->setX(obj->second->getObjX());
						}
						if (obj->second->getwhichObj()!= 11){
							QT->getListItem()->find(obj->first)->second->setY(obj->second->getObjY()); //^^^19
						}
						//Nếu đánh vào con chó thì xét lại tọa độ y của ngọn lửa
					}
			}
		}

	}
	//III. DUYỆT DANH SÁCH ITEMS
	for (map<int, CItems*>::iterator obj = QT->getListItem()->begin(); obj != QT->getListItem()->end(); obj++)
	{
		//3.1 Va chạm với simon
		IsCollision = Collide(simon->GetBox(cam), obj->second->GetBox(cam), CollisionTime, nx, ny);
		if (IsCollision) {
			//Nếu simon va chạm với item là IWhip thì nó sẽ thay đổi màu
			if (obj->second->getwhichObj() == 4 && obj->second->getIsDie() == 0){
				//CollectMorningStar = 1;
				weapons.at(0)->SetTypeMorningStar();
			}
			//Cay thanh gia chop man hinh
			if (obj->second->getwhichObj() == 9 && obj->second->getIsDie() == 0)
			{
				animation = 10;
				for (map<int, CDistinct*>::iterator obj = Enemys->begin(); obj != Enemys->end(); obj++)
				{
					if (obj->second->getwhichObj() != 11 && obj->second->getwhichObj() != 15)
					{
						obj->second->setIsDie(1);
						this->SetDieAllEnemy();
					}
				}
			}
			
			//Cây kiếm
			if (obj->second->getwhichObj() == 10 && obj->second->getIsDie() == 0)
			{
				typeWeapon = 1;
				boardItem->setwhichObj(10);
			}
			//Lọ nước (bom)
			if (obj->second->getwhichObj() == 13 && obj->second->getIsDie() == 0) {
				typeWeapon = 2;
				boardItem->setwhichObj(13);
			}
			//Cái rìu
			if (obj->second->getwhichObj() == 3 && obj->second->getIsDie() == 0) {
				typeWeapon = 3;
				boardItem->setwhichObj(3);
			}
			//Bomeran
			if (obj->second->getwhichObj() == 6 && obj->second->getIsDie() == 0) {
				typeWeapon = 4;
				boardItem->setwhichObj(6);
			}
			
			if (obj->second->getIsDie() == 0 && obj->second->getIsDie() == 0)
			{
				score->CalculatorItem(obj->second->getwhichObj());
				if (obj->second->getwhichObj() == 17) //Quả trứng chỗ con boss dơi, đụng con đó thì tính điểm, thời gian còn lại
				{
					eatOrb = true;
				}
			}
			obj->second->setIsDie(1);
		}

	}
	//IV. SIMON VỚI CẦU THANG
	for (map<int, CDistinct*>::iterator obj = listObjDist->begin(); obj != listObjDist->end(); obj++) {
		if (obj->second->getwhichObj() == 2 || obj->second->getwhichObj() == 4) {
			obj->second->settrend(-1);
		}
		if (obj->second->getwhichObj() == 1 || obj->second->getwhichObj() == 3) {
			obj->second->settrend(1);
		}
		IsCollision = Collide(simon->GetBox(cam), obj->second->GetBox(cam), CollisionTime, nx, ny);
		if (obj->second->getwhichObj() == 2 || obj->second->getwhichObj() == 1) {
			if (IsCollision) {// == 2
				simon->xStairUp = obj->second->getObjX();
				simon->yStairUp = obj->second->getObjY();
				simon->stairTrend = obj->second->gettrend();
				if (simon->isUpStair) {
					PreUpStair = 1;
					phaseUpStair = 0;
					simon->SetAnimation(1, 0, 90);
					//GoUpStair(simon->xStairUp, simon->yStairUp, simon->stairTrend);
				}
				else

				if (simon->GetOnStair()
					&& (simon->getTrend()*simon->stairTrend) == 1
					&& simon->gety() <= simon->yStairUp + 16)//hết va chạm để ra khỏi cầu thang
				{
					simon->OutStair();
					//simon->sety(simon->yStairUp - 5 + 30 + 2);
				}
			}
		}
		if (obj->second->getwhichObj() == 4 || obj->second->getwhichObj() == 3) {
			//obj->second->setTrend(-1);
			if (IsCollision) {
				simon->xStairDown = obj->second->getObjX();
				simon->yStairDown = obj->second->getObjY();
				simon->stairTrend = obj->second->gettrend();
				if (simon->isDownStair){
					PreDownStair = 1;
					phaseDownStair = 0;
					//GoDownStair(simon->xStairDown, simon->yStairDown, simon->stairTrend);
				}
				//**dang bi cho va  cham vi box 4 qua dai
				else
				if (simon->GetOnStair()
					&& (simon->getTrend()*simon->stairTrend) == -1
					&& simon->gety() >= simon->yStairDown + 16
					) {
					simon->OutStair();
				}
			}
		}
	}
	//KHÁC

}
void SceneMain::GoUpStair(float x, float y, int trend) {
	if (phaseUpStair == 0) {
		simon->Auto = 1;
		if (trend == -1) //lên theo chiều dương oX
		{
			if (x < simon->getx())
				simon->MoveLeft(); //Nếu simon ngược hướng thì quay lại
			else
				simon->MoveRigh();
		}
		else //lên theo chiều âm của ox
		{
			if (simon->getx() < x) simon->MoveRigh();
			else  simon->MoveLeft();
		}
		phaseUpStair = 1;
		return;
	}
	if (phaseUpStair == 1) // Ch?nh l?i v? trí, d?ng l?i
	{
		simon->Go();
		// --> khi x cua simon nho hon x cua cau thang thi return buoc stepupstair = 0 de moveright.
		if (trend == -1 && simon->getTrend() == -1 && simon->getx() < x)
		{
			phaseUpStair = 0;
			return;
		}
		if (trend == -1 && (simon->getx() <= x))
		{
			simon->setx(x - 14);
			//simon->UpStair();
			phaseUpStair = 2;
		}

		// <--
		if (trend == 1 && simon->getTrend() == 1 && simon->getx() > x)// đi quá đà phải quay lại để lên cầu thang
		{
			phaseUpStair = 0;
			return;
		}

		if (trend == 1 && simon->getx() >= x)
		{
			//simon->MoveLeft();
			simon->setx(x + 14);
			simon->Stop();
			simon->UpStair();
			phaseUpStair = 2;
			//return;
		}
	}
	if (phaseUpStair == 2) // ?i lên
	{
		simon->SetAnimation(5, 0, 100);
		simon->Go();
		phaseUpStair = 3;
	}

	if (phaseUpStair == 3)
	{
		if (simon->Auto == 0)
		{
			PreUpStair = 0;
			//simon->Stop();
		}
	}
}
void SceneMain::GoDownStair(float x, float y, int trend) {
	if (phaseDownStair == 0) {
		simon->Auto = 1;
		if (trend == -1) // 
		{
			if (x < simon->getx())
				simon->MoveLeft();
			else
				simon->MoveRigh();
		}
		else
		{
			if (simon->getx() < x) simon->MoveRigh();
			else  simon->MoveLeft();
		}
		phaseDownStair = 1;
		return;//????
	}
	if (phaseDownStair == 1) {
		simon->Go();
		// -->
		if (trend == -1 && simon->getTrend() == -1 && simon->getx() < x)
		{
			phaseDownStair = 0;
			return;
		}
		if (trend == -1 && simon->getx() <= x)
		{
			//simon->MoveRigh();
			simon->setx(x - 14);
			simon->Stop();
			simon->DownStair();
			phaseDownStair = 2;
			//return;
		}
		if (trend == 1 && simon->getTrend() == 1 && simon->getx() > x)
		{
			phaseDownStair = 0;
			return;
		}
		if (trend == 1 && simon->getx() >= x)
		{
			//simon->MoveLeft();
			simon->setx(x + 14);
			simon->Stop();
			simon->DownStair();
			phaseDownStair = 2;
			return;
		}

	}
	if (phaseDownStair == 2) {
		simon->Go();
		phaseDownStair = 3;
		//return;
	}
	if (phaseDownStair == 3) {
		PreDownStair = 0;
	}

}

void SceneMain::OpenTheGate()
{
	if (stepOpenTheGate == 0)
	{
		Enemys->clear();
		cam->viewport.x += 4 * simon->getTrend();
		camObj->viewport.x += 4 * simon->getTrend();
		if (cam->viewport.x >= xToOpen && simon->getTrend() > 0 || (cam->viewport.x <= xToOpen && simon->getTrend() < 0))
		{
			stepOpenTheGate++;
			OpeningTheGate = 1;
		}
		return;
	}
	if (stepOpenTheGate == 1)
	{
		if (OpeningTheGate == 2)
			stepOpenTheGate++;
		return;
	}
	if (stepOpenTheGate == 2)
	{
		if (simon->getx() >= cam->viewport.x + G_ScreenWidth / 2 + 70 && simon->getTrend() > 0 || (simon->getx() <= cam->viewport.x + G_ScreenWidth / 2 - 70 && simon->getTrend() < 0))
		{
			OpeningTheGate = 0;
			stepOpenTheGate++;
			simon->Stop();
		}
		return;
	}
	if (stepOpenTheGate == 3)
	{
		cam->viewport.x += 4 * simon->getTrend();
		camObj->viewport.x += 4 * simon->getTrend();
		if (cam->viewport.x >= xToOpen + G_ScreenWidth / 2 && simon->getTrend() > 0 || (cam->viewport.x <= xToOpen - G_ScreenWidth / 2 && simon->getTrend() < 0))
		{
			stepOpenTheGate = 0;
			isOpenTheGate = 0;
			if (State == 2)
			{
				if (cam->viewport.x < 3100 + G_ScreenWidth / 2) {
					Enemys->clear();
					cam->SetSizeMap(cam->viewport.x, 4098);
					camObj->SetSizeMap(cam->viewport.x, 4098);
					QT = new QuadTree(22);//Chuyển sang file QT2b.txt
				}
				else
				if (cam->viewport.x < 4100 + G_ScreenWidth / 2) {
					Enemys->clear();
					cam->SetSizeMap(cam->viewport.x, G_MapWidth);
					camObj->SetSizeMap(cam->viewport.x, G_MapWidth);
					isColliFood = false;//Bien cho cuc thit ve thi simon ve o truoc do
					QT = new QuadTree(23);//Chuyển sang file QT2b.txt
				}

			}
			if (State == 3)
			{
				if (cam->viewport.x > 1536 + G_ScreenWidth / 2)
				{
					Enemys->clear();
					cam->SetSizeMap(1536, cam->viewport.x + G_ScreenWidth);
					camObj->SetSizeMap(1536, cam->viewport.x + G_ScreenWidth);
					QT = new QuadTree(32);//Chuyển sang file QT3c.txt
				}
				else
				if (cam->viewport.x > 0)
				{
					Enemys->clear();
					cam->SetSizeMap(0, cam->viewport.x + G_ScreenWidth); // 0 -> 1536
					camObj->SetSizeMap(0, cam->viewport.x + G_ScreenWidth); // 0 -> 1536
					QT = new QuadTree(34);//Chuyển sang file QT3e.txt
				}
			}
		}
		return;
	}
}

void SceneMain::MoveCamera(bool up, bool down)
{
	if (State == 2){
		if (down){
			if (simon->getx() < 3300 && simon->gety() < 474 && Floor == 2)
			{
				simon->setx(3200);
				simon->sety(388);
				MoveDownCamera();
				return;
			}
			if (simon->getx() > 3700 && simon->gety() < 474 && Floor == 2)
			{
				simon->setx(3836);
				simon->sety(388);
				MoveDownCamera();
				return;
			}
			return;
		}
		if (up){
			if (simon->getx() < 3200 && simon->gety() > 400 && Floor == 1)
			{
				simon->setx(3184);
				simon->sety(465);
				MoveUpCamera();
				return;
			}
			if (simon->getx() > 3700 && simon->gety() > 400 && Floor == 1)
			{
				simon->setx(3824);
				simon->sety(465);
				MoveUpCamera();
				return;
			}
		}
	}
	if (State == 3)
	{
		if (up)
		{
			// Lên tầng 2
			if (simon->getx() > 3840 && simon->gety() > 350 && Floor == 1)
			{
				simon->setx(3859);
				simon->sety(432);
				MoveUpCamera();
				cam->SetSizeMap(G_MapWidth - 2 * G_ScreenWidth, G_MapWidth);
				camObj->SetSizeMap(G_MapWidth - 2 * G_ScreenWidth, G_MapWidth);
				//Load vào QT3b
				Enemys->clear();
				QT = new QuadTree(31);
				return;
			}

			// Lên tầng 3
			if (simon->getx() > 1668 && simon->gety() > 739 && Floor == 2)
			{
				simon->setx(1683);
				simon->sety(818);
				MoveUpCamera();
				Enemys->clear();
				QT = new QuadTree(33);
				return;
			}

			// Lên tầng 4
			if (simon->getx() > 1348 && simon->gety() > 1119 && Floor == 3)
			{
				simon->setx(1363);
				simon->sety(1198);
				MoveUpCamera();
				Enemys->clear();
				QT = new QuadTree(35);
				return;
			}
		}

		if (down)
		{
			// Xuống tầng 1
			if (simon->getx() < 3860 && simon->gety() < 435 && Floor == 2)
			{
				simon->setx(3825);
				simon->sety(335);
				MoveDownCamera();
				cam->SetSizeMap(G_MapWidth - G_ScreenWidth, G_MapWidth);
				camObj->SetSizeMap(G_MapWidth - G_ScreenWidth, G_MapWidth);
				Enemys->clear();
				QT = new QuadTree(3);
				return;
			}

			// Xuống tầng 2
			if (simon->getx() < 1690 && simon->gety() < 820 && Floor == 3)
			{
				simon->setx(1668);
				simon->sety(739);
				MoveDownCamera();
				Enemys->clear();
				QT = new QuadTree(32);
				return;
			}

			// Xuống tầng 3
			if (simon->getx() < 1365 && simon->gety() < 1200 && Floor == 4)
			{
				simon->setx(1348);
				simon->sety(1119);
				MoveDownCamera();
				Enemys->clear();
				QT = new QuadTree(34);
				return;
			}
		}
	}
}
void SceneMain::MoveDownCamera()
{
	Floor--;
	if (State == 2){
		cam->viewport.y = 480 + AutoFit * (Floor - 1);
	}
	if (State == 3){
		cam->viewport.y = G_ScreenHeight + 384 * (Floor - 1);
	}
}
void SceneMain::MoveUpCamera()
{
	if (State == 2){
		cam->viewport.y = G_ScreenHeight + AutoFit * Floor;
	}
	if (State == 3){
		cam->viewport.y = G_ScreenHeight + 384 * Floor;
	}
	Floor++;
}
SceneMain::~SceneMain(void)
{

}

void SceneMain::FlashAnimation()
{
	if (animation > 0)
	{
		white->Draw(cam);
		animation--;
	}
}

void SceneMain::SetDieAllEnemy()
{
	for (map<int, CDistinct*>::iterator obj = Enemys->begin(); obj != Enemys->end(); obj++)
	{
		if (obj->second->getwhichObj() != 11 && obj->second->getwhichObj() != 15)
		{
			obj->second->setIsDie(1);
			QT->getListItem()->find(obj->first)->second->setIsDie(0);
			QT->getListItem()->find(obj->first)->second->Fall();
			QT->getListItem()->find(obj->first)->second->setXFire(obj->second->getObjX());
			QT->getListItem()->find(obj->first)->second->setYFire(obj->second->getObjY());
			QT->getListItem()->find(obj->first)->second->setFireDie(0);
			QT->getListItem()->find(obj->first)->second->setX(obj->second->getObjX());
			QT->getListItem()->find(obj->first)->second->setY(obj->second->getObjY());
		}
	}
}