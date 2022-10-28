#pragma once

#include <SFML/Graphics.hpp>
#include "GraphicsManager.hpp"

class Arquetype
{
protected:
	int id;

public:
	Arquetype();
	~Arquetype();

	void setId(int id);
	int getId();

	//virtual void draw();

	virtual void execute() = 0;
};