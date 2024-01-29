#pragma once
#include "Base.h"
#define _USE_MATH_DEFINES
#include <math.h>

class Title : public Base
{
public:
	Title();
	~Title();

	void Update() override;
	void Draw() override;

private:
	int titleGH_ = Novice::LoadTexture("./Resources/images/title.png");
	int pushSpaceKeyGH_ = Novice::LoadTexture("./Resources/images/pushSpaceKey.png");
	int triangleGH_ = Novice::LoadTexture("./Resources/images/triangle.png");

	int count_;
};

