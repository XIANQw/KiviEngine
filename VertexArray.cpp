#include "VertexArray.h"

VertexArray::VertexArray(VertexBuffer* vb, VertexBufferLayout* layout) : vb(vb), layout(layout) {
	glGenVertexArrays(1, &mID);
	glBindVertexArray(mID);
	vb->Bind();
	layout->Bind();
}

VertexArray::~VertexArray() {
	glDeleteVertexArrays(1, &mID);
	delete vb;
	delete layout;
}

VertexArray* VertexArray::CreateInstance(VertexBuffer* vb, VertexBufferLayout* layout) {
	if (vb == nullptr || layout == nullptr) return nullptr;
	return new VertexArray(vb, layout);
}

void VertexArray::Bind() {
	glBindVertexArray(mID);
}

void VertexArray::UnBind() {
	glBindVertexArray(0);
}