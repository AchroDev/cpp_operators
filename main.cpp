#include <iostream>

/*
    There are many operators and this project will only showcase a few, the other will be split off into their own projects
    to showcase their functionality in a better way.

    Overloading operators allows you to define/change the way they work
*/

// Example Vector 2 struct
struct Vector2
{
    float x, y;

    Vector2(float x, float y)
        : x(x), y(y) {}

    // Example Add constructor
    Vector2 Add(const Vector2 &other) const
    {
        return Vector2(x + other.x, y + other.y);
    }

    // Example operator overload
    Vector2 operator+(const Vector2 &other) const
    {
        return Add(other);
    }

    // Example Multiply constructor
    Vector2 Multiply(const Vector2 &other) const
    {
        return Vector2(x * other.x, y * other.y);
    }

    // Example operator overload now for the multiply constructor
    Vector2 operator*(const Vector2 &other) const
    {
        return Multiply(other);
    }
};

int main()
{
    Vector2 position(4.0f, 4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 powerup(1.1f, 1.1f);

    Vector2 result1 = position.Add(speed.Multiply(powerup)); // At first we would've had to write the the code like this without the overloading
    Vector2 result2 = position + speed * powerup;            // Now we are able to simplify the code this way thanks to the overloads

    std::cin.get();
}
