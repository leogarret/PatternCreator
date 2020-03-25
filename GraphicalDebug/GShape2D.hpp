#ifndef PATTERNCREATOR_GSHAPE2D_HPP
#define PATTERNCREATOR_GSHAPE2D_HPP

#include "../Geometry/Shape2D.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace pc::debug {

	/**
	 * @class Graphics shape for debug.
	 */
	 class GShape2D : private sf::ConvexShape {
	 	 public:
	 		/**
	 		 * Create 2D graphics shape from Shape2D.
	 		 * @param shape
	 		 */
			explicit GShape2D(geom::Shape2D& shape);

			/**
			 * Draw the current shape into window given as parameter.
			 * @param window
			 */
			void draw(sf::RenderWindow& window);
			/**
			 * Change color of current shape.
			 * @param r red value between 0 and 255
			 * @param g green value between 0 and 255
			 * @param b blue value between 0 and 255
			 */
			void setFillColor(float r, float g, float b);
			/**
			 * Update all attributes with connected shape.
			 */
			void updateAttributes();

		 private:
	 		geom::Shape2D& linkedShape;
	};
}

#endif //PATTERNCREATOR_GSHAPE2D_HPP
