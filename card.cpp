#include <SFML/Graphics.hpp>
#include "card.h"

Card::Card(int v, const sf::Texture *f, const sf::Texture *b)
: value(v), face(f), back(b), sprite(*b) {
    faceUp = false;
    matched = false;
}

void Card::setPosition(float x, float y)
{
    sprite.setPosition(sf::Vector2f(x, y));
}

bool Card::contains(sf::Vector2f p) const
{
    return sprite.getGlobalBounds().contains(p);
}

void Card::reveal() {
    if (!matched) {
        faceUp = true;
        sprite.setTexture(*face);
    }
}

void Card::hide() {
    if (!matched) {
        faceUp = false;
        sprite.setTexture(*back);
    }
}

void Card::match() {
    matched = true;
    sprite.setTexture(*face);
}

bool Card::isUp() const {
    return faceUp;
}

bool Card::isMatched() const {
    return matched;
}

int Card::getValue() const {
    return value;
}

void Card::draw(sf::RenderWindow &w) const {
    w.draw(sprite);
}