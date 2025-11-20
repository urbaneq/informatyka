#include "Stone.h"

std::array<sf::Color, 4> Stone::LUT = {
    sf::Color(0,0,0,0),
    sf::Color::Red,
    sf::Color::Yellow,
    sf::Color::Blue
};

Stone::Stone(sf::Vector2f pos, sf::Vector2f size, int L)
    : sf::RectangleShape(size),
    hp(std::clamp(L, 0, 3)),
    dead(false) {

    setPosition(pos);
    setOutlineThickness(2.f);
    setOutlineColor(sf::Color(50, 50, 50));
    updateColor();
}

void Stone::trafienie() {
    if (dead) return;
    hp = std::max(0, hp - 1);
    if (hp == 0) dead = true;
    updateColor();
}

void Stone::updateColor() {
    setFillColor(LUT[hp]);
    if (dead) setOutlineThickness(0.f);
}