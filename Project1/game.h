#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Paletka.h"
#include "Pilka.h"
#include "Level.h"

class Game {
public:
    Game();
    void run();

private:

    sf::RenderWindow m_window;
    sf::Clock m_deltaClock;

    Paletka m_paletka;
    Pilka   m_pilka;
    std::vector<Stone> m_bloki;


    void processEvents();
    void update(sf::Time dt);
    void render();
};
