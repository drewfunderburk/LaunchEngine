#include "Vector2.h"
#include <cmath>
#include <string>

Launch::Vector2::Vector2()
{
    x = 0;
    y = 0;
}

Launch::Vector2::Vector2(float x, float y)
{
    this->x = x;
    this->y = y;
}

float Launch::Vector2::getMagnitude()
{
    return sqrt(x * x + y * y);
}

Launch::Vector2 Launch::Vector2::getNormalized()
{
    return normalize(*this);
}

const char* Launch::Vector2::toString()
{
    return std::string("(" +
        std::to_string(x) +
        ", " +
        std::to_string(y) +
        ")").c_str();
}

Launch::Vector2 Launch::Vector2::normalize(Vector2 vector)
{
    if (vector.getMagnitude() == 0)
        return Vector2();

    return vector / vector.getMagnitude();
}

float Launch::Vector2::dotProduct(Vector2 lhs, Vector2 rhs)
{
    return (lhs.x * rhs.x) + (lhs.y * rhs.y);
}

float Launch::Vector2::angle(Vector2 lhs, Vector2 rhs)
{
    lhs = normalize(lhs);
    rhs = normalize(rhs);

    //Use the dotproduct to find the angle the actor needs to rotate
    float dotProd = dotProduct(lhs, rhs);

    if (abs(dotProd) > 1)
        return 0;

    float angle = (float)acos(dotProd);

    //Find a perpindicular vector to the direction
    Vector2 perp = Vector2(rhs.y, -rhs.x);

    //Find the dot product of the perpindicular vector and the current forward
    float perpDot = dotProduct(perp, lhs);

    //If the result isn't 0, use it to change the sign of the angle to be either positive or negative
    if (perpDot != 0)
        angle *= perpDot / abs(perpDot);

    return angle;
}

Launch::Vector2 Launch::Vector2::lerp(Vector2 start, Vector2 end, float time)
{
    // If the timescale is 0, return the start vector
    if (time == 0)
        return start;
    // If the timescale is set to 1, meaning we travel 100% of the way, return the end vector
    else if (time == 1)
        return end;
    // If the distance between the start and end vector is miniscule, return the end vector
    else if ((end - start).getMagnitude() < 0.1)
        return end;

    return start + (end - start) * time;
}

float Launch::Vector2::distance(Vector2 start, Vector2 end)
{
    return sqrt(pow(end.x - start.y, 2) + pow(end.y - start.y, 2));
}

Launch::Vector2 Launch::Vector2::operator +(Vector2 rhs)
{
    return Vector2(x + rhs.x, y + rhs.y);
}

Launch::Vector2 Launch::Vector2::operator -(Vector2 rhs)
{
    return Vector2(x - rhs.x, y - rhs.y);
}

Launch::Vector2 Launch::Vector2::operator *(float scalar)
{
    return Vector2(x * scalar, y * scalar);
}

Launch::Vector2 operator *(float scalar, Launch::Vector2 rhs)
{
    return Launch::Vector2(scalar * rhs.x, scalar * rhs.y);
}

Launch::Vector2 Launch::Vector2::operator / (float scalar)
{
    return Vector2(x / scalar, y / scalar);
}

bool Launch::Vector2::operator==(Vector2 rhs)
{
    return x == rhs.x && y == rhs.y;
}
