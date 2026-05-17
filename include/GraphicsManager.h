#ifndef GRAPHICSMANAGER_H
#define GRAPHICSMANAGER_H
#include <SFML/Graphics.hpp>
#include <memory>

class GraphicsManager
{
    public:
        static void setWindow(sf::RenderWindow& window);
        static sf::RenderWindow& getWindow();

    protected:

    private:
        static sf::RenderWindow* _window;

};

#endif // GRAPHICSMANAGER_H
