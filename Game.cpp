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

				// 弾が衝突した際のパーティクルを生成する
				bulletHitEmitter_.Emit(player_->bullet_[i]->GetPos());
				break;
			}
		}
	}

	// 敵のライフが減った際にパーティクルを生成
	if (enemy_->GetHp() <= 0 && enemy_->GetIsAlive() == true) {
		enemyDeadEmitter_.Emit(enemy_->GetPos());
	}

	// パーティクルの更新処理
	bulletHitEmitter_.Update();
	enemyDeadEmitter_.Update();
}

void Game::Draw()
{
	// プレイヤーの描画処理
	player_->Draw();

	// 敵の描画処理
	enemy_->Draw();

	// プレイヤーの文字を描画
	Novice::DrawSprite(
		40, 620,
		playerLetterGH_,
		1.0f, 1.0,
		0.0f,
		0xFFFFFFFF
	);

	// プレイヤーの残りHPを描画
	for (int i = 0; i < player_->GetHp(); i++) {
		Novice::DrawSprite(
			168+(i*48), 620,
			heartGH_,
			1.0f, 1.0f,
			0.0f,
			0xFFFFFFFF
		);
	}

	// 敵の文字を描画
	Novice::DrawSprite(
		190, 30,
		bossLetterGH_,
		1.0f, 1.0f,
		0.0f,
		0xFFFFFFFF
	);
	// 記号を描画
	Novice::DrawSprite(
		890, 30,
		crossGH_,
		1.0f, 1.0f,
		0.0f,
		0xFFFFFFFF
	);
	// 敵の残りライフを描画
	if (enemy_->GetLife() >= 0 && enemy_->GetLife() <= 3) {
		Novice::DrawSpriteRect(
			890 + 64, 30,
			enemy_->GetLife() * 64, 0,
			64, 64,
			numberGH_,
			0.25f, 1.0f,
			0.0f,
			0xFFFFFFFF
		);
	}
	// 敵のHPの背景を描画
	Novice::DrawBox(
		390, 40,
		500, 50,
		0.0f,
		0x606060FF, kFillModeSolid
	);
	// 敵のHPを描画
	for (int i = 0; i < enemy_->GetHp(); i++) {
		Novice::DrawBox(
			390 + (i * 50), 40,
			50, 50,
			0.0f,
			RED, kFillModeSolid
		);
	}
	// 敵のHPの枠を描画
	Novice::DrawSprite(
		390, 40,
		bossHpFrameGH_,
		1.0f, 1.0f,
		0.0f,
		0xFFFFFFFF
	);

	// パーティクルの描画処理
	bulletHitEmitter_.Draw();
	enemyDeadEmitter_.Draw();
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
