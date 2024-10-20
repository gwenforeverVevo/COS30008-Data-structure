class Vector2D
{
private:
    float x, y;

public:
    Vector2D() : x(0), y(0) {}                     // Default constructor
    Vector2D(float aX, float aY) : x(aX), y(aY) {} // Parameterized constructor

    float getX() const { return x; }
    float getY() const { return y; }

    void setX(float aX) { x = aX; }
    void setY(float aY) { y = aY; }

    // Complete the overloaded operator
    /* Return type */ operator+(const Vector2D & other) const
    {
        // Implement addition here
    }
};
