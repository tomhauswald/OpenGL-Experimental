#pragma once

#include "opengl_buffer.h"

namespace planet {

	struct Vertex {
		vec3 position;
		vec3 normal;
		vec3 color;
		vec2 uv;
	};

	class Mesh {
	private:
		Vertex* vertices;
		u16 vertexCount;
		u16* indices;
		u16 indexCount;

	public:
		OpenGLVertexArray* vao;
		OpenGLBuffer* vbo;
		OpenGLBuffer* ibo;

		Mesh();
		void updateVertexBuffer(Vertex* vertices, u16 count, GLenum usage);
		void updateIndexBuffer(u16* indices, u16 count, GLenum usage);
		void render();
		~Mesh();
	};
}