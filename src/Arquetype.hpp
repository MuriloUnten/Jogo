#pragma once

#include <SFML/Graphics.hpp>

class Arquetype
{
protected:
	int id;

public:
	Arquetype();
	~Arquetype();

	void setId(const int ID);
	const int getId() const;

	virtual void draw() = 0;
	virtual void execute() = 0;
};