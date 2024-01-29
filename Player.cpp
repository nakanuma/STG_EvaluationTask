#include "Player.h"

Player::Player()
{
	pos_ = { 320.0f,360.0f };
	radius_ = 32.0f;
	speed_ = 6.0f;
	hp_ = 3;
	isAlive_ = true;
	isInvincible_ = false;
	invincibleTimer_ = 60;

	for (int i = 0; i < kPlayerBulletNum; i++) {
		bullet_[i] = new Bullet;
	}
	bulletCoolDownTimer_ = 0;
}

Player::~Player()
{
}

void Player::Initialize()
{
	pos_ = { 320.0f,360.0f };
	radius_ = 32.0f;
	speed_ = 6.0f;
	hp_ = 3;
	isAlive_ = true;
	isInvincible_ = false;
	invincibleTimer_ = 60;

	for (int i = 0; i < kPlayerBulletNum; i++) {
		bullet_[i] = new Bullet;
	}
	bulletCoolDownTimer_ = 0;
}

void Player::Update(char* keys, char* preKeys)
{
	// キー入力で移動
	if (keys[DIK_W] || keys[DIK_UP]) {
		pos_.y -= speed_;
	}
	if (keys[DIK_S] || keys[DIK_DOWN]) {
		pos_.y += speed_;
	}
	if (keys[DIK_A] || keys[DIK_LEFT]) {
		pos_.x -= speed_;
	}
	if (keys[DIK_D] || keys[DIK_RIGHT]) {
		pos_.x += speed_;
	}

	// スペースを押した際に弾のクールダウンタイマーをリセット
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		bulletCoolDownTimer_ = 0;
	}

	// キー入力で弾を発射
	if (keys[DIK_SPACE]) {
		// スペースを押している間はタイマーの増加を行う
		bulletCoolDownTimer_++;
		for (int i = 0; i < kPlayerBulletNum; i++) {
			// 弾が撃たれていない状態かつ10フレームに一度
			if (bullet_[i]->GetIsShot() == false && bulletCoolDownTimer_ % 10 == 0) {
				// 弾が撃たれている状態にする
				bullet_[i]->SetIsShot(true);
				// 弾の座標をプレイヤーの座標に設定
				bullet_[i]->SetPos({ pos_.x,pos_.y });
				break;
			}
		}
	}

	// 移動制限
	pos_.x = std::clamp(pos_.x, radius_, 1280.0f - radius_);
	pos_.y = std::clamp(pos_.y, radius_, 720.0f - radius_);

	// 弾の更新処理を呼ぶ
	for (int i = 0; i < kPlayerBulletNum; i++) {
		bullet_[i]->Update({ 1.0f,0.0f });
	}

	// 無敵状態中の処理
	if (isInvincible_ == true) {
		if (invincibleTimer_ > 0) {
			invincibleTimer_--; // 無敵時間のタイマーを減らす
		} else {
			isInvincible_ = false; // 無敵状態を解除する
			invincibleTimer_ = 60; //　無敵時間のタイマーをリセット
		}
	}
}

void Player::Draw()
{
	// 弾の描画処理
	for (int i = 0; i < kPlayerBulletNum; i++) {
		bullet_[i]->Draw();
	}

	// プレイヤーを描画
	if (isInvincible_ == false) {
		Novice::DrawSprite(
			(int)pos_.x - (int)radius_, (int)pos_.y - (int)radius_,
			playerGH_,
			1.0f, 1.0f,
			0.0f,
			0xFFFFFFFF
		);
	}

	// 無敵時間中のプレイヤーを描画
	if (isInvincible_ == true && invincibleTimer_ % 3 == 0) {
		Novice::DrawSprite(
			(int)pos_.x - (int)radius_, (int)pos_.y - (int)radius_,
			playerGH_,
			1.0f, 1.0f,
			0.0f,
			0xFFFFFFFF
		);
	}

	/*Novice::ScreenPrintf(0, 100, "playerHP = %d", hp_);
	Novice::ScreenPrintf(0, 120, "isInvincivle = %d", isInvincible_);
	Novice::ScreenPrintf(0, 140, "invincivleTimer = %d", invincibleTimer_);*/

}

void Player::OnCollision()
{
	hp_--; // 体力を減らす
	isInvincible_ = true; // 無敵にする
}

Vector2 Player::GetPos()
{
	return pos_;
}

float Player::GetRadius()
{
	return radius_;
}

bool Player::IsInvincivle()
{
	return isInvincible_;
}

int Player::GetHp()
{
	return hp_;
}
