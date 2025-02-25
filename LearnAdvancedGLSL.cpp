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
//        else if (nrComponents == 3)
//            format = GL_RGB;
//        else if (nrComponents == 4)
//            format = GL_RGBA;
//
//        glBindTexture(GL_TEXTURE_2D, textureID);
//        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
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
//unsigned int loadCubemap(vector<std::string>faces)
//{
//    unsigned int textureID;
//    glGenTextures(1, &textureID);
//    glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
//
//    int width, height, nrChannels;
//    for (int i = 0;i < 6;i++)
//    {
//        unsigned char* data = stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
//        if (data)
//        {
//            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//            stbi_image_free(data);
//        }
//    }
//    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
//    return textureID;
//}
//
//int main()
//{
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//#ifdef __APPLE__
//    glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GL_TRUE);
//#endif
//    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Learn advanced GLSL", nullptr, nullptr);
//    if (window == nullptr)
//    {
//        std::cout << "ERROR::Failed to create a window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//    glfwSetCursorPosCallback(window, mouse_callback);
//    glfwSetScrollCallback(window, scroll_callback);
//
//    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "ERROR::Failed to initilize GLAD" << std::endl;
//        return -1;
//    }
//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_PROGRAM_POINT_SIZE);
//
//    Shader shader("E:\\vstudioproject\\LearnOpenGL\\LearnOpenGL\\vertexShaderSource_advanvedGLSL.GLSL", "E:\\vstudioproject\\LearnOpenGL\\LearnOpenGL\\fragmentShaderSource_advancedGLSL.GLSL");
//
//    float vertices[] = {
//                // positions          // texture Coords
//                -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//                 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//                 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//                 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//                -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//                -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//        
//                -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//                 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//                 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//                 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//                -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//                -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//        
//                -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//                -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//                -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//                -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//                -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//                -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//        
//                 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//                 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//                 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//                 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//                 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//                 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//        
//                -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//                 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//                 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//                 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//                -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//                -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//        
//                -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//                 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//                 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//                 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//                -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//                -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//            };
//
//
//    unsigned int VBO, VAO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//
//    
//    unsigned int frontTexture = loadTexture("F:/OpenGLImage/container.jpg");
//
//    unsigned int backTexture = loadTexture("F:/OpenGLImage/iroccontainer.png");
//
//
//    shader.use();
//    shader.setInt("frontTexture", 0);
//    shader.setInt("backTexture", 1);
//
//    while (!glfwWindowShouldClose(window))
//    {
//        float currentFrame = static_cast<float>(glfwGetTime());
//
//        deltaTime = currentFrame - lastFrame;
//
//        lastFrame = currentFrame;
//        processInput(window);
//
//
//        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//
//        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
//
//        shader.use();
//
//        glm::mat4 model(1.0f);
//        glm::mat4 view = camera.GetViewMatrix();
//        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
//        shader.setMat4("model", model);
//        shader.setMat4("view", view);
//        shader.setMat4("projection", projection);
//
//        glBindVertexArray(VAO);
//        glActiveTexture(GL_TEXTURE0);
//
//        glBindTexture(GL_TEXTURE_2D, frontTexture);
//        glActiveTexture(GL_TEXTURE1);
//        glBindTexture(GL_TEXTURE_2D, backTexture);
//
//       // glDrawArrays(GL_POINTS, 0, 36);
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//    glDeleteVertexArrays(1,&VAO);
//    glDeleteBuffers(1,&VBO);
//    glfwTerminate();
//    return 0;
//}