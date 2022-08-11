#pragma once
#include "VertexArray.h"
#include "IndexBuffer.h"
#include <memory>

class Renderer
{
private:
	std::shared_ptr<VertexArray> vao;
	std::shared_ptr <IndexBuffer> ibo;
public:
	Renderer(std::shared_ptr<VertexArray> vao, std::shared_ptr<IndexBuffer> ibo) : vao(vao), ibo(ibo) {}
	~Renderer() { }

	void Draw();
};

