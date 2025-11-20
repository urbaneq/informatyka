#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Stone.h"
#include "Pilka.h"

namespace Level {
    std::vector<Stone> generate(float screenWidth);
    void draw(sf::RenderTarget& win, const std::vector<Stone>& blocks);
    bool collideBlocks(std::vector<Stone>& blocks, Pilka& ball);
}

