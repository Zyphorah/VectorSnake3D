#include "../../../include/logic/snake/SnakeController.h"

SnakeController::SnakeController(Snake& snakeRef, sf::RenderWindow& window, Vector3f& pivotRef, Vector3f& dirPivotRef)
    : snake(snakeRef), inputHandler(registry, window), pivotPointAxe(pivotRef), directionPivot(dirPivotRef)
{
    setupControls();
}

void SnakeController::handleInput()
{
    inputHandler.handleInput();
}

void SnakeController::setupControls()
{
    // Touches de rotation avec flèches
    registry.injectCommand(
        Keyboard::Key::Up,
        [this]() {
            pivotPointAxe.x = -1;
            directionPivot.x = -1;
        }
    );
    registry.injectReleasedCommand(
        Keyboard::Key::Up,
        [this]() {
            pivotPointAxe.x = 0;
        }
    );
    
    registry.injectCommand(
        Keyboard::Key::Down,
        [this]() {
            pivotPointAxe.x = 1;
            directionPivot.x = 1;
        }
    );
    registry.injectReleasedCommand(
        Keyboard::Key::Down,
        [this]() {
            pivotPointAxe.x = 0;
        }
    );
    
    registry.injectCommand(
        Keyboard::Key::Left,
        [this]() {
            pivotPointAxe.y = -1;
            directionPivot.y = -1;
        }
    );
    registry.injectReleasedCommand(
        Keyboard::Key::Left,
        [this]() {
            pivotPointAxe.y = 0;
        }
    );
    
    registry.injectCommand(
        Keyboard::Key::Right,
        [this]() {
            pivotPointAxe.y = 1;
            directionPivot.y = 1;
        }
    );
    registry.injectReleasedCommand(
        Keyboard::Key::Right,
        [this]() {
            pivotPointAxe.y = 0;
        }
    );
    
    // Touches de mouvement du serpent
    // Note: Using getDirectionRef() to modify direction directly, matching original logic
    
    registry.injectCommand(
        Keyboard::Key::A,
        [this]() {
            snake.getDirectionRef() = Vector3f(-20, 0, 0);
        }
    );
    
    registry.injectCommand(
        Keyboard::Key::D,
        [this]() {
            snake.getDirectionRef() = Vector3f(20, 0, 0);
        }
    );
    
    registry.injectCommand(
        Keyboard::Key::W,
        [this]() {
            snake.getDirectionRef() = Vector3f(0, 0, -20);
        }
    );
    
    registry.injectCommand(
        Keyboard::Key::S,
        [this]() {
            snake.getDirectionRef() = Vector3f(0, 0, 20);
        }
    );
    
    registry.injectCommand(
        Keyboard::Key::E,
        [this]() {
            snake.getDirectionRef() = Vector3f(0, 10, 0);
        }
    );
    
    registry.injectCommand(
        Keyboard::Key::Q,
        [this]() {
            snake.getDirectionRef() = Vector3f(0, -10, 0);
        }
    );
}
