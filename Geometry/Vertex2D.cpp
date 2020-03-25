#include "Vertex2D.hpp"

using namespace pc::geom;

Vertex2D::Vertex2D() : vertex { 0.0f, 0.0f } {}

Vertex2D::Vertex2D(double x, double y) : vertex { x, y } {}

inline std::array<double, 2> Vertex2D::get()
{
	return this->vertex;
}

void Vertex2D::set(double x, double y)
{
	this->vertex[0] = x;
	this->vertex[1] = y;
}

inline double& Vertex2D::operator[](size_t index)
{
	return this->vertex[index];
}

Vertex2D &Vertex2D::operator*=(float multiplier)
{
	this->vertex[0] *= multiplier;
	this->vertex[1] *= multiplier;
	return *this;
}

std::ostream& operator<<(std::ostream& out, pc::geom::Vertex2D& obj)
{
	return out << "{ x = " << obj[0] << ", y = " << obj[1] << " }";
}