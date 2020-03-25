#include "EntityShape2D.hpp"

using namespace pc::geom;

EntityShape2D::EntityShape2D()
{
	for (int i = 0; i < 4; i++)
		this->rectWrap.addVertex(0.0f, 0.0f);
}

EntityShape2D::EntityShape2D(const std::string &file) : Shape2D(file)
{
	for (int i = 0; i < 4; i++)
		this->rectWrap.addVertex(0.0f, 0.0f);
	this->computeRectWrap();
}

void EntityShape2D::addVertex(Vertex2D vertex)
{
	try {
		this->vertices.push_back(vertex);
		this->computeRectWrap();
	} catch (const std::exception& e) {
		std::cerr << "Shape2D::addVertex: " << e.what() << std::endl;
	}
}

void EntityShape2D::addVertex(double x, double y)
{
	try {
		this->vertices.emplace_back(x, y);
		this->computeRectWrap();
	} catch (const std::exception& e) {
		std::cerr << "Shape2D::addVertex: " << e.what() << std::endl;
	}
}

void EntityShape2D::computeRectWrap()
{
	std::vector<Vertex2D>& rectWrapVertices = this->rectWrap.getVertices();

	for (int i = 0; i < 4; i++)
	{
		rectWrapVertices[i][0] = this->vertices[0][0];
		rectWrapVertices[i][1] = this->vertices[0][1];
	}

	for (Vertex2D item : this->vertices)
	{
		// Point A (minX, minY)
		if (item[0] < rectWrapVertices[0][0]) rectWrapVertices[0][0] = item[0];
		if (item[1] < rectWrapVertices[0][1]) rectWrapVertices[0][1] = item[1];

		// Point B (maxX, minY)
		if (item[0] > rectWrapVertices[1][0]) rectWrapVertices[1][0] = item[0];
		if (item[1] < rectWrapVertices[1][1]) rectWrapVertices[1][1] = item[1];

		// Point C (maxX, maxY)
		if (item[0] > rectWrapVertices[2][0]) rectWrapVertices[2][0] = item[0];
		if (item[1] > rectWrapVertices[2][1]) rectWrapVertices[2][1] = item[1];

		// Point D (minX, maxY)
		if (item[0] < rectWrapVertices[3][0]) rectWrapVertices[3][0] = item[0];
		if (item[1] > rectWrapVertices[3][1]) rectWrapVertices[3][1] = item[1];
	}
}

Shape2D &EntityShape2D::getRectWrap()
{
	return this->rectWrap;
}

void EntityShape2D::setPosition(Vertex2D &vertex)
{
	Shape2D::setPosition(vertex);
	this->computeRectWrap();
	this->rectWrap.setPosition(vertex);
}

void EntityShape2D::setPosition(double x, double y)
{
	Shape2D::setPosition(x, y);
	this->computeRectWrap();
	this->rectWrap.setPosition(x, y);
}

void EntityShape2D::scale(float factor)
{
	Shape2D::scale(factor);
	this->computeRectWrap();
}

void EntityShape2D::rotate(float factor)
{
	Shape2D::rotate(factor);
	this->computeRectWrap();
}
