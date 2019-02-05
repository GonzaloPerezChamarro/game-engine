#pragma once

#include "Task.hpp"

namespace imeng {

	class Update_Task :public Task{

	public:

		Update_Task(Scene & scene, int priority = 0, bool finished = false)
			:Task(scene, priority, finished)
		{}

		bool initialize() override;
		void run(float deltaTime) override;
		bool finalize() override;


	};
}
