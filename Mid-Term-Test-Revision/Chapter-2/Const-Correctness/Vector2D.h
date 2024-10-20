class Vector2D {
private:
    float x, y;

public:
    Vector2D(float aX, float aY) : x(aX), y(aY) {}

    // Complete the following function signatures for const correctness
    /* Return type */ getX() /* const */;
    /* Return type */ getY() /* const */;
    void setX(float aX);
    void setY(float aY);
};
