#include "Vector3.h"
#include <cmath>

Launch::Vector3::Vector3()
{
    x = 0;
    y = 0;
    z = 0;
}

Launch::Vector3::Vector3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

float Launch::Vector3::getMagnitude()
{
    return sqrt(x * x + y * y + +z * z);
}

Launch::Vector3 Launch::Vector3::getNormalized()
{
    return normalize(*this);
}

std::string Launch::Vector3::toString()
{
    return std::string("(" +
        std::to_string(x) +
        ", " +
        std::to_string(y) +
        ", " +
        std::to_string(z) +
        ")");
}

Launch::Vector3 Launch::Vector3::normalize(Vector3 vector)
{
    if (vector.getMagnitude() == 0)
        return Vector3();

    return vector / vector.getMagnitude();
}

float Launch::Vector3::dotProduct(Vector3 lhs, Vector3 rhs)
{
    return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
}

Launch::Vector3 Launch::Vector3::crossProduct(Vector3 lhs, Vector3 rhs)
{
    return Vector3((lhs.y * rhs.z) - (lhs.z * rhs.y), (lhs.z * rhs.x) - (lhs.x * rhs.z), (lhs.x * rhs.y) - (lhs.y * rhs.x));
}

Launch::Vector3 Launch::Vector3::lerp(Vector3 start, Vector3 end, float time)
{
    // If the timescale is 0, return the start vector
    if (time == 0)
        return start;
    // If the timescale is set to 1, meaning we travel 100% of the way, return the end vector
    else if (time == 1)
        return end;
    // If the distance between the start and end vector is miniscule, return the end vector
    else if ((end - start).getMagnitude() < 0.001f)
        return end;

    return start + (end - start) * time;
}

float Launch::Vector3::distance(Vector3 start, Vector3 end)
{
    return sqrt(pow(end.x - start.y, 2) + pow(end.y - start.y, 2) + pow(end.z - start.z, 2));
}

Launch::Vector3 Launch::Vector3::operator +(Vector3 rhs)
{
    return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
}

Launch::Vector3 Launch::Vector3::operator -(Vector3 rhs)
{
    return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
}

Launch::Vector3 Launch::Vector3::operator *(float scalar)
{
    return Vector3(x * scalar, y * scalar, z * scalar);
}

Launch::Vector3 operator *(float scalar, Launch::Vector3 rhs)
{
    return Launch::Vector3(scalar * rhs.x, scalar * rhs.y, scalar * rhs.z);
}

Launch::Vector3 Launch::Vector3::operator / (float scalar)
{
    return Vector3(x / scalar, y / scalar, z / scalar);
}

bool Launch::Vector3::operator==(Vector3 rhs)
{
    return x == rhs.x && y == rhs.y && z == rhs.z;
}
