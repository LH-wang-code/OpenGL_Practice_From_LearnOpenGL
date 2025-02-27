//#define STB_IMAGE_IMPLEMENTATION
//#include<iostream>
//#include<glad/glad.h>
//#include<GLFW/glfw3.h>
//
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include "shader.h"
//#include "camera.h"
//#include "model.h"
//
//
//
//#include <assimp/Importer.hpp>
//#include <assimp/scene.h>
//#include <assimp/postprocess.h>
//
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//const int WIDTH = 800;
//const int HEIGHT = 600;
//bool firstMouse = true;
//float lastX = WIDTH / 2.0f;
//float lastY = HEIGHT / 2.0f;
//
//glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
//
//
//float deltaTime = 0.0f;
//float lastFrame = 0.0f;
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    glViewport(0, 0, width, height);
//}
//
//int main()
//{
//    glfwInit();
//
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//#ifdef __APPLE__
//    glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GL_TRUE);
//#endif
//
//    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Learn Instancing", nullptr, nullptr);
//    if (window == nullptr)
//    {
//        std::cout << "ERROR::Failed to create a window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//
//    glfwMakeContextCurrent(window);
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "ERROR::Failed to initilize GLAD" << std::endl;
//        return -1;
//    }
//    glEnable(GL_DEPTH_TEST);
//
//
//
//    Shader shader("E:\\vstudioproject\\LearnOpenGL\\LearnOpenGL\\vertexShaderSource_instancing.GLSL", "E:\\vstudioproject\\LearnOpenGL\\LearnOpenGL\\fragmentShaderSource_instancing.GLSL");
//
//
//    glm::vec2 translations[100];
//    int index = 0;
//    float offset = 0.1f;
//    for (int y = -10;y < 10;y += 2)
//    {
//        for (int x = -10;x < 10;x += 2)
//        {
//            glm::vec2 translation;
//            translation.x = (float)x / 10.0f + offset;
//            translation.y = (float)y / 10.0f + offset;
//            translations[index++] = translation;
//        }
//    }
//
//
//    unsigned int instanceVBO;
//    glGenBuffers(1, &instanceVBO);
//    glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
//   glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * 100, &translations[0], GL_STATIC_DRAW);
//    
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//    float quadVertices[] = {
//        // positions     // colors
//        -0.05f,  0.05f,  1.0f, 0.0f, 0.0f,
//         0.05f, -0.05f,  0.0f, 1.0f, 0.0f,
//        -0.05f, -0.05f,  0.0f, 0.0f, 1.0f,
//
//        -0.05f,  0.05f,  1.0f, 0.0f, 0.0f,
//         0.05f, -0.05f,  0.0f, 1.0f, 0.0f,
//         0.05f,  0.05f,  0.0f, 1.0f, 1.0f
//    };
//
//    unsigned int quadVAO, quadVBO;
//    glGenVertexArrays(1, &quadVAO);
//    glGenBuffers(1, &quadVBO);
//    glBindVertexArray(quadVAO);
//    glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
//
//    glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices, GL_STATIC_DRAW);
//
//    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2*sizeof(float)));
//    glEnableVertexAttribArray(1);
//
//    glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
//    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(2);
//
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//    glVertexAttribDivisor(2, 1);//何时更新顶点属性 到新的一组
//
//
//    while (!glfwWindowShouldClose(window))
//    {
//        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//
//        shader.use();
//        glBindVertexArray(quadVAO);
//
//        glDrawArraysInstanced(GL_TRIANGLES, 0, 6, 100);
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//    glDeleteVertexArrays(1, &quadVAO);
//    glDeleteBuffers(1, &quadVBO);
//
//
//    return 0;
//}