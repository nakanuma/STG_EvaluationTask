#pragma once
#include <Novice.h>
#include <Vector2.h>
#include "Define.h"

// Object //
#include "Bullet.h"

class Player
{
public:
	Player();
	~Player();

	void Initialize();
	void Update(char* keys,char* preKeys);
	void Draw();

private:
	int playerGH_ = Novice::LoadTexture("./Resources/images/player.png");

	Vector2 pos_;
	float radius_;
	float speed_;

	Bullet* bullet_[kPlayerBulletNum];
	int bulletCoolDownTimer_;
};

