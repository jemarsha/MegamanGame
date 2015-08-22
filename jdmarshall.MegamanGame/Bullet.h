#ifndef BULLET_H
#define BULLET_H

#include "GameObject.h"
#include <string>

using namespace std;
class Bullet :public GameObject{ 

public:
	Bullet();
	Bullet(int, int, float);
	~Bullet();
	vector<GameObject*> move(string);
	

	
	

private:
	
	int x,y, bullet ;
	float yvel;
	
};


#endif	
