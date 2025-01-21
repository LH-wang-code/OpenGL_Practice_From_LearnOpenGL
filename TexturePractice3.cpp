//#define STB_IMAGE_IMPLEMENTATION
//
//#include<glad/glad.h>
//#include<GLFW/glfw3.h>
//#include "stb_image.h"
//#include "shader.h"
//#include<iostream>
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0,0,width,height);
//}
//void processInput(GLFWwindow *window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//	{
//		glfwSetWindowShouldClose(window, GL_TRUE);
//
//	}
//}
//
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
//	//std::cout << 1111 << std::endl;
//	GLFWwindow* window = glfwCreateWindow(800, 600, "Texture Practice 3", nullptr, nullptr);
//	if (window == nullptr)
//	{
//		std::cout << "ERROR:Failed to create a window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "ERROR::Failed to initilize GLAD" << std::endl;
//		return -1;
//	}
//	//while (!glfwWindowShouldClose(window))
//	//{
//	//	processInput(window);
//	//	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//	//	glClear(GL_COLOR_BUFFER_BIT);
//	//	//glActiveTexture(GL_TEXTURE0);
//	//	//glBindTexture(GL_TEXTURE_2D, texture1);
//	//	//glActiveTexture(GL_TEXTURE1);
//	//	//glBindTexture(GL_TEXTURE_2D, texture2);
//
//
//	//	//ourShader.use();
//	//	//glBindVertexArray(VAO);
//	//	//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//	//	glfwSwapBuffers(window);
//	//	glfwPollEvents();
//
//
//	//}
//
//
//	
//	float vertices[] = {
//		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   0.55f, 0.55f,
//		 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   0.55f, 0.45f,
//		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.45f, 0.45f,
//		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.45f, 0.55f
//	};
//	unsigned int indices[] = {
//	0,1,3,
//	1,2,3
//	};
//	unsigned int VBO, VAO, EBO;
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(sizeof(float) * 3));
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//	glEnableVertexAttribArray(2);
//
//	unsigned int texture1, texture2;
//	glGenTextures(1, &texture1);
//	glBindTexture(GL_TEXTURE_2D, texture1);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//
//
//	int width, height, nrChannels;
//	stbi_set_flip_vertically_on_load(true);
//
//	unsigned char* data = stbi_load("F:/OpenGLImage/container.jpg", &width, &height, &nrChannels, 0);
//	if (data)
//	{
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//
//	}
//	else
//	{
//		std::cout << "Failed to load texture" << std::endl;
//
//	}
//	stbi_image_free(data);
//	glGenTextures(1, &texture2);
//	glBindTexture(GL_TEXTURE_2D, texture2);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	data = stbi_load("F:/OpenGLImage/awesomeface.png",&width,&height,&nrChannels,0);
//	if (data)
//	{
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else
//	{
//		std::cout << "Failed to load texture" << std::endl;
//	}
//	stbi_image_free(data);
//
//	Shader ourShader("E:/vstudioproject/LearnOpenGL/LearnOpenGL/vertexShaderSource_Texture3.GLSL", "E:/vstudioproject/LearnOpenGL/LearnOpenGL/fragmentShaderSource_Texture3.GLSL");
//	ourShader.use();
//	glUniform1i(glGetUniformLocation(ourShader.ID, "texture1"), 0);
//	ourShader.setInt("texture2", 1);
//
//
//	std::cout << 1111 << std::endl;
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
//
//		ourShader.use();
//		glBindVertexArray(VAO);
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//
//
//	}
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glDeleteBuffers(1, &EBO);
//	glfwTerminate();
//
//	return 0;
//
//	
//return 0;
//}