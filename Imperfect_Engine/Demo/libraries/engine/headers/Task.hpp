#pragma once

#include "Kernel.hpp"
#include "Scene.hpp"
#include "Component.hpp"

#include <list>

namespace imeng {

	class Scene;
	class Component;

	class Task {

	protected:

		int priority;
		Scene * scene;
		bool finished;

		typedef std::shared_ptr<Component> shared_component;
		std::list< shared_component> components;

	public:

		Task(Scene&, int, bool);
		//virtual ~Task();

		int get_priority()const;
		bool is_finished() const { return finished; }

		virtual bool initialize() = 0;
		virtual bool finalize() = 0;
		//virtual bool do_step(float time) = 0;

		virtual void run(float) = 0;
	};

	bool operator<(const Task& a, const Task& b)
	{
		
		return a.get_priority() < b.get_priority();
	};
}
