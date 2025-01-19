//#include<iostream>
//#include<glad/glad.h>
//#include<GLFW/glfw3.h>
//#include "shader.h"
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//    {
//        glfwSetWindowShouldClose(window, GL_TRUE);
//    }
//}
//int main()
//{
//	glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//
//    GLFWwindow* window = glfwCreateWindow(800, 600, "UserShader", nullptr, nullptr);
//    if (window == nullptr)
//    {
//        std::cout << "Failed to create a window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//    glfwSetKeyCallback(window, key_callback);
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "ERROR:failed to initilize GLAD" << std::endl;
//		return -1;
//
//	}
//    int width, height;
//    glfwGetFramebufferSize(window, &width, &height);
//    glViewport(0, 0, width, height);
//    Shader ourShader(R"(E:\vstudioproject\LearnOpenGL\LearnOpenGL\vertexShaderSource.GLSL)", R"(E:\vstudioproject\LearnOpenGL\LearnOpenGL\fragmentShaderSource.GLSL)");
//    //这里文件路径是绝对路径，注意使用转义字符或者反斜杠，或者R()将字符串转化从而能正确读取文件路径
//
//    
//    GLfloat vertices[] = {
//	 0.5f, -0.5f, 0.0f,1.0f,0.0f,0.0f,
//	-0.5f, -0.5f, 0.0f,0.0f,1.0f,0.0f,
//	 0.0f,  0.5f, 0.0f,0.0f,0.0f,1.0f
//	 };
//    unsigned int VBO, VAO;
//    glGenBuffers(1, &VBO);
//    glGenVertexArrays(1, &VAO);
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//    while (!glfwWindowShouldClose(window))
//    {
//        glfwPollEvents();
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//        ourShader.use();
//        glBindVertexArray(VAO);
//        glDrawArrays(GL_TRIANGLES, 0, 3);
//        glfwSwapBuffers(window);
//        
//    }
//    glDeleteBuffers(1, &VBO);
//    glDeleteVertexArrays(1, &VAO);
//
//    glfwTerminate();
//     return 0;
//}
//
