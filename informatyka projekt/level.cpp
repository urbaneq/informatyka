#include "Level.h"

std::vector<Stone> Level::generate(float W) {
    const int COL = 6;
    const int ROW = 7;
    const float H = 25.f;
    const float GAP = 2.f;

    float blockW = (W - (COL - 1) * GAP) / COL;

    std::vector<Stone> out;
    out.reserve(COL * ROW);

    for (int r = 0; r < ROW; r++) {
        for (int c = 0; c < COL; c++) {
            float x = c * (blockW + GAP);
            float y = 40 + r * (H + GAP);
            int hp = 3 - (r % 3);
            out.emplace_back(sf::Vector2f{ x,y }, sf::Vector2f{ blockW,H }, hp);
        }
    }
    return out;
}

void Level::draw(sf::RenderTarget& w, const std::vector<Stone>& b) {
    for (auto& s : b)
        if (!s.destroyed())
            w.draw(s);
}

bool Level::collideBlocks(std::vector<Stone>& blocks, Pilka& p) {
    float x = p.getX();
    float y = p.getY();
    float r = p.getRadius();
    sf::FloatRect ballBB(x - r, y - r, r * 2, r * 2);

    for (auto& s : blocks) {
        if (s.destroyed()) continue;
        if (s.getGlobalBounds().intersects(ballBB)) {
            s.trafienie();
            p.bounceY();
            return true;
        }
    }
    return false;
}