#include "Bullet.h"

Bullet::Bullet()
{
	pos_ = { 0.0f,0.0f };
	speed_ = 16.0f;
	radius_ = 16.0f;
	isShot_ = false;
}

Bullet::~Bullet()
{
}

void Bullet::Update(Vector2 velocity)
{
	// 移動処理
	if (isShot_ == true) { // 弾が撃たれているときのみ
		pos_.x += velocity.x * speed_;
		pos_.y += velocity.y * speed_;
	}

	// 画面外に出たら削除する
	if (pos_.x > 1280.0f || pos_.x < 0.0f || pos_.y > 720.0f || pos_.y < 0.0f) {
		isShot_ = false;
	}
}

void Bullet::Draw()
{
	if (isShot_ == true) {
		Novice::DrawSprite(
			(int)pos_.x - (int)radius_, (int)pos_.y - (int)radius_,
			bulletGH_,
			1.0f, 1.0f,
			0.0f,
			0xFFFFFFFF
		);
	}
}

Vector2 Bullet::GetPos()
{
	return pos_;
}

void Bullet::SetPos(Vector2 pos)
{
	pos_ = pos;
}

bool Bullet::GetIsShot()
{
	return isShot_;
}

void Bullet::SetIsShot(bool flag)
{
	isShot_ = flag;
}
