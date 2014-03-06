#include "player_controller.h"
#include "../../utils/math.h"

#include <SFML/Window/Keyboard.hpp>

using namespace s2dg::com;

const int PlayerController::CID = 0x0c934be1;
const std::string PlayerController::NAME = "PlayerController";

PlayerController::PlayerController(float speed)
: Component(PlayerController::CID, PlayerController::NAME), 
_speed(speed)
{
}


PlayerController::~PlayerController() {}

void PlayerController::update(const sf::Time& elapsed) {
	sf::Vector2f dir;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		dir.y -= 1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		dir.y += 1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		dir.x -= 1.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		dir.x += 1.f;
	}

	if (!vector::is_zero(dir)) {
		sf::Vector2f movement = vector::unit(dir) * _speed * elapsed.asSeconds();
		transform().move(movement);
	}
}
