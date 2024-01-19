#include "Enemy.h"
#include "math.h"

Enemy::Enemy()
{
	pos_ = { 960.0f,360.0f };
	radius_ = 128.0f;
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	// エネミーを描画
	Novice::DrawSprite(
		(int)pos_.x - (int)radius_, (int)pos_.y - (int)radius_,
		enemyGH_,
		1.0f, 1.0f,
		0.0f,
		0xFFFFFFFF
	);
}
