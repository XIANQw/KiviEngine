#pragma once
#include "Mesh.h"
#include "Shader.h"
#include <memory>

class Renderer
{
private:
	std::shared_ptr<Mesh> mMesh;
	std::shared_ptr<Shader> mShader;
public:
	Renderer(std::shared_ptr<Mesh> mesh, std::shared_ptr<Shader> shader);
	~Renderer();

	void Draw() const;
};

