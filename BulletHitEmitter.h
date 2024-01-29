#pragma once
#include "BulletHitParticle.h"
#include <list>

class BulletHitEmitter
{
public:
	BulletHitEmitter();
	~BulletHitEmitter();

	void Update();
	void Draw();

	void Emit(Vector2 pos);

	void listClear();

private:
	std::list<BulletHitParticle>particleList;
	int particleEmitNum = 8;
};

