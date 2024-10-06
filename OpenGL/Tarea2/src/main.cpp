#include <cstdlib>
#include <iostream>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

/* Variables globales */
const int BGColor = 0x1b1e2b;
const int V1Color = 0xff0000;
const int V2Color = 0x00ff00;
const int V3Color = 0x0000ff;

/* Estructura RGB para manejar canales de color facilmente */
struct RGB {

	float r;
	float g;
	float b;

};
/* Funcion para extraer valores RGB de color en Hexadecimal */
RGB colorConverter(int hexValue)
{
	struct RGB rgb;

	rgb.r = ((hexValue >> 16) & 0xFF) / 255.0;  // Extract the RR byte
	rgb.g = ((hexValue >> 8) & 0xFF) / 255.0;   // Extract the GG byte
	rgb.b = ((hexValue) & 0xFF) / 255.0;        // Extract the BB byte

	return rgb;
}

int main(void) {

	GLFWwindow* window;

	/*  Inicializa libreria de glfw */
	if (!glfwInit()) {
		return -1;
	}

	/* Creacion de ventana emergente y contexto */
	window = glfwCreateWindow(640, 480, "Triangulito en OpenGl", NULL, NULL);

	if (!window) {
		glfwTerminate();
		return -1;
	}

	/* Indicacion de ventana/lienzo actual para glfw */
	glfwMakeContextCurrent(window);

	/* Iniciacion de libreria de glew */
	GLenum glew_status = glewInit();
	if (glew_status != GLEW_OK) {
		cerr << "Error: glewInit: " << glewGetErrorString(glew_status) << endl;
		return EXIT_FAILURE;
	}

	/* Preparacion de color */
	RGB BGrgb = colorConverter(BGColor);
	RGB V1rgb = colorConverter(V1Color);
	RGB V2rgb = colorConverter(V2Color);
	RGB V3rgb = colorConverter(V3Color);


	/* Ciclo hasta que el usuario cierre la ventana */
	while (!glfwWindowShouldClose(window))
	{

		/* Renderizado de la ventana */
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(BGrgb.r,BGrgb.g,BGrgb.b,1.0f);
		
		/* Renderizado del triangulo */
		glBegin(GL_TRIANGLES);
		
		/* Posicion y colores de los vertices */
		glColor3f(V2rgb.r, V2rgb.g, V2rgb.b);
		glVertex2f(-0.5f, -0.5f);
		glColor3f(V1rgb.r, V1rgb.g, V1rgb.b);
		glVertex2f(0.0f, 0.87f);
		glColor3f(V3rgb.r, V3rgb.g, V3rgb.b);
		glVertex2f(0.5f, -0.5f); 


		/* Fin del renderizado del triangulo */
		glEnd();

		/* Intercambio entre buffers */
		glfwSwapBuffers(window);

		/* Recepcion de eventos */
		glfwPollEvents();

	}

	/* Cierre de glfw */
	glfwTerminate();

	return 0;

}