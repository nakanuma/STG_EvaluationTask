#pragma once
#include "EnemyDeadParticle.h"
#include <list>

class EnemyDeadEmitter
{
public:
	EnemyDeadEmitter();
	~EnemyDeadEmitter();

	void Update();
	void Draw();

	void Emit(Vector2 pos);

	void listClear();

private:
	std::list<EnemyDeadParticle>particleList;
	int particleEmitNum = 16;
};

