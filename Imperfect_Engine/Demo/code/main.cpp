/**
 * @file main.cpp
 * @author Gonzalo Perez Chamarro
 * @brief Main 
 * @version 0.1
 * @date 2019-01-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once

#include <string>
#include <Scene.hpp>
#include "My_Player_Controller.hpp"
#include "Number_Controller.hpp"

using namespace imeng;

int main(int argc, char * argv[])
{
	// CREACION DE LA VENTANA DE JUEGO //
	Window window{ "Test Imperfect Engine v.1.0f2", 1080,720, false };


	// REGISTRO DE SCRIPTS //

	My_Player_Controller * player_script = new My_Player_Controller();
	Number_Controller * number_script = new Number_Controller();


	// CREACION DE LA ESCENA //
	/* Nota: Si se desea compilar el proyecto, se debe modificar la ruta de resources */
	/* Nota: Tambien se debera cambiar la ruta del modelo (Render_Component)          */

	imeng::Scene * scene = new imeng::Scene("resources//scene.xml", &window);
	scene->execute();


	return 0;

}


