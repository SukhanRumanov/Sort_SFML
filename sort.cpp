#include "sort.hpp"

void drawBars(sf::RenderWindow& window, const std::vector<int>& arr, int compare1, int compare2, int swapped1, int swapped2) {
    window.clear(sf::Color::Black);

    int barSpacing = (WINDOW_WIDTH - NUM_BARS * BAR_WIDTH) / NUM_BARS;

    for (size_t i = 0; i < arr.size(); ++i) {
        sf::RectangleShape bar(sf::Vector2f(BAR_WIDTH, -arr[i]));
        bar.setPosition(barSpacing + i * (BAR_WIDTH + barSpacing), WINDOW_HEIGHT);

        if (i == compare1 || i == compare2) {
            bar.setFillColor(sf::Color::Red);
        }
        else if (i == swapped1 || i == swapped2) {
            bar.setFillColor(sf::Color::Green);
        }
        else {
            bar.setFillColor(sf::Color::Blue);
        }

        window.draw(bar);
    }

    window.display();
}

void bubbleSort(sf::RenderWindow& window, std::vector<int>& arr) {
    size_t n = arr.size();
    sf::Clock clock;
    const float delay = 0.2f;

    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            clock.restart();

            drawBars(window, arr, j, j + 1, -1, -1);

            while (clock.getElapsedTime().asSeconds() < delay) {
                sf::Event event;
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                        return;
                    }
                }
            }

            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);

                clock.restart();
                drawBars(window, arr, -1, -1, j, j + 1);

                while (clock.getElapsedTime().asSeconds() < delay) {
                    sf::Event event;
                    while (window.pollEvent(event)) {
                        if (event.type == sf::Event::Closed) {
                            window.close();
                            return;
                        }
                    }
                }
            }
        }
    }

    drawBars(window, arr, -1, -1, -1, -1);
}