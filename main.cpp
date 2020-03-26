#include "Geometry/Shape2D.hpp"
#include "GraphicalDebug/GShape2D.hpp"
#include "Geometry/EntityShape2D.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 5;

	sf::RenderWindow window(sf::VideoMode(1280, 720), "PatternCreator", sf::Style::Default, settings);
	sf::Event event	{};

	pc::geom::EntityShape2D pcShape("../shape.pcsd");
	pcShape.setPosition(150, 150);

	pc::debug::GShape2D gShape(pcShape);
	gShape.setFillColor(100, 250, 50);

	pc::debug::GShape2D gRectWrap(pcShape.getRectWrap());
	gRectWrap.setFillColor(250, 100, 50);

	std::cout << "Width = " << pcShape.getWidth() << " - Height = " << pcShape.getHeight() << std::endl;
	
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		gRectWrap.draw(window);
		gShape.draw(window);

		window.display();
		window.clear();
	}

	return 0;
}
