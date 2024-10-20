class Vector2D {
private:
    float x, y;

public:
    Vector2D(float aX, float aY) : x(aX), y(aY) {}

    // Overload the >> operator for input
    friend std::istream &operator>>(std::istream &input, Vector2D &vec);

    // Overload the << operator for output
    friend std::ostream &operator<<(std::ostream &output, const Vector2D &vec);
};
