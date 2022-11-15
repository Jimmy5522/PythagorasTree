//Takes two command line arguments: the pixel size of the base and the depth desired
//Depths over 20 not recommended

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

void make(int depth, sf::RectangleShape base, sf::RenderTarget& window, sf::Color color);

int main(int argc, char* argv[])
{
  int base, depth;
  base = std::stoi(argv[1]);
  depth = std::stoi(argv[2]);
  
  sf::RenderWindow window(sf::VideoMode(base * 6, base * 4), "Pythagoras Tree");

  sf::RectangleShape original{{base, base}};
  original.setPosition(base * 2.5, base * 3);
  sf::Color color(0, 125, 0);
  
  while(window.isOpen())
    {
      sf::Event event;
      while(window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    window.close();
	}
      window.clear();
      make(depth, original, window, color);
      window.display();
    }
  
  return 0;
}

void make(int depth, sf::RectangleShape base, sf::RenderTarget& window, sf::Color color)
{
  base.setFillColor(color);
  window.draw(base);

  //Termination condition
  if(depth > 0)
    {
      sf::RectangleShape left = base;
      sf::RectangleShape right = base;
      auto size = base.getSize();
      auto offset = base.getTransform();

      //Set size
      left.setSize(size * static_cast<float>((sqrt(2.0)/2.0)));
      right.setSize(size * static_cast<float>((sqrt(2.0)/2.0)));

      left.setOrigin(0, left.getSize().y);//bottom left corner
      right.setOrigin(right.getSize());//bottom right corner

      //Sets adjusted position based on parent square
      left.setPosition(offset.transformPoint({0,0}));
      right.setPosition(offset.transformPoint({size.x, 0}));

      //Rotate about the origin
      left.rotate(-45);
      right.rotate(45);

      //Change color of this depth
      color.r = (color.b + 85) % 255;
      color.b = (color.g + 60) % 255;
      color.g = (color.r + 45) % 255;

      //Call left and right branches
      make(depth - 1, left, window, color);
      make(depth - 1, right, window, color);
    }
}
