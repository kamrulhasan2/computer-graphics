#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

// Triangle vertices
GLfloat vertices[] = {
-0.5f, -0.5f, 0.0f,
0.5f, -0.5f, 0.0f,
0.0f, 0.5f, 0.0f
};
// Vertex Shader source code
const char* vertexShaderSource = R";
#version 330 core
layout (location = 0) in vec3 aPos;
uniform mat4 rotationMatrix;
void main()
{
gl_Position = rotationMatrix * vec4(aPos, 1.0);
}
)";
// Fragment Shader source code
const char* fragmentShaderSource = R"(
#version 330 core
out vec4 FragColor;
void main()
{
FragColor = vec4(1.0, 1.0, 1.0, 1.0);
}
)";
// Function to compile shaders
GLuint compileShader(GLenum type, const char* source)
{
GLuint shader = glCreateShader(type);
glShaderSource(shader, 1, &source, nullptr);
glCompileShader(shader);
// Check for compilation errors
GLint success;
glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
if (!success)
{
GLchar infoLog[512];

glGetShaderInfoLog(shader, sizeof(infoLog), nullptr, infoLog);
std::cerr << "Shader compilation failed:\n" << infoLog << std::endl;
exit(EXIT_FAILURE);
}
return shader;
}
int main()
{
// Initialize GLFW
if (!glfwInit())
{
std::cerr << "Failed to initialize GLFW" << std::endl;
return -1;
}
// Create a windowed mode window and its OpenGL context
GLFWwindow* window = glfwCreateWindow(800, 600, "Point-to-Point Rotation", nullptr, nullptr);
if (!window)
{
std::cerr << "Failed to create GLFW window" << std::endl;
glfwTerminate();
return -1;
}
// Make the window's context current
glfwMakeContextCurrent(window);
// Initialize GLEW
if (glewInit() != GLEW_OK)
{
std::cerr << "Failed to initialize GLEW" << std::endl;
return -1;
}
// Create and compile the vertex shader
GLuint vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
// Create and compile the fragment shader
GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
// Link the shaders into a program
GLuint shaderProgram = glCreateProgram();
glAttachShader(shaderProgram, vertexShader);
glAttachShader(shaderProgram, fragmentShader);
glLinkProgram(shaderProgram);

// Check for linking errors
GLint success;
glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
if (!success)
{
GLchar infoLog[512];
glGetProgramInfoLog(shaderProgram, sizeof(infoLog), nullptr, infoLog);
std::cerr << "Shader program linking failed:\n" << infoLog << std::endl;
exit(EXIT_FAILURE);
}
// Delete the shaders as they're linked into our program now and no longer needed
glDeleteShader(vertexShader);
glDeleteShader(fragmentShader);
// Set up vertex data (and buffer(s)) and attribute pointers
GLuint VBO, VAO;
glGenVertexArrays(1, &VAO);
glGenBuffers(1, &VBO);
// Bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex
attributes(s).
glBindVertexArray(VAO);
glBindBuffer(GL_ARRAY_BUFFER, VBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
glEnableVertexAttribArray(0);
glBindBuffer(GL_ARRAY_BUFFER, 0); // Unbind VBO
glBindVertexArray(0); // Unbind VAO
// Enable depth testing
glEnable(GL_DEPTH_TEST);
// Main loop
while (!glfwWindowShouldClose(window))
{
// Check and call events
glfwPollEvents();
// Set the viewport size
int width, height;
glfwGetFramebufferSize(window, &width, &height);
glViewport(0, 0, width, height);
// Clear the color and depth buffers

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// Use the shader program
glUseProgram(shaderProgram);
// Define the rotation matrix
float angle = glfwGetTime() * 50.0f; // Rotate at 50 degrees per second
glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0.0f, 0.0f,
1.0f));
// Get the location of the rotationMatrix uniform
GLuint rotationMatrixLoc = glGetUniformLocation(shaderProgram, "rotationMatrix");
// Set the rotation matrix uniform
glUniformMatrix4fv(rotationMatrixLoc, 1, GL_FALSE, glm::value_ptr(rotationMatrix));
// Draw the triangle
glBindVertexArray(VAO);
glDrawArrays(GL_TRIANGLES, 0, 3);
glBindVertexArray(0);
// Swap the front and back buffers
glfwSwapBuffers(window);
}
// Clean up
glDeleteVertexArrays(1, &VAO);
glDeleteBuffers(1, &VBO);
glDeleteProgram(shaderProgram);
// Terminate GLFW
glfwTerminate();
return 0;
}
