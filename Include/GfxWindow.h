#pragma once
#include "GLDebug.h"
#include <glfw3.h>
#include <string>
#include <iostream>
#include "Renderer.h"

class GfxWindow
{
public:
	int Width = 640;
	int Height = 480;

private:
	GLFWwindow* mWindow;
	std::string mTitle;

public:
	GfxWindow(int width, int height, std::string title);
	~GfxWindow();
	bool Init();
	std::vector<Renderer*> PrepareData();
	void RenderLoop(const std::vector<Renderer*>& rdrs);
	inline bool ShouldBeClosed() { return glfwWindowShouldClose(mWindow); }
};

