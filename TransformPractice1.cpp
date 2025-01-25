//#define STB_IMAGE_IMPLEMENTATION
//#include<iostream>
//#include<glad/glad.h>
//#include<GLFW/glfw3.h>
//#include "shader.h"
//#include "stb_image.h"
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//
//
//void Framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//
//}
//
//
//void processInput(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GL_TRUE);
//
//}
//
//int main()
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//#ifdef __APPLE__
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif
//
//
//	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnTransfrom", nullptr, nullptr);
//	if (window == nullptr)
//	{
//		std::cout << "ERROR::Failed to create a window" << std::endl;
//		glfwTerminate();
//		return -1;
//
//	}
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, Framebuffer_size_callback);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "ERROR::Failed to initilize GLAD" << std::endl;
//		return -1;
//	}
//
//	Shader ourShader("E:/vstudioproject/LearnOpenGL/LearnOpenGL/vertexShaderSource_Transform1.GLSL", "E:/vstudioproject/LearnOpenGL/LearnOpenGL/fragmentShaderSource_Transform1.GLSL");
//	float vertices[] = {
//		 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
//		 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
//		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
//		-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
//	};
//	unsigned int indices[] = {
//		0,1,3,
//		1,2,3
//	};
//
//
//
//	unsigned int VBO, VAO, EBO;
//	glGenBuffers(1, &VBO);
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &EBO);
//	glBindVertexArray(VAO);
//
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//
//
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//
//
//	unsigned int texture1, texture2;
//
//	glGenTextures(1, &texture1);
//	glBindTexture(GL_TEXTURE_2D, texture1);
//
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//
//	int width, height, nrChannels;
//	stbi_set_flip_vertically_on_load(true);
//	unsigned char* data = stbi_load("F:/OpenGLImage/container.jpg", &width, &height, &nrChannels, 0);
//	if (data)
//	{
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//
//	}
//	else
//	{
//		std::cout << "ERROR::Failed to load texture" << std::endl;
//	}
//
//	stbi_image_free(data);
//
//
//
//	glGenTextures(1, &texture2);
//	glBindTexture(GL_TEXTURE_2D, texture2);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//
//	data = stbi_load("F:/OpenGLImage/awesomeface.png", &width, &height, &nrChannels, 0);
//	if (data)
//	{
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//
//	}
//	else
//	{
//		std::cout << "ERROR::Failed to load texture:awesomeface.png" << std::endl;
//	}
//
//	stbi_image_free(data);
//	ourShader.use();
//	ourShader.setInt("texture1", 0);
//	ourShader.setInt("texture2", 1);
//
//
//
//	while (!glfwWindowShouldClose(window))
//	{
//		processInput(window);
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, texture1);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, texture2);
//
//		glm::mat4 transform = glm::mat4(1.0f);
//		//transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));
//		transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
//		transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));
//		//效果：箱子会围绕着原来的旋转中心在旋转而不是箱子中心
//		//分析：旋转是按照当前的物体坐标来确定旋转轴的，当前旋转时，在原地先旋转，然后在平移，而先平移再旋转，他的旋转轴跟着平移，所以会在右下角原地旋转
//		//analysis:"rotate" determines axis based on the object's coordinates,while "translate"  change the coordinates of axis
//
//
//		ourShader.use();
//		unsigned int transformL = glGetUniformLocation(ourShader.ID, "transform");
//		glUniformMatrix4fv(transformL, 1, GL_FALSE, glm::value_ptr(transform));
//		glBindVertexArray(VAO);
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//
//
//	}
//
//
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glDeleteBuffers(1, &EBO);
//
//	glfwTerminate();
//
//	return 0;
//}