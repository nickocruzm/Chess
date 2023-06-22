#ifndef __CHESSBOARD_H__
#define __CHESSBOARD_H__

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

using sf::Sprite;

class Chessboard {
    private:
        std::vector<Sprite> boardSprite;
        sf::Font font;
        std::vector<sf::Text> coord_text;

    public: 
        // Initialize the chessboard and fill it with chess pieces
        Chessboard(sf::Texture& light_texture, sf::Texture& dark_texture);

        // update the chessboard and chess piece textures
        void renderBoard(sf::RenderWindow& window);
};

#endif