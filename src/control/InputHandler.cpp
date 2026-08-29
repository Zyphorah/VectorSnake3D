#include "../../include/control/InputHandler.h"

InputHandler::InputHandler(CommandRegistry& commandRegistry, RenderWindow& renderWindow)
    : registry(commandRegistry), window(renderWindow)
{
}

void InputHandler::handleInput()
{
    while (const std::optional<Event> event = window.pollEvent())
    {
        if (event->is<Event::Closed>())
        {
            window.close();
        }
        else if (const auto* keyPressed = event->getIf<Event::KeyPressed>())
        {
            registry.executePressedCommand(keyPressed->code);
        }
        else if (const auto* keyReleased = event->getIf<Event::KeyReleased>())
        {
            registry.executeReleasedCommand(keyReleased->code);
        }
    }
}

CommandRegistry& InputHandler::getRegistry()
{
    return registry;
}
