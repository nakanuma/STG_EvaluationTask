#include "Title.h"

Title::Title()
{
}

Title::~Title()
{
}

void Title::Update()
{
}

void Title::Draw()
{
	// タイトル画像を描画
	Novice::DrawSprite(
		0, 0,
		titleGH_,
		1.0f, 1.0f,
		0.0f,
		0xFFFFFFFF
	);
}
