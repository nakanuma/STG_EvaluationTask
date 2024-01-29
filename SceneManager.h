#pragma once
#include <Novice.h>
#include "Base.h"
#include "Title.h"
#include "Game.h"
#include "Result.h"

enum Scene {
	TITLE,
	GAME,
	RESULT,
};

class SceneManager
{
public:
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// インスタンスの生成 //
	Title title;
	Game game;
	Result result;

	Scene currentScene = TITLE;

	bool isWin = false;

	void Run();
};

