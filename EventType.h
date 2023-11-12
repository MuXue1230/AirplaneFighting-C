#pragma once
#include "Listener.h"

#define EVENT               0x00

#define PRE_INIT_EVENT      0x10
#define INIT_EVENT          0x11
#define EXIT_EVENT          0x12
#define RELOAD_EVENT        0x13

#define LOAD_EVENT          0x20
#define UNLOAD_EVENT        0x21

#define GUI_OPEN_EVENT      0x30
#define GUI_CLOSE_EVENT     0x31
#define PLANE_CRASH_EVENT   0x32
#define PLANE_SPAWN_EVENT   0x33
#define BOMB_EVENT          0x34
#define SUPPLY_EVENT        0x35
#define NO_HIT_EVENT        0x36
#define DOUBLE_BULLET_EVENT 0x37
#define UPGRADE_EVENT       0x38

struct ListenerList
{
	int ListenerType;
	Listener listener;
};
