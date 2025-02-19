/**
 * @file main.cpp
 * @author Gonzalo Perez Chamarro
 * @brief Main 
 * @version 1.0
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include <string>

#include "Scene.h"
#include "Kernel.h"
#include "My_Player_Controller.h"
#include "Number_Controller.h"

using namespace imeng;

int main(int argc, char * argv[])
{
	// Note: Modify this path to resources folder
	RESOURCES_PATH = "..//..//resources//";

	// CREATION OF GAME WINDOW //
	Window window{ "Test Imperfect Engine v1.0", 1080,720, false };

	// SCRIPTS REGISTER //
	My_Player_Controller* player_script = new My_Player_Controller();
	Number_Controller* number_script = new Number_Controller();

	// CREATION OF GAME SCENE //
	imeng::Scene * scene = new imeng::Scene("scene.xml", &window);
	scene->execute();

	return 0;
}
