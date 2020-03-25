#ifndef PATTERNCREATOR_SHAPE2D_HPP
#define PATTERNCREATOR_SHAPE2D_HPP

#include <vector>
#include <exception>
#include <iostream>
#include <fstream>
#include "Vertex2D.hpp"

namespace pc::geom {

	/**
	 * @class create a 2D shape with a list of vertices.
	 */
	class Shape2D {
		 public:
			Shape2D() = default;
			/**
			 * Create shape from file.
			 * @param file path of pcsd file.
			 */
			explicit Shape2D(const std::string& file);

			/**
			 * Add vertex into current shape
			 * @param vertex the vertex to add into the current shape
			 */
			virtual void addVertex(Vertex2D vertex);
			/**
			 * Add vertex into current shape
			 * @param vertex the vertex to add into the current shape
			 */
			virtual void addVertex(double x, double y);
			/**
			 * Get all vertices of the current shape.
			 * @return a vector that hold all vertices.
			 */
			std::vector<Vertex2D>& getVertices();
			/**
			 * Set shape position relative to the RectWrap left-top vertex.
			 * @param vertex the new position.
			 */
			virtual void setPosition(Vertex2D& vertex);
			/**
			 * Set shape position relative to the RectWrap left-top vertex.
			 * @param vertex the new position.
			 */
			virtual void setPosition(double x, double y);
			/**
			 * Scale current shape by n.
			 * @param factor scale factor.
			 */
			virtual void scale(float factor);
			/**
			 * Rotate shape
			 * @param factor value of rotation
			 */
			virtual void rotate(float factor);
			/**
			 * Get centroid of current shape.
			 */
			virtual Vertex2D getCentroid();
			/**
			 * Get width of the current shape.
			 * @return a decimal number.
			 */
			double getWidth();
			/**
			 * Get height of the current shape.
			 * @return a decimal number.
			 */
			double getHeight();
			/**
			 * Get origin of current shape.
			 * @return origin vertex.
			 */
			Vertex2D getOrigin();

		 protected:
			std::vector<Vertex2D> vertices;
	};

}

std::ostream& operator<<(std::ostream&, pc::geom::Shape2D&);

#endif //PATTERNCREATOR_SHAPE2D_HPP
