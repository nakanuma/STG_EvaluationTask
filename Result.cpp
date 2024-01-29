#include "Result.h"

Result::Result()
{
	count_ = 0;
}

Result::~Result()
{
}

void Result::Update()
{
	count_++;
}

void Result::Draw()
{
	// PUSH SPACE KEYの描画
	Novice::DrawSprite(
		374, 500,
		pushSpaceKeyGH_,
		1.0f, 1.0f,
		0.0f,
		0xFFFFFFFF
	);

	// 三角形を描画
	Novice::DrawSprite(
		(int)(280 + sinf((float)count_ * (float)M_PI * 4.0f / 180.f) * 20), 490,
		triangleGH_,
		1.0f, 1.0f,
		0.0f,
		0xFFFFFFFF
	);
}

void Result::DrawWin()
{
	Novice::DrawSprite(
		226, 120,
		winGH_,
		1.0f, 1.0f,
		0.0f,
		0xFFFFFFFF
	);
}

void Result::DrawLose()
{
	Novice::DrawSprite(
		170, 120,
		loseGH_,
		1.0f, 1.0f,
		0.0f,
		0xFFFFFFFF
	);
}
