#include "Game.h"

Game::Game()
    : m_window(sf::VideoMode(640, 480), "Arkanoid"),
    m_paletka(640 * 0.5f, 480 - 40.f, 100.f, 20.f, 7.f),
    m_pilka(640 * 0.5f, 480 * 0.5f, 4.f, 3.f, 8.f)
{
    m_window.setFramerateLimit(60);
    m_bloki = Level::generate(640.f); 
}

void Game::run() {
    while (m_window.isOpen()) {
        sf::Time dt = m_deltaClock.restart();

        processEvents();
        update(dt);
        render();
    }
}

void Game::processEvents() {
    sf::Event e;
    while (m_window.pollEvent(e)) {
        if (e.type == sf::Event::Closed)
            m_window.close();
    }
}

void Game::update(sf::Time dt) {
    m_paletka.handleInput(static_cast<float>(m_window.getSize().x));

    auto ev = m_pilka.update(
        static_cast<float>(m_window.getSize().x),
        static_cast<float>(m_window.getSize().y),
        m_paletka
    );

    if (ev == BallEvent::Missed)
        m_window.close();

    Level::collideBlocks(m_bloki, m_pilka);
}

void Game::render() {
    m_window.clear(sf::Color(20, 20, 30));
    Level::draw(m_window, m_bloki);
    m_paletka.draw(m_window);
    m_pilka.draw(m_window);
    m_window.display();
}
