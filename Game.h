#pragma once
#include "Base.h"

// Object //
#include "Player.h"
#include "Enemy.h"

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
private:
	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
};

