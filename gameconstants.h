/*
	HEADER FILE : gameconstants
*/

#ifndef GAMECONSTANTS_H
#define GAMECONSTANTS_H

#include <iostream>

enum StartMenu {
	START_GAME,
	SETTING,
	EXIT,
	EN_MENU
};
	
const std::string startmenu_name[EN_MENU] = {"START GAME","SETTING","EXIT"};

#endif
