#pragma once
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray
{
private:
	unsigned int mID;
	VertexBuffer* vb;
	VertexBufferLayout* layout;
	VertexArray(VertexBuffer* vb, VertexBufferLayout* layout);

public:
	~VertexArray();
	inline unsigned int GetID() { return mID; }
	void Bind();
	void UnBind();

	static VertexArray* CreateInstance(VertexBuffer* vb, VertexBufferLayout* layout);
};

