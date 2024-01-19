#pragma once
#include "Base.h"

class Result : public Base
{
public:
	Result();
	~Result();

	void Update() override;
	void Draw() override;

private:
	int resultGH_ = Novice::LoadTexture("./Resources/images/result.png");
};

