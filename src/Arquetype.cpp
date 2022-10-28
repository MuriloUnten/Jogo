#include "Arquetype.hpp"

Arquetype::Arquetype()
{
	id = -1;
}


Arquetype::~Arquetype()
{
	id = -1;
}

void Arquetype::setId(int id)
{
	id = id;
}


int Arquetype::getId()
{
	return id;
}