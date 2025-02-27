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
//#include <assimp/Importer.hpp>
//#include <assimp/scene.h>
//#include <assimp/postprocess.h>
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    glViewport(0, 0, width, height);
//}
//int WIDTH = 800;
//int HEIGHT = 600;
//int main()
//{
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
//#ifdef __APPLE__
//    glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GL_TRUE);
//#endif
//    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "learn geometry shader", nullptr, nullptr);
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
//    float points[] = {
//    -0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 
//     0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 
//     0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 
//    -0.5f, -0.5f, 1.0f, 1.0f, 0.0f  
//    };
//
//    unsigned int VBO, VAO;
//
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//
//
//
//
//
//    Shader shader("E:\\vstudioproject\\LearnOpenGL\\LearnOpenGL\\vertexShaderSource_geo.GLSL","E:\\vstudioproject\\LearnOpenGL\\LearnOpenGL\\fragmentShaderSource_geo.GLSL","E:\\vstudioproject\\LearnOpenGL\\LearnOpenGL\\geometeryShaderSource_geo.GLSL");
//    
//    while (!glfwWindowShouldClose(window))
//    {
//        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        shader.use();
//        glBindVertexArray(VAO);
//        glDrawArrays(GL_POINTS, 0, 4);
//
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//
//    }
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO);
//
//    glfwTerminate();
//
//    return 0;
//}
