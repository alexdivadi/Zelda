#include "Game.h"
#include <iostream>

int Game::GameLoop() 
{
    cmap.Create("O-1.txt", &player.getSprite(), "O-1");

    if (!background.load("Sprites/tiles.png", cmap))
        return -1;

    while (window.isOpen())
    {
        elapsedTime = clock.restart();
        getInput(elapsedTime.asSeconds());

        if (frame_counter >= 0.0167f)
        {
            for (auto e : entities)
                e->tick(elapsedTime.asSeconds(), cmap);

            window.clear();
            window.draw(background);
            for (auto e : entities)
                window.draw(e->getSprite());

            window.display();
        }

        fps++;
        frame_counter += elapsedTime.asSeconds();

        if (frame_counter >= 1.0f) {
            std::cout << "fps: " << fps << std::endl;
            frame_counter = 0.;
            fps = 0;
        }
    }

    return 0;
}

void Game::getInput(float elapsedTime)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyReleased)   // If a key is released
        {
            switch (event.key.code)
            {
            case (sf::Keyboard::Up): player.upFlag = false; break;	// if any movement key is released, stop
            case (sf::Keyboard::Down): player.downFlag = false; break;
            case (sf::Keyboard::Left): player.leftFlag = false; break;
            case (sf::Keyboard::Right): player.rightFlag = false; break;
            case (sf::Keyboard::Space): player.aFlag = false; player.aFlagUsed = false; break;
            }
        }

        // If a key is pressed
        if (event.type == sf::Event::KeyPressed)
        {
            player.isMoving = true;

            switch (event.key.code)
            {  
            case (sf::Keyboard::Escape): window.close(); break;   // If escape is pressed, close the application
            case (sf::Keyboard::Down): player.downFlag = true; break; // Process the up, down, left and right keys
            case (sf::Keyboard::Up): player.upFlag = true; break;
            case (sf::Keyboard::Left): player.leftFlag = true; break;
            case (sf::Keyboard::Right): player.rightFlag = true; break;
            case (sf::Keyboard::Space): player.aFlag = true; break;
            }
        }
    }
}