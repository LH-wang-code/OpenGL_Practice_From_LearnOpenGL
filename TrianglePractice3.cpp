#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>



const char * vertexShaderSource = "#version 330 core\n"
"layout (location=0)in vec3 aPos;\n"
"void main()\n"
"{\n"
"gl_Position =vec4(aPos.x,aPos.y,aPos.z,1.0f);\n"
"}\n";

const char* fragmentShaderSourceOrange = "#version 330 core\n"
"out vec4 FragColor;"
"void main()\n"
"{\n"
"FragColor=vec4(1.0f,0.5f,0.2f,1.0f);\n"
"}\n";
const char* fragmentShaderSourceYellow = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"FragColor=vec4(1.0f,1.0f,0.0f,1.0f);\n"
"}\n";
void key_callback(GLFWwindow* window, int key, int scancode, int action,int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)

	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}
int main()
{

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "TrianglePractice3", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "FAILED::CREATEWINDOW" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "failed to initilized GLAD" << std::endl;
		return -1;
	}

	//创建视口
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	GLfloat vertices1[] = {
				1.0f,0.0f,0.0f,
		0.5f,0.5f,0.0f,
		0.0f,0.0f,0.0f,
	};
	GLfloat vertices2[] = {
		-1.0f,0.0f,0.0f,
		-0.5f,0.5f,0.0f,
		0.0f,0.0f,0.0f
	};
	//绑定各种数据
	unsigned int VBOs[2], VAOs[2];
	glGenBuffers(2, VBOs);
	glGenVertexArrays(2, VAOs);
	glBindVertexArray(VAOs[0]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(VAOs[1]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	//着色器程序
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fragmentShaderOrange = glCreateShader(GL_FRAGMENT_SHADER);
	unsigned int fragmentShaderYellow = glCreateShader(GL_FRAGMENT_SHADER);
	unsigned int shaderProgramOrange = glCreateProgram();
	unsigned int shaderProgramYellow = glCreateProgram();
	glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
	glCompileShader(vertexShader);
	glShaderSource(fragmentShaderOrange, 1, &fragmentShaderSourceOrange, nullptr);
	glCompileShader(fragmentShaderOrange);

	glShaderSource(fragmentShaderYellow, 1, &fragmentShaderSourceYellow, nullptr);
	glCompileShader(fragmentShaderYellow);

	glAttachShader(shaderProgramOrange, vertexShader);
	glAttachShader(shaderProgramOrange, fragmentShaderOrange);
	glLinkProgram(shaderProgramOrange);
	glAttachShader(shaderProgramYellow, vertexShader);
	glAttachShader(shaderProgramYellow, fragmentShaderYellow);
	glLinkProgram(shaderProgramYellow);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shaderProgramOrange);
		glBindVertexArray(VAOs[0]);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);
		glUseProgram(shaderProgramYellow);
		glBindVertexArray(VAOs[1]);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);
		glfwSwapBuffers(window);

	}
	glDeleteVertexArrays(2, VAOs);
	glDeleteBuffers(2, VBOs);
	glDeleteProgram(shaderProgramOrange);
	glDeleteProgram(shaderProgramYellow);
	glfwTerminate();
	return 0;
}