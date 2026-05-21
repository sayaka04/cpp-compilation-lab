#include <GLFW/glfw3.h>
#include "game.h"

// Player position
float x = 0.0f;
float y = 0.0f;

// Drawing a simple square
void drawSquare(float x, float y)
{
    glBegin(GL_QUADS);
    glVertex2f(x - 0.05f, y - 0.05f);
    glVertex2f(x + 0.05f, y - 0.05f);
    glVertex2f(x + 0.05f, y + 0.05f);
    glVertex2f(x - 0.05f, y + 0.05f);
    glEnd();
}

void Game::run()
{
    if (!glfwInit())
        return;

    // FULLSCREEN WINDOW (1920x1080)
    GLFWwindow *window = glfwCreateWindow(
        1920, 1080,
        "GLFW Game Foundation Demo",
        glfwGetPrimaryMonitor(),
        NULL);

    if (!window)
    {
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    // 2D coordinate system (-1 to 1)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);

    float lastTime = glfwGetTime();

    while (!glfwWindowShouldClose(window))
    {
        // ===== TIME (DELTA TIME) =====
        float currentTime = glfwGetTime();
        float deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        float speed = 2.0f;

        // ===== INPUT + MOVEMENT =====
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            y += speed * deltaTime;

        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            y -= speed * deltaTime;

        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            x -= speed * deltaTime;

        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            x += speed * deltaTime;

        // ===== RENDER =====
        glClear(GL_COLOR_BUFFER_BIT);

        drawSquare(x, y);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}