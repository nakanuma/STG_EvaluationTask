#pragma once
#include <Novice.h>
#include "Vector2.h"

class Enemy
{
public:
	Enemy();
	~Enemy();

	void Initialize();
	void Update();
	void Draw();

private:
	int enemyGH_ = Novice::LoadTexture("./Resouces/iamges/enemy.png");

	Vector2 pos_;
	float radius_;
};

