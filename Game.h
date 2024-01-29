#pragma once
#include "Base.h"

// Object //
#include "Player.h"
#include "Enemy.h"

// Particle //
#include "BulletHitEmitter.h"
#include "EnemyDeadEmitter.h"

class Game : public Base
{
public:
	Game();
	~Game();

	void Update() override;
	void Draw() override;

	bool CheckCollisionCircle(Vector2 pos1, float radius1, Vector2 pos2, float radius2); // 円の衝突判定を行う関数

	// インスタンスを生成
	Player* player_;
	Enemy* enemy_;

	BulletHitEmitter bulletHitEmitter_;
	EnemyDeadEmitter enemyDeadEmitter_;
private:
	int playerLetterGH_ = Novice::LoadTexture("./Resources/images/playerLetter.png"); // プレイヤーの文字
	int heartGH_ = Novice::LoadTexture("./Resources/images/heart.png"); // プレイヤーの残り体力
	int bossHpFrameGH_ = Novice::LoadTexture("./Resources/images/bossHpFrame.png"); // ボスのHPの枠
	int bossLetterGH_ = Novice::LoadTexture("./Resources/images/bossLetter.png"); // ボスの文字
	int crossGH_ = Novice::LoadTexture("./Resources/images/cross.png"); // ×記号
	int numberGH_ = Novice::LoadTexture("./Resources/images/number.png"); // 数字

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
};

