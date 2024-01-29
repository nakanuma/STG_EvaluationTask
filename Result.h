#pragma once
#include "Base.h"
#define _USE_MATH_DEFINES
#include <math.h>

class Result : public Base
{
public:
	Result();
	~Result();

	void Update() override;
	void Draw() override;

	void DrawWin();
	void DrawLose();

private:
	int pushSpaceKeyGH_ = Novice::LoadTexture("./Resources/images/pushSpaceKey.png");
	int triangleGH_ = Novice::LoadTexture("./Resources/images/triangle.png");
	int winGH_ = Novice::LoadTexture("./Resources/images/resultWin.png");
	int loseGH_ = Novice::LoadTexture("./Resources/images/resultLose.png");

	int count_;
};

