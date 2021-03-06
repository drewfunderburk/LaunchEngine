#include "Transform.h"
#include "Log.h"
#include "Actor.h"

Launch::Vector3 Launch::Transform::getForward() const
{
	return Vector3(m_globalTransformMatrix.m11, m_globalTransformMatrix.m21, m_globalTransformMatrix.m31).getNormalized();
}

Launch::Vector3 Launch::Transform::getWorldPosition() const
{
	return Vector3(m_globalTransformMatrix.m13, m_localTransformMatrix.m23, m_globalTransformMatrix.m33);
}

void Launch::Transform::setWorldPosition(Vector3 position)
{
	if (Actor* actor = getActor())
		if (Actor* parent = actor->getParent())
		setLocalPosition(position + parent->getTransform().getWorldPosition());
	else
		setLocalPosition(position);
}

Launch::Vector3 Launch::Transform::getLocalPosition() const
{
	return Vector3(m_localTransformMatrix.m13, m_localTransformMatrix.m23, m_localTransformMatrix.m33);
}

void Launch::Transform::setLocalPosition(Vector3 position)
{
	LN_CORE_ERROR("Transform::setLocalPosition not implemented!");
}

Launch::Vector3 Launch::Transform::getRotation() const
{
	LN_CORE_ERROR("Transform::getRotation not implemented!");
	return Vector3();
}

void Launch::Transform::setRotation(Vector3 rotation)
{
	LN_CORE_ERROR("Transform::setRotation not implemented!");
}

Launch::Vector3 Launch::Transform::getScale() const
{
	LN_CORE_ERROR("Transform::getScale not implemented!");
	return Vector3();
}

void Launch::Transform::setScale(Vector3 scale)
{
	LN_CORE_ERROR("Transform::setScale not implemented!");
}

void Launch::Transform::translate(Vector3 translation)
{
	translate(translation.x, translation.y, translation.z);
}

void Launch::Transform::translate(float x, float y, float z)
{
	LN_CORE_ERROR("Transform::translate not implemented!");
}

void Launch::Transform::rotate(Vector3 rotation)
{
	rotate(rotation.x, rotation.y, rotation.z);
}

void Launch::Transform::rotate(float x, float y, float z)
{
	LN_CORE_ERROR("Transform::rotate not implemented!");
}

void Launch::Transform::scale(Vector3 scale)
{
	Transform::scale(scale.x, scale.y, scale.z);
}

void Launch::Transform::scale(float x, float y, float z)
{
	LN_CORE_ERROR("Transform::scale not implemented!");
}

void Launch::Transform::lookAt(Vector3 position)
{
	LN_CORE_ERROR("Transform::lookAt not implemented!");
}

void Launch::Transform::lookAt(Transform* transform)
{
	lookAt(transform->getWorldPosition());
}

Launch::Vector3 Launch::Transform::getRight() const
{
	LN_CORE_ERROR("Transform::getRight not implemented!");
	return Vector3();
}

Launch::Vector3 Launch::Transform::getUp() const
{
	LN_CORE_ERROR("Transform::getUp not implemented!");
	return Vector3();
}
