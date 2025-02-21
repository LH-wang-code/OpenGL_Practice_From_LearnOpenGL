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
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//
//int WIDTH = 800;
//int HEIGHT = 600;
//
//
//bool firstMouse = true;
//float lastX = WIDTH / 2.0f;
//float lastY = HEIGHT / 2.0f;
//
//float deltaTime = 0.0f;
//float lastFrame = 0.0f;
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    glViewport(0, 0, width, height);
//
//}void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
//{
//    float xpos = static_cast<float>(xposIn);
//    float ypos = static_cast<float>(yposIn);
//    if (firstMouse)
//    {
//        lastX = xpos;
//        lastY = ypos;
//        firstMouse = false;
//    }
//    float xoffset = xpos - lastX;
//    float yoffset = lastY - ypos;
//    lastX = xpos;
//    lastY = ypos;
//    camera.ProcessMouseMovement(xoffset, yoffset);
//}
//
//void processInput(GLFWwindow* window)
//{
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//        camera.ProcessKeyboard(FORWARD, deltaTime);
//    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//        camera.ProcessKeyboard(BACKWARD, deltaTime);
//    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//        camera.ProcessKeyboard(LEFT, deltaTime);
//    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//        camera.ProcessKeyboard(RIGHT, deltaTime);
//
//}
//
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//    camera.ProcessMouseScroll(static_cast<float>(yoffset));
//}
//
//unsigned int loadTexture(char const* path)
//{
//    unsigned int textureID;
//    glGenTextures(1, &textureID);
//
//    int width, height, nrComponents;
//    unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
//    if (data)
//    {
//        GLenum format;
//        if (nrComponents == 1)
//            format = GL_RED;
//        if (nrComponents == 3)
//            format = GL_RGB;
//        if (nrComponents == 4)
//            format = GL_RGBA;
//        glBindTexture(GL_TEXTURE_2D, textureID);
//        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, format == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, format == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//        stbi_image_free(data);
//    }
//    else
//    {
//        std::cout << "Texture failed to load path :" << path << std::endl;
//
//        stbi_image_free(data);
//    }
//    return textureID;
//}
//
//
//int main()
//{
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//#ifdef __APPLE__
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif
//    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Learn Face Culling", nullptr, nullptr);
//    if (window == nullptr)
//    {
//        std::cout << "ERROR::Failed to create a window" << std::endl;
//        glfwTerminate();
//        return -1;
//
//    }
//    glfwMakeContextCurrent(window);
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//    glfwSetCursorPosCallback(window, mouse_callback);
//    glfwSetScrollCallback(window, scroll_callback);
//    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout<<"ERROR::Failed to initilize GLAD" << std::endl;
//        return -1;
//    }
//    glEnable(GL_DEPTH_TEST);
//
//
//    glEnable(GL_CULL_FACE);
//   
//    glCullFace(GL_BACK);
//   // glCullFace(GL_FRONT);
//    glFrontFace(GL_CW);
//
//
//    float cubeVertices[] = {
//        // Back face
//        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, // Bottom-left
//         0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right
//         0.5f, -0.5f, -0.5f,  1.0f, 0.0f, // bottom-right         
//         0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right
//        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, // bottom-left
//        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, // top-left
//        // Front face
//        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-left
//         0.5f, -0.5f,  0.5f,  1.0f, 0.0f, // bottom-right
//         0.5f,  0.5f,  0.5f,  1.0f, 1.0f, // top-right
//         0.5f,  0.5f,  0.5f,  1.0f, 1.0f, // top-right
//        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, // top-left
//        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-left
//        // Left face
//        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-right
//        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-left
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-left
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-left
//        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-right
//        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-right
//        // Right face
//         0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-left
//         0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-right
//         0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right         
//         0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-right
//         0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-left
//         0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-left     
//         // Bottom face
//         -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // top-right
//          0.5f, -0.5f, -0.5f,  1.0f, 1.0f, // top-left
//          0.5f, -0.5f,  0.5f,  1.0f, 0.0f, // bottom-left
//          0.5f, -0.5f,  0.5f,  1.0f, 0.0f, // bottom-left
//         -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-right
//         -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // top-right
//         // Top face
//         -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, // top-left
//          0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // bottom-right
//          0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right     
//          0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // bottom-right
//         -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, // top-left
//         -0.5f,  0.5f,  0.5f,  0.0f, 0.0f  // bottom-left        
//    };
//
//
//    unsigned int VAO, VBO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//
//
//    Shader shader("E:\\vstudioproject\\LearnOpenGL\\LearnOpenGL\\vertexShaderSource_facebulling.GLSL", "E:\\vstudioproject\\LearnOpenGL\\LearnOpenGL\\fragmentShaderSource_faceculling.GLSL");
//
//    unsigned int textureID = loadTexture("F:/OpenGLImage/container.jpg");
//
//    shader.use();
//    shader.setInt("texture1", 0);
//
//    while (!glfwWindowShouldClose(window))
//    {
//        float currentFrame = static_cast<float>(glfwGetTime());
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//        
//        processInput(window);
//        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        shader.use();
//
//        glm::mat4 model(1.0f);
//        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
//        glm::mat4 view = camera.GetViewMatrix();
//
//        shader.setMat4("model", model);
//        shader.setMat4("projection", projection);
//        shader.setMat4("view", view);
//
//        glBindVertexArray(VAO);
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D, textureID);
//
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//
//
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//
//    }
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO);
//    glfwTerminate();
//
//
//    return 0;
//}