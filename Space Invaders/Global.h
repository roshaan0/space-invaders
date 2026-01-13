#pragma once
//Global variables for all the classes
#include <cmath>
constexpr unsigned char BASEGAME_SIZE = 100; //?
constexpr unsigned char BULLETSPEEDFORENEMY = 7;
constexpr unsigned char HITTIMERFORENEMY= 2; //?
constexpr unsigned char HITTIMERFORPLAYER= 10; //?
constexpr unsigned char MOVEMENTSPEED = 5;
constexpr unsigned char ENEMYTYPES = 14;
constexpr unsigned char TRANSITION = 64;
constexpr unsigned char EXPLOSIONSPEED = 2; //?
constexpr unsigned char RELODTIME= 7;   //?
constexpr unsigned char BULLETSPEEDFORPLAYER = 10;
constexpr unsigned char MOVESPEED = 3;
constexpr unsigned char PLAYERSPEED = 5;
constexpr unsigned char ANIMATIONSPEED = 16;    //?
constexpr unsigned char SPEEDADDON = 2;
constexpr unsigned char ADDONTYPES = 4;
constexpr unsigned char RELOADTIME = 31;
constexpr unsigned char RESIZE = 4; //?
constexpr unsigned char TLEVELS= 3;
constexpr unsigned short SHOOTCHANCEFORENEMY = 2048;
constexpr unsigned short SHOOTCHANCEFORENEMY_INCREASE = 64;
constexpr unsigned short SHOOTCHANCEFORENEMY_MIN = 1024;
constexpr unsigned short ADDONTIMER = 512;
constexpr unsigned short WIDTH = 800;
constexpr unsigned short HEIGHT = 600;
constexpr unsigned short ADDONTIMER_MIN = 100;
constexpr unsigned short BOSSTIMER_MAX = 1024;  //?
constexpr unsigned short BOSSTIMER_MIN = 700;
constexpr std::chrono::microseconds FRAME_DURATION(16667);
extern unsigned short score;
extern bool pause;