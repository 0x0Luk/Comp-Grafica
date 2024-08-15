#include <iostream>
#include <stdio.h>
#include <GL\glew.h>
#include <GLFW\glfw3.h>

const GLint WIDTH = 800, HEIGHT = 600;

int main()
{
    glfwInit();
    if (!glfwInit()) {
        printf("Error: O GLFW não iniciou.");
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Computacao Grafica", NULL, NULL);
    if (!window) {
        printf("Error: Janela não aberta.");
        glfwTerminate();
        return 1;
    }

    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(window, &bufferWidth, &bufferHeight);
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        printf("Error: O Glew não iniciou.");
        glfwDestroyWindow(window);
        glfwTerminate();
        return 1;
    }

    glViewport(0, 0, bufferWidth, bufferHeight);
    while (!glfwWindowShouldClose(window)) {
        //Evento
        glfwPollEvents();

        //Cor
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //Janela
        glfwSwapBuffers(window);
    }
}
