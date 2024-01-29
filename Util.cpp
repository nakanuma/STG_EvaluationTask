#include "Util.h"
#include <Novice.h>

// 指定した範囲の乱数を生成する関数
int Random(int min, int max) {
    int range = max - min + 1;

    return rand() % range + min;
}

void InitRandomSeed()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

float RandomFloat(float min, float max)
{
    if (min > max) {
        // 範囲が逆転している場合は交換する
        std::swap(min, max);
    }

    // 0.0以上1.0未満の乱数を生成し、それを範囲にスケーリングする
    return min + static_cast<float>(std::rand()) / RAND_MAX * (max - min);
}

