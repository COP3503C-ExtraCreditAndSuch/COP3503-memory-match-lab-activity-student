
#include <SFML/Graphics.hpp>
#pragma once

class Card {
    int value;
    const sf::Texture *face;
    const sf::Texture *back;
    sf::Sprite sprite;
    bool faceUp;
    bool matched;

public:
    Card(int v, const sf::Texture *f, const sf::Texture *b);

    void setPosition(float x, float y);

    bool contains(sf::Vector2f p) const;

    void reveal();

    void hide();

    void match();

    bool isUp() const;

    bool isMatched() const;

    int getValue() const;

    void draw(sf::RenderWindow &w) const;
};

