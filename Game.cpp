#include "Game.h"

Game::Game()
{
	player_ = new Player;
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
}

void Game::Draw()
{
	// プレイヤーの描画処理
	player_->Draw();
}
