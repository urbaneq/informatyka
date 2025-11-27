#include "gamestate.h"
#include <iostream>
#include "Paletka.h"
#include "Pilka.h"
#include "stone.h"



bool GameState::saveToFile(const std::string& filename) {
    
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Blad: Nie mozna otworzyc pliku " << filename << " do zapisu." << std::endl;
        return false;
    }

   
    file << "PADDLE " << paletka.getX() << " " << paletka.getY() << "\n";

   
    file << "BALL " << pilka.getX() << " " << pilka.getY()
        << " " << pilka.getVx << " " << pilka.getVy << "\n";

 
    file << "BLOCKS_COUNT " << blocks.size() << "\n";


    for (const auto& block : blocks) {
     
        file << block.position.x << " " << block.position.y << " " << block.hp << "\n";
    }


    return true;
}