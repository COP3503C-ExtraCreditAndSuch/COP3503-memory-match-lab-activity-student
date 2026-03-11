#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>
#include "card.h"



//Loads card textures from assets folder
void loadCardTextures(sf::Texture &back, std::vector<sf::Texture> &faces){

}

//Shuffles creates deck of cards from textures from faces and back and then shuffles them
void buildDeck(sf::Texture &back, std::vector<sf::Texture> &faces, std::vector<Card> &cards, int size) {

}

//Sets the layout and spacing for memory game grid
void setLayout(sf::Texture &back, std::vector<Card> &cards, unsigned int size) {

}
int main() {
    //Create game window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Memory Match");

    // Load textures
    sf::Texture back;
    std::vector<sf::Texture> faces(8);
    if (!back.loadFromFile("../assets/cards/back.png")) std::cerr << "Error loading back texture" << std::endl;

    for (int i = 0; i < 8; ++i)
        faces[i].loadFromFile("../assets/cards/" + std::to_string(i + 2) + "_of_clubs.png");



    // Build deck (16 cards: 8 pairs)
    std::vector<Card> cards;
    for (int i = 0; i < 8; ++i) {
        Card card(i, &faces[i], &back);
        cards.push_back(card);
        cards.push_back(card);
    }
    // Create a random seed from your system
    std::random_device rd;
    // Make a random number generator using that seed
    std::mt19937 gen(rd());
    // Use std::shuffle to randomly rearrange vals
    std::shuffle(cards.begin(), cards.end(), gen);


    // Layout (4x4 grid)
    float cardWidth = back.getSize().x;
    float cardHeight = back.getSize().y;
    float startX = (window.getSize().x - 4 * cardWidth) / 2.f;
    float startY = 80.f;
    for (int i = 0; i < 16; ++i)
        cards.at(i).setPosition(startX + (i % 4) * (cardWidth + 10), startY + (i / 4) * (cardHeight + 10));

    //Initialize game logic
    std::vector<int> flipped;
    sf::Clock clock;
    bool twoCardsFlipped = false;

    while (window.isOpen()) {
        while (std::optional<sf::Event> event = window.pollEvent()) {
            // Close
            if (event->is<sf::Event::Closed>()) {
                window.close();
                break;
            }


            // Left-click to flip
            if (!twoCardsFlipped) {
                if (const auto *mouse = event->getIf<sf::Event::MouseButtonPressed>()) {
                    if (mouse->button == sf::Mouse::Button::Left) {
                        //If mouse button clicked, game logic begins
                        for (int i = 0; i < 16; ++i) {
                            if (!cards[i].isUp() && !cards[i].isMatched() && cards[i].contains(sf::Vector2f(mouse->position))) {
                                cards[i].reveal();
                                flipped.push_back(i);

                                if (flipped.size() == 2) {
                                    twoCardsFlipped = true;
                                    int firstCardIndex = flipped[0];
                                    int secondCardIndex = flipped[1];
                                    if (cards[firstCardIndex].getValue() == cards[secondCardIndex].getValue()) {
                                        cards[firstCardIndex].match();
                                        cards[secondCardIndex].match();
                                        flipped.clear();
                                        twoCardsFlipped = false;

                                    } else {
                                        clock.restart(); // start mismatch delay
                                    }
                                }
                                break; // only one card per click
                            }
                        }
                    }
                }
            }
        }

        if (twoCardsFlipped && clock.getElapsedTime().asMilliseconds() > 700) {
            cards[flipped[0]].hide();
            cards[flipped[1]].hide();
            flipped.clear();
            twoCardsFlipped = false;
        }

        //draw background and cards
        window.clear(sf::Color::Black);
        for (auto &c: cards) c.draw(window);

        window.display();
    }
}




