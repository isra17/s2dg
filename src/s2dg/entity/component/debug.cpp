#include "debug.h"

using namespace s2dg::com;

const int Debug::CID = 0xfe24603a;
const std::string Debug::NAME = "Debug";

Debug::Debug() 
: Component(Debug::CID, Debug::NAME), _drawable(new sf::RectangleShape(sf::Vector2f(50,50)))
{
	_drawable->setOutlineColor(sf::Color::Red);
	_drawable->setOutlineThickness(-2.f);
}


Debug::~Debug() {}


void Debug::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(*_drawable, states);
}