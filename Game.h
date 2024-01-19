#pragma once
#include "Base.h"

// Object //
#include "Player.h"

class Game : public Base
{
public:
	Game();
	~Game();

	void Update() override;
	void Draw() override;

private:
	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Player* player_; // プレイヤーのインスタンスを生成
};

