#include "Enemy.h"
#include "math.h"

Enemy::Enemy()
{
	pos_ = { 960.0f,360.0f };
	radius_ = 128.0f;
	count_ = 0;
	hp_ = 10;
	isAlive_ = true;
	life_ = 3; // 残基
	reviveTimer_ = 90;
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	pos_ = { 960.0f,360.0f };
	radius_ = 128.0f;
	count_ = 0;
	hp_ = 10;
	isAlive_ = true;
	life_ = 3; // 残基
	reviveTimer_ = 90;
}

void Enemy::Update()
{
	count_++; // カウントを進める

	// 移動処理
	float angleInRadians = ((float)count_ * (float)M_PI * 2.0f / 180.0f);
	float amplitude = 160.0f; // 振幅の設定
	pos_.y = amplitude * sinf(angleInRadians) + 360.0f; // 360を基準にして振幅で移動


	// 体力が0になった場合の処理
	if (hp_ <= 0 && isAlive_ == true) {
		isAlive_ = false;
		life_--; // 残基を減らす
	}

	// 復活するための処理
	if (isAlive_ == false) {
		if (reviveTimer_ > 0) {
			reviveTimer_--; // 復活するまでのカウントを減らす
		} else {
			isAlive_ = true;
			hp_ = 10;
			reviveTimer_ = 90;
		}
	}
}

void Enemy::Draw()
{
	// 敵を描画
	if (isAlive_ == true) {
		Novice::DrawSprite(
			(int)pos_.x - (int)radius_, (int)pos_.y - (int)radius_,
			enemyGH_,
			1.0f, 1.0f,
			0.0f,
			0xFFFFFFFF
		);
	}

	/*Novice::ScreenPrintf(0, 0, "enemyHP = %d", hp_);
	Novice::ScreenPrintf(0, 20, "enemyReviveTimer = %d", reviveTimer_);
	Novice::ScreenPrintf(0, 40, "life = %d", life_);*/
}

void Enemy::OnCollision()
{
	hp_--; // 体力を減らす
}

Vector2 Enemy::GetPos()
{
	return pos_;
}

float Enemy::GetRadius()
{
	return radius_;
}

bool Enemy::GetIsAlive()
{
	return isAlive_;
}

int Enemy::GetLife()
{
	return life_;
}

int Enemy::GetHp()
{
	return hp_;
}

int Enemy::GetReviveTimer()
{
	return reviveTimer_;
}
