#pragma once

#include "component.h"
#include "orientation_component.h"
#include "opengl_common.h"

namespace planet {
	struct ViewProjComponent : public Component {
	private:
		// Camera orientation.
		OrientationComponent *orientation;
		
		// Up vector.
		const vec3 up = { 0, 1, 0 };

		// Untransformed forward vector.
		const vec3 forward = { 0, 0, 1 };

		// Projection matrix. 
		const mat4 projection;

		// Calculated view-projection matrix.
		mat4 viewProjMatrix;
	
	public:
		ViewProjComponent(mat4 const &projection, OrientationComponent *orientation);
		
		void update(float dt);

		inline mat4 const &getMatrix() const { return viewProjMatrix; }
	};
}