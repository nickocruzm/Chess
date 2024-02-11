#include "Chessboard.h"

Chessboard::Chessboard(sf::Texture& l_texture, sf::Texture& d_texture) {
    Sprite light_green_sq;
    light_green_sq.setTexture(l_texture);
    light_green_sq.scale(1.5, 1.5);
    // light_green_sq.setPosition(0, 0);
    light_green_sq.setPosition(120, 120);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            boardSprite.push_back(light_green_sq);
            light_green_sq.move(240, 0);
        }
        light_green_sq.move(-960, 240);
    } 
    // light_green_sq.setPosition(120, 120);
    light_green_sq.setPosition(240, 240);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            boardSprite.push_back(light_green_sq);
            light_green_sq.move(240, 0);
        }
        light_green_sq.move(-960, 240);
    } 

    Sprite dark_green_sq;
    dark_green_sq.setTexture(d_texture);
    dark_green_sq.setScale(1.5, 1.5);
    // dark_green_sq.setPosition(120, 0);
    dark_green_sq.setPosition(240, 120);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            boardSprite.push_back(dark_green_sq);
            dark_green_sq.move(240, 0);
        }
        dark_green_sq.move(-960, 240);
    }
    // dark_green_sq.setPosition(0, 120);
    dark_green_sq.setPosition(120, 240);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            boardSprite.push_back(dark_green_sq);
            dark_green_sq.move(240, 0);
        }
        dark_green_sq.move(-960, 240);
    }

    // Load the coordinate texts and font
    if (!font.loadFromFile("assets/CourierPrime-Regular.ttf")) {
        std::cerr << "Failed to load font \"arial.ttf\"" << std::endl;
    }
    sf::Text t;
    t.setFont(font);
    t.setCharacterSize(36);
    t.setFillColor(sf::Color::White);
    for (int i = 0; i < 8; i++) {
        t.setString((char)(65 + i));
        t.setPosition(169 + i * 120, 1115);
        coord_text.push_back(t);
    }
    for (int i = 0; i < 8; i++) {
        t.setString((char)(65 + i));
        t.setPosition(169 + i * 120, 35);
        coord_text.push_back(t);
    }
    for (int i = 0; i < 8; i++) {
        t.setString((char)(49 + i));
        t.setPosition(49, 995 - i * 120);
        coord_text.push_back(t);
    }
    for (int i = 0; i < 8; i++) {
        t.setString((char)(49 + i));
        t.setPosition(1130, 995 - i * 120);
        coord_text.push_back(t);
    }
}

void Chessboard::renderBoard(sf::RenderWindow& window) {
    for (int i = 0; i < boardSprite.size(); i++) {
        window.draw(boardSprite.at(i));
    }
    for (int i = 0; i < coord_text.size(); i++) {
       window.draw(coord_text.at(i));
    }
}