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

	void setId(const int ID);
	const int getId() const;

	//virtual void draw();

	virtual void execute() = 0;
};