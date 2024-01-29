#include "Title.h"

Title::Title()
{
	count_ = 0;
}

Title::~Title()
{
}

void Title::Update()
{
	count_++;
}

void Title::Draw()
{
	// タイトル画像を描画
	Novice::DrawSprite(
		200,(int) (80 + sinf((float)count_ * (float)M_PI * 2.0f / 180.f) * 30), 
		titleGH_,
		1.0f, 1.0f,
		0.0f,
		0xFFFFFFFF
	);

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
