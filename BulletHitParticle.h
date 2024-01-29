#pragma once
#include <Novice.h>
#include "Vector2.h"

class BulletHitParticle
{
public:
	BulletHitParticle(Vector2 pos,Vector2 velocity,float size);
	~BulletHitParticle();

	void Update();
	void Draw();

	bool GetDelFlag();

private:
	int gh_ = Novice::LoadTexture("./Resources/images/circle.png");

	Vector2 pos_;
	Vector2 velocity_;
	float size_;

	Vector2 leftTop_;
	Vector2 rightTop_;
	Vector2 leftBottom_;
	Vector2 rightBottom_;

	int alpha_ = 255;
	bool del_ = false;
};

