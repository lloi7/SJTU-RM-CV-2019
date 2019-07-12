//
// Created by sun on 19-7-11.
//

#include "energy/energy.h"
#include "log.h"

using namespace std;
using namespace cv;


//----------------------------------------------------------------------------------------------------------------------
// 此函数用于判断大符模式是否可以发弹
// ---------------------------------------------------------------------------------------------------------------------
void Energy::judgeBigShoot() {
    if (abs(yaw_rotation - mcuData.curr_yaw) < 0.3 && fabs(pitch_rotation - mcuData.curr_pitch) < 0.3) {
        shoot = true;
        isPredicting = false;
        isGuessing = true;
        startguessing = true;
        gettimeofday(&time_start_guess, NULL);
        LOGM(STR_CTR(WORD_LIGHT_RED, "Start Guessing!"));
    } else
        shoot = false;
}


//----------------------------------------------------------------------------------------------------------------------
// 此函数用于判断小符模式是否可以发弹
// ---------------------------------------------------------------------------------------------------------------------
void Energy::judgeSmallShoot() {
    if (fabs(yaw_rotation) < 0.3 && fabs(pitch_rotation) < 0.3) {
        shoot = true;
        isPredicting = false;
        isGuessing = true;
    } else
        shoot = false;
}