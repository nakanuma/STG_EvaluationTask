#pragma once
#include <Novice.h>
#include <Vector2.h>
#include "Define.h"
#include <iostream>
#include <algorithm>

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

	void OnCollision();

	// アクセッサ
	Vector2 GetPos();
	float GetRadius();

	bool IsInvincivle(); 

	int GetHp();

	Bullet* bullet_[kPlayerBulletNum];

private:
	int playerGH_ = Novice::LoadTexture("./Resources/images/player.png");

	Vector2 pos_;
	float radius_;
	float speed_;
	int hp_;
	bool isAlive_;
	bool isInvincible_; // プレイヤーが無敵中かどうか
	int invincibleTimer_; // 無敵時間

	int bulletCoolDownTimer_;
};

