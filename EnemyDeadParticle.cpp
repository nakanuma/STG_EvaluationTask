#include "EnemyDeadParticle.h"

EnemyDeadParticle::EnemyDeadParticle(Vector2 pos, Vector2 velocity, float size)
{
	pos_.x = pos.x;
	pos_.y = pos.y;

	velocity_.x = velocity.x;
	velocity_.y = velocity.y;

	size_ = size;

	leftTop_ = { 0.0f,0.0f };
	rightTop_ = { 0.0f,0.0f };
	leftBottom_ = { 0.0f,0.0f };
	rightBottom_ = { 0.0f,0.0f };
}

EnemyDeadParticle::~EnemyDeadParticle()
{
}

void EnemyDeadParticle::Update()
{
	// 4点の座標を更新
	leftTop_ = { pos_.x - (size_ / 2),pos_.y - (size_ / 2) };
	rightTop_ = { pos_.x + (size_ / 2),pos_.y - (size_ / 2) };
	leftBottom_ = { pos_.x - (size_ / 2),pos_.y + (size_ / 2) };
	rightBottom_ = { pos_.x + (size_ / 2),pos_.y + (size_ / 2) };

	// 座標を更新
	pos_.x += velocity_.x;
	pos_.y += velocity_.y;

	// サイズを小さくする
	if (size_ >= 0) {
		size_ -= 2.5f;
	}

	// サイズが0になったら削除
	if (size_ < 0) {
		del_ = true;
	}
}

void EnemyDeadParticle::Draw()
{
	Novice::DrawQuad(
		(int)leftTop_.x, (int)leftTop_.y,
		(int)rightTop_.x, (int)rightTop_.y,
		(int)leftBottom_.x, (int)leftBottom_.y,
		(int)rightBottom_.x, (int)rightBottom_.y,
		0, 0,
		128, 128,
		gh_,
		0xFF0000FF
	);
}

bool EnemyDeadParticle::GetDelFlag()
{
	return del_;
}
