#pragma once
#include <SFML/Graphics.hpp>

class Paletka;

enum class BallEvent { None, HitPaddle, Missed };

class Pilka {
private:
    float x, y, vx, vy, radius;
    sf::CircleShape shape;

public:
    Pilka(float x_, float y_, float vx_, float vy_, float r_)
        : x(x_), y(y_), vx(vx_), vy(vy_), radius(r_) {

        shape.setRadius(radius);
        shape.setOrigin(radius, radius);
        shape.setFillColor(sf::Color::White);
        shape.setPosition(x, y);
    }

    void move() {
        x += vx;
        y += vy;
        shape.setPosition(x, y);
    }

    void bounceX() { vx = -vx; }
    void bounceY() { vy = -vy; }

    void collideWalls(float width, float height) {
        if (x - radius <= 0.f) { x = radius; bounceX(); }
        if (x + radius >= width) { x = width - radius; bounceX(); }
        if (y - radius <= 0.f) { y = radius; bounceY(); }
    }

    bool collidePaddle(const Paletka& p);
    BallEvent update(float w, float h, const Paletka& p);

    void draw(sf::RenderTarget& t) const { t.draw(shape); }

    float getX() const { return x; }
    float getY() const { return y; }
    float getRadius() const { return radius; }
};
