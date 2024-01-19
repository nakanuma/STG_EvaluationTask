#include "Player.h"

Player::Player()
{
	pos_ = { 320.0f,360.0f };
	radius_ = 32.0f;
	speed_ = 6.0f;

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
}

void Player::Update(char* keys, char* preKeys)
{
	// キー入力で移動
	if (keys[DIK_W]) {
		pos_.y -= speed_;
	}
	if (keys[DIK_S]) {
		pos_.y += speed_;
	}
	if (keys[DIK_A]) {
		pos_.x -= speed_;
	}
	if (keys[DIK_D]) {
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

	// 弾の更新処理を呼ぶ
	for (int i = 0; i < kPlayerBulletNum; i++) {
		bullet_[i]->Update({ 1.0f,0.0f });
	}
}

void Player::Draw()
{
	// 弾の描画処理
	for (int i = 0; i < kPlayerBulletNum; i++) {
		bullet_[i]->Draw();
	}

	// プレイヤーを描画
	Novice::DrawSprite(
		(int)pos_.x - (int)radius_, (int)pos_.y - (int)radius_,
		playerGH_,
		1.0f, 1.0f,
		0.0f,
		0xFFFFFFFF
	);
}
