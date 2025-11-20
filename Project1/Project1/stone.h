#pragma once
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <array>

class Stone : public sf::RectangleShape {
public:
    static std::array<sf::Color, 4> LUT;

    Stone(sf::Vector2f pos, sf::Vector2f size, int L);

    void trafienie();
    bool destroyed() const { return hp == 0; }

private:
    void updateColor();

    int hp;
    bool dead;
};