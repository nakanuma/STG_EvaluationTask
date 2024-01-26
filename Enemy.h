#pragma once
#include <Novice.h>
#include "Vector2.h"
#define _USE_MATH_DEFINES
#include <math.h>

class Enemy
{
public:
	Enemy();
	~Enemy();

	void Initialize();
	void Update();
	void Draw();

	void OnCollision(); // 衝突した際の処理

	// アクセッサ
	Vector2 GetPos();
	float GetRadius();

	bool GetIsAlive();

	int GetLife();

private:
	int enemyGH_ = Novice::LoadTexture("./Resources/images/enemy.png");

	Vector2 pos_;
	float radius_;
	int count_;
	int hp_;
	bool isAlive_;
	int life_;
	int reviveTimer_; // 復活するまでの時間
};

