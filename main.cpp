#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include "sort.hpp"


int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Sort");
    std::vector<int> arr = { 150, 300, 100, 250, 400, 350, 200, 450, 50, 500 };
    bubbleSort(window, arr);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}
