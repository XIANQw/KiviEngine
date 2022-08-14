#include "VertexArray.h"

VertexArray::VertexArray(VertexBuffer* vb, VertexLayout* layout) : vb(vb) {
	glGenVertexArrays(1, &mID);
	glBindVertexArray(mID);
	vb->Bind();
	layout->Bind();
}

VertexArray::~VertexArray() {
	glDeleteVertexArrays(1, &mID);
	delete vb.release();
}

VertexArray* VertexArray::CreateInstance(VertexBuffer* vb, VertexLayout* layout) {
	if (vb == nullptr || layout == nullptr) return nullptr;

	return new VertexArray(vb, layout);
}

void VertexArray::Bind() {
	glBindVertexArray(mID);
}

void VertexArray::UnBind() {
	glBindVertexArray(0);
}