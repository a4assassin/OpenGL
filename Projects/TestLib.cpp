#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include<Shaders.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);


int main()
{

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(1024, 768, "FirstWindow", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create a window.";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to load GLAD";
		return -1;
	}


	float vertices[] = { -0.5f, -0.5f, 0.f, 1.f, 0.f, 0.f,
						-0.5f,	0.5f,	0.f, 1.f, 0.f, 0.f,
						0.5f,	0.5f,	0.f, 0.f, 1.f,  0.f ,
						-0.7f, 0.f, 0.f,
						0.7f, 0.8f, 0.f,
						1.f, 1.f, 0.f };
	unsigned int indices[] = { 0, 3, 1,
								1, 3 , 2 };

	GLuint VBO[2], VAO[2];

	glGenBuffers(2, VBO);
	glGenVertexArrays(2, VAO);
	glBindVertexArray(VAO[0]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(sizeof(float)*3));
	glEnableVertexAttribArray(1);
	/*
	glBindVertexArray(VAO[1]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)(sizeof(float) * 9));
	glEnableVertexAttribArray(0);
	*/
	Shader ourShader("vertexShader.txt", "fragmentShader.txt");
	//unsigned int vertexShader, fragShader, fragShader2, shaderProgram, shaderProgram2;
	//vertexShader = glCreateShader(GL_VERTEX_SHADER);
	//fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	//fragShader2 = glCreateShader(GL_FRAGMENT_SHADER);
	//glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	//glShaderSource(fragShader, 1, &fragShaderSource, NULL);
	//glShaderSource(fragShader2, 1, &fragShaderSource2, NULL);
	//glCompileShader(vertexShader);
	//glCompileShader(fragShader);
	//glCompileShader(fragShader2);

	//shaderProgram = glCreateProgram();
	//glAttachShader(shaderProgram, vertexShader);
	//glAttachShader(shaderProgram, fragShader);
	//glLinkProgram(shaderProgram);

	//shaderProgram2 = glCreateProgram();
	//glAttachShader(shaderProgram2, vertexShader);
	//glAttachShader(shaderProgram2, fragShader2);
	//glLinkProgram(shaderProgram2);


	//glDeleteShader(vertexShader);
	//glDeleteShader(fragShader);
	//glDeleteShader(fragShader2);



	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		glClearColor(0.0f, 0.0f, 0.0f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);



		//float timeValue = glfwGetTime();
		//float colorValue = (sin(timeValue) / 2.0f) + 0.5f;
		//int vertexColorLoc = glGetUniformLocation(shaderProgram, "ourColor");
		ourShader.use();
		//glUniform4f(vertexColorLoc, 0.f, colorValue, 0.f, 1.f);

		glBindVertexArray(VAO[0]);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		/*
		int vertexColorLoc2 = glGetUniformLocation(shaderProgram2, "ourColor");
		glUseProgram(shaderProgram2);
		glUniform4f(vertexColorLoc2, colorValue, 0.f, 0.f, 1.f);

		glBindVertexArray(VAO[1]);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		*/
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, VAO);
	glDeleteBuffers(1, VBO);
	//glDeleteBuffers(1, &EBO);
	//glDeleteProgram(ourShader);
	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}