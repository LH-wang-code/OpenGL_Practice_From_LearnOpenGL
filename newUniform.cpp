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
//
//    float cubeVertices[] = {
//        // positions         
//        -0.5f, -0.5f, -0.5f,
//         0.5f, -0.5f, -0.5f,
//         0.5f,  0.5f, -0.5f,
//         0.5f,  0.5f, -0.5f,
//        -0.5f,  0.5f, -0.5f,
//        -0.5f, -0.5f, -0.5f,
//
//        -0.5f, -0.5f,  0.5f,
//         0.5f, -0.5f,  0.5f,
//         0.5f,  0.5f,  0.5f,
//         0.5f,  0.5f,  0.5f,
//        -0.5f,  0.5f,  0.5f,
//        -0.5f, -0.5f,  0.5f,
//
//        -0.5f,  0.5f,  0.5f,
//        -0.5f,  0.5f, -0.5f,
//        -0.5f, -0.5f, -0.5f,
//        -0.5f, -0.5f, -0.5f,
//        -0.5f, -0.5f,  0.5f,
//        -0.5f,  0.5f,  0.5f,
//
//         0.5f,  0.5f,  0.5f,
//         0.5f,  0.5f, -0.5f,
//         0.5f, -0.5f, -0.5f,
//         0.5f, -0.5f, -0.5f,
//         0.5f, -0.5f,  0.5f,
//         0.5f,  0.5f,  0.5f,
//
//        -0.5f, -0.5f, -0.5f,
//         0.5f, -0.5f, -0.5f,
//         0.5f, -0.5f,  0.5f,
//         0.5f, -0.5f,  0.5f,
//        -0.5f, -0.5f,  0.5f,
//        -0.5f, -0.5f, -0.5f,
//
//        -0.5f,  0.5f, -0.5f,
//         0.5f,  0.5f, -0.5f,
//         0.5f,  0.5f,  0.5f,
//         0.5f,  0.5f,  0.5f,
//        -0.5f,  0.5f,  0.5f,
//        -0.5f,  0.5f, -0.5f,
//    };
//
//    unsigned int cubeVAO, cubeVBO;
//    glGenVertexArrays(1, &cubeVAO);
//    glGenBuffers(1, &cubeVBO);
//    glBindVertexArray(cubeVAO);
//    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), &cubeVertices, GL_STATIC_DRAW);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//
//
//
//    Shader shaderRed("E:\\vstudioproject\\LearnOpenGL\\LearnOpenGL\\vertexShaderSource_advance1.GLSL", "E:\\vstudioproject\\LearnOpenGL\\LearnOpenGL\\fragmentShaderSource_advanceRed.GLSL");
//    Shader shaderGreen("E:\\vstudioproject\\LearnOpenGL\\LearnOpenGL\\vertexShaderSource_advance2.GLSL", "E:\\vstudioproject\\LearnOpenGL\\LearnOpenGL\\fragmentShaderSource_advanceGreen.GLSL");
//    Shader shaderBlue("E:\\vstudioproject\\LearnOpenGL\\LearnOpenGL\\vertexShaderSource_advance3.GLSL", "E:\\vstudioproject\\LearnOpenGL\\LearnOpenGL\\fragmentShaderSource_advanceBlue.GLSL");
//    Shader shaderYellow("E:\\vstudioproject\\LearnOpenGL\\LearnOpenGL\\vertexShaderSource_advance4.GLSL", "E:\\vstudioproject\\LearnOpenGL\\LearnOpenGL\\fragmentShaderSource_advanceYellow.GLSL");
//
//    
//    unsigned int uniformBlockIndexRed = glGetUniformBlockIndex(shaderRed.ID, "Materices");
//    unsigned int uniformBlockIndexGreen = glGetUniformBlockIndex(shaderGreen.ID, "Materices");
//    unsigned int uniformBlockIndexBlue = glGetUniformBlockIndex(shaderBlue.ID, "Materices");
//    unsigned int uniformBlockIndexYellow = glGetUniformBlockIndex(shaderYellow.ID, "Materices");
//
//
//    glUniformBlockBinding(shaderRed.ID, uniformBlockIndexRed, 0);
//    glUniformBlockBinding(shaderGreen.ID, uniformBlockIndexGreen, 0);
//    glUniformBlockBinding(shaderBlue.ID, uniformBlockIndexBlue, 0);
//    glUniformBlockBinding(shaderYellow.ID, uniformBlockIndexYellow, 0);
//
//
//
//    unsigned int Materials;
//    glGenBuffers(1, &Materials);
//
//    glBindBuffer(GL_UNIFORM_BUFFER, Materials);
//    glBufferData(GL_UNIFORM_BUFFER, 2 * sizeof(glm::mat4), nullptr, GL_STATIC_DRAW);
//    glBindBuffer(GL_UNIFORM_BUFFER, 0);
//
//    glBindBufferRange(GL_UNIFORM_BUFFER, 0, Materials, 0, 2 * sizeof(glm::mat4));
//
//    glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
//    glBindBuffer(GL_UNIFORM_BUFFER, Materials);
//    glBufferSubData(GL_UNIFORM_BUFFER, 0,sizeof(glm::mat4), glm::value_ptr(projection));
//    glBindBuffer(GL_UNIFORM_BUFFER, 0);
//
//
//    while (!glfwWindowShouldClose(window))
//    {
//
//        float currentFrame = static_cast<float>(glfwGetTime());
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//
//        processInput(window);
//
//        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        glm::mat4 view = camera.GetViewMatrix(); 
//
//        glBindBuffer(GL_UNIFORM_BUFFER, Materials);
//        glBufferSubData(GL_UNIFORM_BUFFER, sizeof(glm::mat4),sizeof(glm::mat4), glm::value_ptr(view));
//        glBindBuffer(GL_UNIFORM_BUFFER, 0);
//
//
//        glBindVertexArray(cubeVAO);
//
//        shaderRed.use();
//        glm::mat4 model(1.0f);
//        model = glm::translate(model, glm::vec3(-0.75f, 0.75f, 0.0f));
//        shaderRed.setMat4("model", model);
//
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//
//        shaderGreen.use();
//        model = glm::mat4(1.0f);
//        model = glm::translate(model, glm::vec3(0.75f, 0.75f, 0.0f));
//        shaderGreen.setMat4("model", model);
//
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//
//
//        shaderYellow.use();
//        model = glm::mat4(1.0f);
//
//        model = glm::translate(model, glm::vec3(-0.75f, -0.75f, 0.0f));
//        shaderYellow.setMat4("model", model);
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//
//
//        shaderBlue.use();
//        model = glm::mat4(1.0f);
//
//        model = glm::translate(model, glm::vec3(0.75f, -0.75f, 0.0f));
//        shaderBlue.setMat4("model", model);
//
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//
//
//
//       
//
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//
//    glDeleteVertexArrays(1, &cubeVAO);
//    glDeleteBuffers(1, &cubeVBO);
//    glfwTerminate();
//    return 0;
//}