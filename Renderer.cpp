#include "Renderer.h"

void Renderer::Draw() {
	if (vao == nullptr || ibo == nullptr) return;
	vao->Bind();
	ibo->Bind();
	glDrawElements(GL_TRIANGLES, ibo->GetCount(), GL_UNSIGNED_INT, NULL);
}