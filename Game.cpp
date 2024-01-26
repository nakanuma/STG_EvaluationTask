#include "Game.h"

Game::Game()
{
	player_ = new Player;
	enemy_ = new Enemy;
}

Game::~Game()
{
}

void Game::Update()
{
	// キー入力を受け取る
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

	// プレイヤーの更新処理
	player_->Update(keys,preKeys);

	// 敵の更新処理
	enemy_->Update();

	// プレイヤーが敵に衝突した際の処理
	if (CheckCollisionCircle(player_->GetPos(), player_->GetRadius(), enemy_->GetPos(), enemy_->GetRadius())) {
		if (player_->IsInvincivle() == false && enemy_->GetIsAlive() == true) { // プレイヤーが無敵じゃない場合かつ、敵が生きているときのみ
			player_->OnCollision(); // プレイヤーの衝突時の処理を呼び出す
		}
	}

	// プレイヤーの弾が敵に衝突した際の処理
	for (int i = 0; i < kPlayerBulletNum; i++) {
		if (CheckCollisionCircle(player_->bullet_[i]->GetPos(), player_->bullet_[i]->GetRadius(), enemy_->GetPos(), enemy_->GetRadius())) {
			if (player_->bullet_[i]->GetIsShot() == true && enemy_->GetIsAlive()) { // プレイヤーの弾が発射されているかつ、敵が生きている場合のみ
				player_->bullet_[i]->SetIsShot(false); // プレイヤーの弾を消す
				enemy_->OnCollision(); // 敵の衝突時の処理を呼び出す

				break;
			}
		}
	}
}

void Game::Draw()
{
	// プレイヤーの描画処理
	player_->Draw();

	// 敵の描画処理
	enemy_->Draw();
}

bool Game::CheckCollisionCircle(Vector2 pos1, float radius1, Vector2 pos2, float radius2)
{
	float distance = sqrtf((pos2.x - pos1.x) * (pos2.x - pos1.x) + (pos2.y - pos1.y) * (pos2.y - pos1.y));

	if (distance <= radius1 + radius2) {
		return true;
	} else {
		return false;
	}
}
