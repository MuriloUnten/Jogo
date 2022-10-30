#include "Arquetype.hpp"

Arquetype::Arquetype()
{
	id = -1;
}


Arquetype::~Arquetype()
{
	id = -1;
}

void Arquetype::setId(const int ID)
{
	id = ID;
}


const int Arquetype::getId() const
{
	return id;
}