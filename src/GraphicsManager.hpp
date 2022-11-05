#pragma once

#include <SFML/Graphics.hpp>


namespace Managers
{
	class GraphicsManager
	{
	private:
		sf::RenderWindow* window;

		/* Singleton Design pattern */
		static GraphicsManager* instance;
		GraphicsManager();

	public:
		~GraphicsManager();

		static GraphicsManager* getInstance();

		bool isWindowOpen();
		void clear();
		void close();
		void display();
		sf::RenderWindow* getWindow();
	};
}// namespace Managers