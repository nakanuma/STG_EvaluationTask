#pragma once
#include "Base.h"

class Title : public Base
{
public:
	Title();
	~Title();

	void Update() override;
	void Draw() override;

private:
	int titleGH_ = Novice::LoadTexture("./Resources/images/title.png");
};

