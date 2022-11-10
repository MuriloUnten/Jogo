#pragma once

#define WIDTH 960
#define HEIGHT 540

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

		sf::Clock clock;
		float deltaTime;


	public:
		~GraphicsManager();

		static GraphicsManager* getInstance();
		static void deleteInstance();

		bool isWindowOpen();
		void clear();
		void close();
		void display();
		sf::RenderWindow* getWindow();

		void updateDeltaTime();
		const float getDeltaTime() const;
	};
}// namespace Managers