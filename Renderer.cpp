#include "Renderer.h"
#include <iostream>

Renderer::Renderer(std::shared_ptr<Mesh> mesh) : mMesh(mesh) {
}

Renderer::~Renderer() {
}


void Renderer::Draw() const{
	if (!mMesh) return;
	mMesh->Bind();
	glDrawElements(GL_TRIANGLES, mMesh->GetCount(), GL_UNSIGNED_INT, NULL);
}