#include "../include/GameMenu.h"
#include <iostream>

GameMenu::GameMenu(int width, int height)
    : visible(false), windowWidth(width), windowHeight(height), font(), restartText(font), quitText(font), gameOverText(font)
{
    initializeFont();
    initializeButtons();
}

void GameMenu::initializeFont()
{
    // Try to load a default system font - if it fails, we'll use SFML built-in
    if (!font.openFromFile("/usr/share/fonts/noto/NotoSans-Regular.ttf")) {
        if (!font.openFromFile("arial.ttf")) {
            cerr << "Warning: Could not load font, text will not display properly" << endl;
        }
    }
}

void GameMenu::initializeButtons()
{
    // Game Over Text
    gameOverText.setString("GAME OVER");
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(60);
    gameOverText.setFillColor(Color::Red);
    gameOverText.setPosition(
        {windowWidth / 2.f - gameOverText.getLocalBounds().size.x / 2.f,
        windowHeight / 4.f}
    );
    
    // Restart Button
    restartButton.setSize({200.f, 60.f});
    restartButton.setFillColor(Color::Green);
    restartButton.setPosition(
        {windowWidth / 2.f - 220.f,
        windowHeight / 2.f + 50.f}
    );
    
    restartText.setString("RESTART");
    restartText.setFont(font);
    restartText.setCharacterSize(30);
    restartText.setFillColor(Color::White);
    restartText.setPosition(
        {restartButton.getPosition().x + 20.f,
        restartButton.getPosition().y + 15.f}
    );
    
    // Quit Button
    quitButton.setSize({200.f, 60.f});
    quitButton.setFillColor(Color::Red);
    quitButton.setPosition(
        {windowWidth / 2.f + 20.f,
        windowHeight / 2.f + 50.f}
    );
    
    quitText.setString("QUIT");
    quitText.setFont(font);
    quitText.setCharacterSize(30);
    quitText.setFillColor(Color::White);
    quitText.setPosition(
        {quitButton.getPosition().x + 50.f,
        quitButton.getPosition().y + 15.f}
    );
}

void GameMenu::render(RenderWindow& window)
{
    if (!visible) return;
    
    // Draw semi-transparent overlay
    RectangleShape overlay(Vector2f(windowWidth, windowHeight));
    overlay.setFillColor(Color(0, 0, 0, 150));
    window.draw(overlay);
    
    // Draw text and buttons
    window.draw(gameOverText);
    window.draw(restartButton);
    window.draw(restartText);
    window.draw(quitButton);
    window.draw(quitText);
}

void GameMenu::handleMouseClick(Vector2f mousePos)
{
    if (!visible) return;
    
    if (isMouseOverButton(mousePos, restartButton)) {
        if (onRestartCallback) {
            onRestartCallback();
        }
    } else if (isMouseOverButton(mousePos, quitButton)) {
        if (onQuitCallback) {
            onQuitCallback();
        }
    }
}

bool GameMenu::isMouseOverButton(Vector2f mousePos, const RectangleShape& button) const
{
    return button.getGlobalBounds().contains(mousePos);
}

void GameMenu::show()
{
    visible = true;
}

void GameMenu::hide()
{
    visible = false;
}

bool GameMenu::isVisible() const
{
    return visible;
}

void GameMenu::setOnRestartCallback(function<void()> callback)
{
    onRestartCallback = callback;
}

void GameMenu::setOnQuitCallback(function<void()> callback)
{
    onQuitCallback = callback;
}
