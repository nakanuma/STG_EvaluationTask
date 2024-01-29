#pragma once
#include <cstdlib>
#include <ctime>
#include <utility>

// 指定した範囲の乱数を生成する関数
int Random(int min, int max);

//乱数生成機を初期化する関数
void InitRandomSeed();

// 指定した範囲の浮動小数点数をランダムに生成する関数
float RandomFloat(float min, float max);

