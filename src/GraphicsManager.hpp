#pragma once

#define WIDTH 800
#define HEIGHT 600

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
		static void deleteInstance();

		bool isWindowOpen();
		void clear();
		void close();
		void display();
		sf::RenderWindow* getWindow();
	};
}// namespace Managers