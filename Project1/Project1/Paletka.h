#pragma once
#include <SFML/Graphics.hpp>

class Paletka {
private:
    float x, y, szerokosc, wysokosc, predkosc;
    sf::RectangleShape shape;

public:
    Paletka(float x_, float y_, float szer_, float wys_, float v_)
        : x(x_), y(y_), szerokosc(szer_), wysokosc(wys_), predkosc(v_) {

        shape.setSize({ szerokosc, wysokosc });
        shape.setOrigin(szerokosc * 0.5f, wysokosc * 0.5f);
        shape.setPosition(x, y);
        shape.setFillColor(sf::Color(180, 180, 220));
        shape.setOutlineThickness(2.f);
        shape.setOutlineColor(sf::Color(40, 40, 40));
    }

    void handleInput(float WIDTH) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            x -= predkosc;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            x += predkosc;

        const float half = szerokosc * 0.5f;
        if (x - half < 0.f) x = half;
        if (x + half > WIDTH) x = WIDTH - half;

        shape.setPosition(x, y);
    }

    void draw(sf::RenderTarget& target) const { target.draw(shape); }

    float getX() const { return x; }
    float getY() const { return y; }
    float getSzerokosc() const { return szerokosc; }
    float getWysokosc() const { return wysokosc; }
};