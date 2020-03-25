#ifndef PATTERNCREATOR_VERTEX2D_HPP
#define PATTERNCREATOR_VERTEX2D_HPP

#include <array>
#include <iostream>

namespace pc::geom {

	/**
	 * @class 2D vertex with x and y values.
	 */
	class Vertex2D {
		 public:
			Vertex2D();
			Vertex2D(double x, double y);

			/**
			 * Get an array with x and y of current vertex.
			 * @return an array with x and y
			 */
			std::array<double, 2> get();
			/**
			 * Set x and y of current vertex.
			 * @param x value of x
			 * @param y value of y
			 */
			void set(double x, double y);
			/**
			 * Get a value of vertex.
			 * @return value
			 */
			double& operator[](size_t index);
			/**
			 * Multiply current vertex by n.
			 * @param multiplier
			 */
			Vertex2D& operator*=(float multiplier);

		 private:
			std::array<double, 2> vertex { 0.0f, 0.0f };
	};

}

std::ostream& operator<<(std::ostream&, pc::geom::Vertex2D&);

#endif //PATTERNCREATOR_VERTEX2D_HPP
