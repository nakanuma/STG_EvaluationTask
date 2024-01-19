#pragma once
#include <Novice.h>
#include "Vector2.h"

class Bullet
{
public:
	Bullet();
	~Bullet();

	void Update(Vector2 velocity);
	void Draw();

	Vector2 GetPos(); // 弾の座標を返す関数
	void SetPos(Vector2 pos); // 弾の座標を設定する関数

	bool GetIsShot(); // 弾が撃たれているかを確認する関数
	void SetIsShot(bool flag); // 弾が撃たれているかを設定する関数

private:
	int bulletGH_ = Novice::LoadTexture("./Resources/images/bullet.png");

	Vector2 pos_;
	float speed_;
	float radius_;
	bool  isShot_;
};

