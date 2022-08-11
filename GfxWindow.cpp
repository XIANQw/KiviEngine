#include "GfxWindow.h"

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

	VertexBuffer* vb = new VertexBuffer(vertex, 5 * 4 * sizeof(float));
	VertexBufferLayout* vbLayout = new VertexBufferLayout();
	vbLayout->AddElement<float>(2);
	vbLayout->AddElement<float>(2);

	std::shared_ptr<VertexArray> vao(VertexArray::CreateInstance(vb, vbLayout));
	std::shared_ptr <IndexBuffer> ib1 = std::make_shared<IndexBuffer>(indices1, 3);
	std::shared_ptr <IndexBuffer> ib2 = std::make_shared<IndexBuffer>(indices2, 3);
	std::shared_ptr <IndexBuffer> ib3 = std::make_shared<IndexBuffer>(indices3, 3);

	Renderer* rdr1 = new Renderer(vao, ib1);
	Renderer* rdr2 = new Renderer(vao, ib2);
	Renderer* rdr3 = new Renderer(vao, ib3);
	std::vector<Renderer*>res {rdr1, rdr2, rdr3};
	return res;
}


/// <summary>
/// 渲染主循环
/// </summary>
void GfxWindow::RenderLoop(const std::vector<Renderer*>& rdrs) 
{
	glClear(GL_COLOR_BUFFER_BIT);

	for (Renderer* rdr : rdrs) {
		if (rdr == nullptr) continue;
		rdr->Draw();
	}
	glfwSwapBuffers(mWindow);

	glfwPollEvents();
}
