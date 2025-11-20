#include "Pilka.h"
#include "Paletka.h"
#include <cmath>

bool Pilka::collidePaddle(const Paletka& pal) {
    float px = pal.getX();
    float py = pal.getY();
    float pw = pal.getSzerokosc();
    float ph = pal.getWysokosc();

    float left = px - pw * 0.5f;
    float right = px + pw * 0.5f;
    float top = py - ph * 0.5f;

    bool insideX = (x >= left && x <= right);
    bool hitTop = (y + radius >= top && y - radius < top);

    if (insideX && hitTop) {
        vy = -std::abs(vy);
        y = top - radius;
        shape.setPosition(x, y);
        return true;
    }
    return false;
}

BallEvent Pilka::update(float W, float H, const Paletka& pal) {
    move();
    collideWalls(W, H);

    if (collidePaddle(pal)) return BallEvent::HitPaddle;
    if (y - radius > H) return BallEvent::Missed;
    return BallEvent::None;
}