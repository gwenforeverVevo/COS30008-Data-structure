class Vector2D {
private:
    float x, y;

public:
    Vector2D(float aX, float aY) : x(aX), y(aY) {}

    // Grant friend access to a non-member function
    friend float distanceBetween(const Vector2D &a, const Vector2D &b);
};

// Implement the friend function here
float distanceBetween(const Vector2D &a, const Vector2D &b) {
    // Calculate and return the Euclidean distance between 'a' and 'b'
}
