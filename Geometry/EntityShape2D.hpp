#ifndef PATTERNCREATOR_ENTITYSHAPE2D_HPP
#define PATTERNCREATOR_ENTITYSHAPE2D_HPP

#include "Shape2D.hpp"

namespace pc::geom {

	class EntityShape2D : public Shape2D {
		 public:
			/**
			 * Create 2D shape.
			 */
			EntityShape2D();
			/**
			 * Create 2D shape from file.
			 * @param file path of pcsd file.
			 */
			explicit EntityShape2D(const std::string& file);

			/**
			 * add vertex into current shape
			 * @param vertex the vertex to add into the current shape
			 */
			void addVertex(Vertex2D vertex) override;
			/**
			 * add vertex into current shape
			 * @param vertex the vertex to add into the current shape
			 */
			void addVertex(double x, double y) override;
			/**
			 * get rectWrap of the current shape.
			 * @return a shape object that represent the rectWrap.
			 */
			Shape2D& getRectWrap();
			/**
			 * Set shape position relative to the RectWrap left-top vertex.
			 * @param vertex the new position.
			 */
			void setPosition(Vertex2D& vertex) override;
			/**
			 * Set shape position relative to the RectWrap left-top vertex.
			 * @param vertex the new position.
			 */
			void setPosition(double x, double y) override;
			/**
			 * Scale current shape by n.
			 * @param factor scale factor.
			 */
			void scale(float factor) override;

			void rotate(float factor) override ;

		 private:
			Shape2D rectWrap;
			void computeRectWrap();
	};

}

#endif //PATTERNCREATOR_ENTITYSHAPE2D_HPP
