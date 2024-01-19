#include "Result.h"

Result::Result()
{
}

Result::~Result()
{
}

void Result::Update()
{
}

void Result::Draw()
{
	// リザルトの画像を描画
	Novice::DrawSprite(
		0, 0,
		resultGH_,
		1.0f, 1.0f,
		0.0f,
		0xFFFFFFFF
	);
}
