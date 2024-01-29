#include "SceneManager.h"

void SceneManager::Run()
{
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

		// ゲームに遷移する処理
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			currentScene = GAME;
			// オブジェクトの初期化を行う
			game.enemy_->Initialize();
			game.player_->Initialize();

			game.bulletHitEmitter_.listClear();
			game.enemyDeadEmitter_.listClear();

			isWin = false;
		}

		break;

	case GAME:

		// ゲームの更新処理
		game.Update();

		// ゲームの描画処理
		game.Draw();

		// リザルトに遷移する処理
		if (game.enemy_->GetLife() == 0) {
			if (game.enemy_->GetReviveTimer() < 30) { // 敵が撃破されてから少し間を空ける
				currentScene = RESULT;
				isWin = true;
			}
		} else if (game.player_->GetHp() == 0) {
			currentScene = RESULT;
			isWin = false;
		}

		break;

	case RESULT:

		// リザルトの更新処理
		result.Update();

		// リザルトの描画処理
		result.Draw();
		if (isWin == true) {
			result.DrawWin();
		} else {
			result.DrawLose();
		}

		// タイトルに遷移する処理
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
			currentScene = TITLE;
		}

		break;

	default:
		break;
	}

	// フレームの終了
	Novice::EndFrame();
}
