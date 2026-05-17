#include "GraphicsManager.h"


sf::RenderWindow* GraphicsManager::_window = nullptr;

void GraphicsManager::setWindow(sf::RenderWindow& window)
{
    _window = &window;
}

sf::RenderWindow& GraphicsManager::getWindow()
{
    return *_window;
}
