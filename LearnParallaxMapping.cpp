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
//GLuint quadVAO = 0;
//GLuint quadVBO;
//void RenderQuad()
//{
//    if (quadVAO == 0)
//    {
//
//        glm::vec3 pos1(-1.0, 1.0, 0.0);
//        glm::vec3 pos2(-1.0, -1.0, 0.0);
//        glm::vec3 pos3(1.0, -1.0, 0.0);
//        glm::vec3 pos4(1.0, 1.0, 0.0);
//
//        glm::vec2 uv1(0.0, 1.0);
//        glm::vec2 uv2(0.0, 0.0);
//        glm::vec2 uv3(1.0, 0.0);
//        glm::vec2 uv4(1.0, 1.0);
//
//        glm::vec3 nm(0.0, 0.0, 1.0);
//
//
//        glm::vec3 tangent1, bitangent1;
//        glm::vec3 tangent2, bitangent2;
//
//        glm::vec3 edge1 = pos2 - pos1;
//        glm::vec3 edge2 = pos3 - pos1;
//        glm::vec2 deltaUV1 = uv2 - uv1;
//        glm::vec2 deltaUV2 = uv3 - uv1;
//
//        GLfloat f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);
//
//        tangent1.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
//        tangent1.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
//        tangent1.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);
//        tangent1 = glm::normalize(tangent1);
//
//        bitangent1.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
//        bitangent1.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
//        bitangent1.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);
//        bitangent1 = glm::normalize(bitangent1);
//
//
//        edge1 = pos3 - pos1;
//        edge2 = pos4 - pos1;
//        deltaUV1 = uv3 - uv1;
//        deltaUV2 = uv4 - uv1;
//
//        f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);
//
//        tangent2.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
//        tangent2.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
//        tangent2.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);
//        tangent2 = glm::normalize(tangent2);
//
//
//        bitangent2.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
//        bitangent2.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
//        bitangent2.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);
//        bitangent2 = glm::normalize(bitangent2);
//
//
//        GLfloat quadVertices[] = {
//
//            pos1.x, pos1.y, pos1.z, nm.x, nm.y, nm.z, uv1.x, uv1.y, tangent1.x, tangent1.y, tangent1.z, bitangent1.x, bitangent1.y, bitangent1.z,
//            pos2.x, pos2.y, pos2.z, nm.x, nm.y, nm.z, uv2.x, uv2.y, tangent1.x, tangent1.y, tangent1.z, bitangent1.x, bitangent1.y, bitangent1.z,
//            pos3.x, pos3.y, pos3.z, nm.x, nm.y, nm.z, uv3.x, uv3.y, tangent1.x, tangent1.y, tangent1.z, bitangent1.x, bitangent1.y, bitangent1.z,
//
//            pos1.x, pos1.y, pos1.z, nm.x, nm.y, nm.z, uv1.x, uv1.y, tangent2.x, tangent2.y, tangent2.z, bitangent2.x, bitangent2.y, bitangent2.z,
//            pos3.x, pos3.y, pos3.z, nm.x, nm.y, nm.z, uv3.x, uv3.y, tangent2.x, tangent2.y, tangent2.z, bitangent2.x, bitangent2.y, bitangent2.z,
//            pos4.x, pos4.y, pos4.z, nm.x, nm.y, nm.z, uv4.x, uv4.y, tangent2.x, tangent2.y, tangent2.z, bitangent2.x, bitangent2.y, bitangent2.z
//        };
//
//        glGenVertexArrays(1, &quadVAO);
//        glGenBuffers(1, &quadVBO);
//        glBindVertexArray(quadVAO);
//        glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
//        glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
//        glEnableVertexAttribArray(0);
//        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(GLfloat), (GLvoid*)0);
//        glEnableVertexAttribArray(1);
//        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//        glEnableVertexAttribArray(2);
//        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 14 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
//        glEnableVertexAttribArray(3);
//        glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(GLfloat), (GLvoid*)(8 * sizeof(GLfloat)));
//        glEnableVertexAttribArray(4);
//        glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(GLfloat), (GLvoid*)(11 * sizeof(GLfloat)));
//    }
//    glBindVertexArray(quadVAO);
//    glDrawArrays(GL_TRIANGLES, 0, 6);
//    glBindVertexArray(0);
//}
//int main()
//{
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//#ifdef __APPLE__
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif
//
//    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "learnopengl", nullptr, nullptr);
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
//
//    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "ERROR::Failed to initilize GLAD" << std::endl;
//        return -1;
//    }
//
//    glEnable(GL_DEPTH_TEST);
//
//    Shader shader("E:\\vstudioproject\\LearnOpenGL\\LearnOpenGL\\vertexShaderSource_normalmapping.GLSL", "E:\\vstudioproject\\LearnOpenGL\\LearnOpenGL\\fragmentShaderSource_normalmapping.GLSL");
//
//    unsigned int diffuseMap = loadTexture("F:/OpenGLImage/bricks2.jpg");
//    unsigned int normalMap = loadTexture("F:/OpenGLImage/bricks2_normal.jpg");
//    unsigned int dispMap = loadTexture("F:/OpenGLImage/bricks2_disp.jpg");
//     
//
//
//
//    shader.use();
//
//    shader.setInt("diffuseMap", 0);
//    shader.setInt("normalMap", 1);
//    shader.setInt("dispMap", 2);
//
//    glm::vec3 lightPos(0.5f, 1.0f, 0.3f);
//
//    while (!glfwWindowShouldClose(window))
//    {
//        float currentFrame = static_cast<float>(glfwGetTime());
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//
//        processInput(window);
//        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        shader.use();
//        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
//
//        glm::mat4 view = camera.GetViewMatrix();
//
//        shader.setMat4("projection", projection);
//        shader.setMat4("view", view);
//
//
//        glm::mat4 model = glm::mat4(1.0f);
//        // model = glm::rotate(model, (float)glfwGetTime() * -10, glm::normalize(glm::vec3(1.0f, 0.0f, 1.0f)));
//        shader.setMat4("model", model);
//
//
//        shader.setVec3("lightPos", lightPos);
//        shader.setVec3("viewPos", camera.Position);
//
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D, diffuseMap);
//        glActiveTexture(GL_TEXTURE1);
//        glBindTexture(GL_TEXTURE_2D, normalMap);
//
//        RenderQuad();
//
//
//        model = glm::mat4();
//        model = glm::translate(model, lightPos);
//        model = glm::scale(model, glm::vec3(0.1f));
//        shader.setMat4("model", model);
//        RenderQuad();
//
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    glfwTerminate();
//
//
//    return 0;
//}