#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int BAR_WIDTH = 60;
const int NUM_BARS = 10;
void bubbleSort(sf::RenderWindow& window, std::vector<int>& arr);