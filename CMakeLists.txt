cmake_minimum_required(VERSION 3.10)
project(Snake3D)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 COMPONENTS System Window Graphics REQUIRED)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

add_executable(Snake3D
    src/main.cpp
    src/CubeRenderer.cpp
    src/GameMenu.cpp
    src/GameState.cpp
    src/ScoreDisplay.cpp
    src/control/CommandRegistry.cpp
    src/control/InputHandler.cpp
    src/matrix/RotationMatrixX.cpp
    src/matrix/RotationMatrixY.cpp
    src/logic/snake/Snake.cpp
    src/logic/snake/SnakeMovement.cpp
    src/logic/snake/SnakeCollision.cpp
    src/logic/snake/SnakeController.cpp
)

target_link_libraries(Snake3D
    SFML::Graphics
    SFML::Window
    SFML::System
)
