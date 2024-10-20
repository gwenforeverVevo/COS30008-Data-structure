void updateVector(Vector2D &vec, const Vector2D &other,/* add appropriate const reference parameters */) {
    // Modify 'vec' based on another vector
    vec.setX(vec.getX() + other.getX());
    vec.setY(vec.getY() + other.getY());
}
