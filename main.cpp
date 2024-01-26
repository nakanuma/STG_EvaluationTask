#include <Novice.h>

// Scene //
#include "Base.h"
#include "Title.h"
#include "Game.h"
#include "Result.h"

enum Scene {
	TITLE,
	GAME,
	RESULT,
};

const char kWindowTitle[] = "STG";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// インスタンスの生成 //

	Title title;
	Game game;
	Result result;

	Scene currentScene = TITLE; // 現在のシーンをここで変更

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		switch (currentScene) {
		case TITLE:
			
			// タイトルの更新処理
			title.Update();

			// タイトルの描画処理
			title.Draw();

			// ここにゲームに遷移する処理
			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				currentScene = GAME;
				game.enemy_->Initialize();
				game.player_->Initialize();
			}

			break;

		case GAME:

			// ゲームの更新処理
			game.Update();

			// ゲームの描画処理
			game.Draw();

			// ここにリザルトに遷移する処理
			if (game.enemy_->GetLife() == 0) {
				currentScene = RESULT;
			} else if (game.player_->GetHp() == 0) {
				currentScene = RESULT;
			}

			break;

		case RESULT:

			// リザルトの更新処理
			result.Update();

			// リザルトの描画処理
			result.Draw();

			// ここにタイトルに遷移する処理
			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				currentScene = TITLE;
			}

			break;

		default:
			break;
		}

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
