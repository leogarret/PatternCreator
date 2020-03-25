//
// Created by leo on 20/03/2020.
//

#include "GShape2D.hpp"

using namespace pc;
using namespace debug;
using namespace geom;

GShape2D::GShape2D(pc::geom::Shape2D& shape) : linkedShape(shape)
{
	this->setPointCount(this->linkedShape.getVertices().size());

	int i = 0;
	for (auto& elem : this->linkedShape.getVertices())
	{
		this->setPoint(i++, sf::Vector2f(elem[0], elem[1]));
	}
}

void GShape2D::draw(sf::RenderWindow &window)
{
	window.draw(*this);
}

void GShape2D::setFillColor(float r, float g, float b)
{
	ConvexShape::setFillColor(sf::Color(r, g, b));
}

void GShape2D::updateAttributes()
{
	this->setPointCount(this->linkedShape.getVertices().size());

	int i = 0;
	for (auto& elem : this->linkedShape.getVertices())
	{
		this->setPoint(i++, sf::Vector2f(elem[0], elem[1]));
	}
}
