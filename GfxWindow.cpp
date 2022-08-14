#include "GfxWindow.h"
#include "Mesh.h"

GLDebug globalGLDebug;

GfxWindow::GfxWindow(int width, int height, std::string title):Width(width), Height(height), mTitle(title), mWindow(nullptr) 
{
}

GfxWindow::~GfxWindow()
{
	glfwDestroyWindow(mWindow);
	glfwTerminate();
}

void GLAPIENTRY ErrorCallback(
	GLenum source,
	GLenum type,
	GLuint id,
	GLenum severity,
	GLsizei length,
	const GLchar* message,
	const void* userParam) 
{
	globalGLDebug.OutputError(source, type, id, severity, message);
}


/// <summary>
/// 窗口初始化
/// </summary>
/// <returns></returns>
bool GfxWindow::Init() 
{
	if (!glfwInit()) return false;

	mWindow = glfwCreateWindow(640, 480, "KiviEngine", NULL, NULL);

	if (!mWindow) {
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(mWindow);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return false;
	}

	glEnable(GL_DEBUG_OUTPUT);
	glDebugMessageCallback(ErrorCallback, 0);

	return true;
}


std::vector<Renderer*> GfxWindow::PrepareData() 
{
	const float vertex[] = {
		-0.5f, -0.5f, 0.0f, 0.0f,
		0.5f, -0.5f, 1.0f, 0.0f,
		0.5f, 0.5f, 1.0f, 1.0f,
		-0.5f, 0.5f,  0.0f, 1.0f,
		0.0f, 1.0f, 0.5f, 1.5f,
	};

	const unsigned int indices1[] = {0, 1, 3};
	const unsigned int indices2[] = { 1, 2, 3 };
	const unsigned int indices3[] = { 4, 2, 3 };

	VertexLayout vbLayout;
	vbLayout.AddElement<float>(2);
	vbLayout.AddElement<float>(2);
	std::shared_ptr<Mesh> mesh1 = std::make_shared<Mesh>(vertex, 5, indices1, 3, vbLayout);
	std::shared_ptr<Mesh> mesh2 = std::make_shared<Mesh>(vertex, 5, indices2, 3, vbLayout);
	std::shared_ptr<Mesh> mesh3 = std::make_shared<Mesh>(vertex, 5, indices3, 3, vbLayout);

	std::vector<Renderer*>res;
	res.push_back(new Renderer(mesh1));
	res.push_back(new Renderer(mesh2));
	res.push_back(new Renderer(mesh3));
	return res;
}


/// <summary>
/// 渲染主循环
/// </summary>
void GfxWindow::RenderLoop(const std::vector<Renderer*>& rdrs) 
{
	glClear(GL_COLOR_BUFFER_BIT);

	for (const Renderer* rdr : rdrs) {
		rdr->Draw();
	}
	glfwSwapBuffers(mWindow);

	glfwPollEvents();
}
