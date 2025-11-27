#include <vector>
#include <SFML/Graphics.hpp>
#include "stone.h"
#include <fstream>
#include <string>

struct BlockData {
    float x, y;
    int hp;
};

class GameState {
private:
    sf::Vector2f paddlePosition;
    sf::Vector2f ballPosition;
    sf::Vector2f ballVelocity;
    std::vector<BlockData> blocks;
public:
    void capture(const sf::Vector2f& paddle, const sf::Vector2f& ball,
        const sf::Vector2f& ballVel, const std::vector<Stone>& stoneBlocks) {
        
        paddlePosition = paddle;
        ballPosition = ball;
        ballVelocity = ballVel;

        
        blocks.clear();
        
    }

    bool saveToFile(const std::string& filename);
};