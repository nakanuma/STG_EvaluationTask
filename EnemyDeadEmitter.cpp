#include "EnemyDeadEmitter.h"
#include "Util.h"

EnemyDeadEmitter::EnemyDeadEmitter()
{
}

EnemyDeadEmitter::~EnemyDeadEmitter()
{
}

void EnemyDeadEmitter::Update()
{
	// パーティクル全ての更新処理を呼ぶ
	for (auto itr = particleList.begin(); itr != particleList.end();) {
		itr->Update();

		// DelFlagがtrueだったら
		if (itr->GetDelFlag()) {
			itr = particleList.erase(itr);
		} else {
			itr++; // eraseしなかった場合のみイテレーターをインクリメント
		}
	}
}

void EnemyDeadEmitter::Draw()
{
	// パーティクル全ての描画処理を呼ぶ
	for (auto& particle : particleList) {
		particle.Draw();
	}
}

void EnemyDeadEmitter::Emit(Vector2 pos)
{
	for (int i = 0; i < particleEmitNum; i++) {
		float particleX = pos.x;
		float particleY = pos.y;

		float velocityX = RandomFloat(-8.0f, 8.0f);
		float velocityY = RandomFloat(-8.0f, 8.0f);

		float size = RandomFloat(128.0f, 128.0f);

		EnemyDeadParticle newParticle = EnemyDeadParticle({ particleX,particleY }, { velocityX,velocityY }, size);
		particleList.push_back(newParticle);
	}
}

void EnemyDeadEmitter::listClear()
{
	particleList.clear();
}
