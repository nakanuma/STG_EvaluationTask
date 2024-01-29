#include "BulletHitEmitter.h"
#include "Util.h"

BulletHitEmitter::BulletHitEmitter()
{
}

BulletHitEmitter::~BulletHitEmitter()
{
}

void BulletHitEmitter::Update()
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

void BulletHitEmitter::Draw()
{
	// パーティクル全ての描画処理を呼ぶ
	for (auto& particle : particleList) {
		particle.Draw();
	}
}

void BulletHitEmitter::Emit(Vector2 pos)
{
	for (int i = 0; i < particleEmitNum; i++) {
		float particleX = pos.x;
		float particleY = pos.y;

		float velocityX = RandomFloat(-6.0f, 6.0f);
		float velocityY = RandomFloat(-6.0f, 6.0f);

		float size = RandomFloat(32.0f, 32.0f);

		BulletHitParticle newParticle = BulletHitParticle({ particleX,particleY }, { velocityX,velocityY }, size);
		particleList.push_back(newParticle);
	}
}

void BulletHitEmitter::listClear()
{
	particleList.clear();
}
