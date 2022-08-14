#pragma once
#include "Mesh.h"

#include <memory>

class Renderer
{
private:
	std::shared_ptr<Mesh> mMesh;

public:
	Renderer(std::shared_ptr<Mesh> mesh);
	~Renderer();

	void Draw() const;
};

