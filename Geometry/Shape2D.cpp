#include "Shape2D.hpp"
#include "../Parser/Parser.hpp"
#include <cmath>

using namespace pc::geom;

Shape2D::Shape2D(const std::string& file)
{
	std::ifstream ifs(file);

	if (ifs.is_open())
	{
		try {
			std::string line;
			while (std::getline(ifs, line))
			{
				if (utils::Parser::computeType(line) == utils::Parser::LineType::VALUE)
				{
					std::vector<std::string> values(utils::Parser::getValues(line));
					if (values.size() == 3 && values[0].compare("v") == 0)
					{
						this->addVertex(atof(values[1].c_str()), atof(values[2].c_str()));
					}
					else
					{
						std::cerr << "Shape2D::Shape2D(): invalid line." << std::endl;
					}
				}
			}

		} catch (const std::exception& e) {
			std::cerr << "Shape2D::Shape2D(): Unable to create shape from file | " << e.what() << std::endl;
		}
	}
	else
	{
		std::cerr << "Shape2D::Shape2D(): " << file << " doesn't exist." << std::endl;
	}
}

void Shape2D::addVertex(Vertex2D vertex)
{
	try {
		this->vertices.push_back(vertex);
	} catch (const std::exception& e) {
		std::cerr << "Shape2D::addVertex: " << e.what() << std::endl;
	}
}

void Shape2D::addVertex(const double x, const double y)
{
	try {
		this->vertices.emplace_back(x, y);
	} catch (const std::exception& e) {
		std::cerr << "Shape2D::addVertex: " << e.what() << std::endl;
	}
}

inline std::vector<Vertex2D>& Shape2D::getVertices()
{
	return this->vertices;
}

void Shape2D::setPosition(double x, double y)
{
	Vertex2D origin(this->vertices[0][0], this->vertices[0][1]);

	for (Vertex2D item : this->vertices)
	{
		if (item[0] < origin[0]) origin[0] = item[0];
		if (item[1] < origin[1]) origin[1] = item[1];
	}

	Vertex2D distance(origin[0] - x, origin[1] - y);

	for (Vertex2D& item : this->vertices)
	{
		item[0] -= distance[0];
		item[1] -= distance[1];
	}
}

void Shape2D::setPosition(Vertex2D& vertex)
{
	Vertex2D origin = this->getOrigin();
	Vertex2D distance(origin[0] - vertex[0], origin[1] - vertex[1]);

	for (Vertex2D& item : this->vertices)
	{
		item[0] -= distance[0];
		item[1] -= distance[1];
	}
}

void Shape2D::scale(float factor)
{
	Vertex2D pos = this->getOrigin();

	for (Vertex2D& item : this->vertices)
		item *= factor;
	this->setPosition(pos);
}

void Shape2D::rotate(float factor)
{
	for (Vertex2D& item : this->vertices)
	{
		double newX = this->getCentroid()[0] + (item[0] - this->getCentroid()[0]) * std::cos(factor) - (item[1] - this->getCentroid()[1]) * std::sin(factor);
		double newY = this->getCentroid()[1] + (item[0] - this->getCentroid()[0]) * std::sin(factor) + (item[1] - this->getCentroid()[1]) * std::cos(factor);
		item.set(newX, newY);
	}
}

Vertex2D Shape2D::getCentroid()
{
	Vertex2D centroid;
	double signedArea = 0.0f;

	for (int i = 0; i < this->vertices.size(); i++)
	{
		double x0 = this->vertices[i][0], y0 = this->vertices[i][1];
		double x1 = this->vertices[(i + 1) % this->vertices.size()][0];
		double y1 = this->vertices[(i + 1) % this->vertices.size()][1];

		double A = (x0 * y1) - (x1 * y0);
		signedArea += A;

		centroid[0] += (x0 + x1) * A;
		centroid[1] += (y0 + y1) * A;
	}

	signedArea *= 0.5;
	centroid[0] = (centroid[0]) / (6 * signedArea);
	centroid[1] = (centroid[1]) / (6 * signedArea);

	return centroid;
}

double Shape2D::getWidth()
{
	return 0;
	//return this->rectWrap[1][0] - this->rectWrap[0][0];
}

double Shape2D::getHeight()
{
	return 0;
	//return this->rectWrap[2][1] - this->rectWrap[0][1];
}

Vertex2D Shape2D::getOrigin()
{
	Vertex2D origin(this->vertices[0][0], this->vertices[0][1]);

	for (Vertex2D item : this->vertices)
	{
		if (item[0] < origin[0]) origin[0] = item[0];
		if (item[1] < origin[1]) origin[1] = item[1];
	}

	return origin;
}

std::ostream& operator<<(std::ostream& out, pc::geom::Shape2D& obj)
{
	out << "{ // Shape" << std::endl;
	for (auto item : obj.getVertices())
	{
		out << "\t" << item << std::endl;
	}
	out << '}';
	return out;
}