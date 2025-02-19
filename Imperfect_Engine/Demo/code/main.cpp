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
#include "My_Player_Controller.h"
#include "Number_Controller.h"

using namespace imeng;

int main(int argc, char * argv[])
{
	// CREATION OF GAME WINDOW //
	Window window{ "Test Imperfect Engine v.1.0f2", 1080,720, false };


	// SCRIPTS REGISTER //
	My_Player_Controller* player_script = new My_Player_Controller();
	Number_Controller* number_script = new Number_Controller();


	// CREATION OF GAME SCENE //
	/* Nota: If you want to compile the proyect, you must modify the resources path */
	/* Nota: Also model path must be changed (Render_Component)                     */

	imeng::Scene * scene = new imeng::Scene("resources//scene.xml", &window);
	scene->execute();

	return 0;

}


