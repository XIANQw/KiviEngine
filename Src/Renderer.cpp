#include "Renderer.h"
#include <iostream>

Renderer::Renderer(std::shared_ptr<Mesh> mesh, std::shared_ptr<Shader> shader) 
	: mMesh(mesh), mShader(shader) {
}

Renderer::~Renderer() {
}


void Renderer::Draw() const{
	if (!mMesh) return;
	mMesh->Bind();
	mShader->Bind();
	glDrawElements(GL_TRIANGLES, mMesh->GetCount(), GL_UNSIGNED_INT, NULL);
}