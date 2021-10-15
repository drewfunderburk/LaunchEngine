#pragma once
#include "Core.h"
#include "Math/Vector3.h"
#include "Math/Matrix4.h"

namespace Launch
{
	class LAUNCH_API Transform
	{
		friend class Actor;
	public:
		Transform() {}
		~Transform() {}

		void translate(Vector3 translation);
		void translate(float x, float y, float z);
		void rotate(Vector3 rotation);
		void rotate(float x, float y, float z);
		void scale(Vector3 scale);
		void scale(float x, float y, float z);
		void lookAt(Vector3 position);
		void lookAt(Transform* transform);

		Vector3 getRight();
		Vector3 getUp();
		Vector3 getForward();

		Vector3 getWorldPosition();
		void setWorldPosition(Vector3 position);
		Vector3 getLocalPosition();
		void setLocalPosition(Vector3 position);
		Vector3 getRotation();
		void setRotation(Vector3 rotation);
		Vector3 getScale();
		void setScale(Vector3 scale);

		Actor* getActor() { return m_actor; }

	private:
		Actor* m_actor = nullptr;
		Matrix4 m_localTransformMatrix = Matrix4();
		Matrix4 m_globalTransformMatrix = Matrix4();
	};
}