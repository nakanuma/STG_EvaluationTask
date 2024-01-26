#pragma once
#include <Novice.h>
#include "Vector2.h"

class Bullet
{
public:
	Bullet();
	~Bullet();

	void Update(Vector2 velocity);
	void Draw();

	// アクセッサ
	Vector2 GetPos(); 
	void SetPos(Vector2 pos); 

	float GetRadius();

	bool GetIsShot(); 
	void SetIsShot(bool flag); 

private:
	int bulletGH_ = Novice::LoadTexture("./Resources/images/bullet.png");

	Vector2 pos_;
	float speed_;
	float radius_;
	bool  isShot_;
};

