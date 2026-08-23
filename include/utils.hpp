#pragma once

struct vector2i{
    int x = 0;
    int y = 0;
};

struct vector2f{
    float x = 0;
    float y = 0;
    vector2f() : x(0), y(0) {}
    vector2f(float x, float y) : x(x), y(y) {}

    // Suma
    vector2f operator+(const vector2f& other) const {
        return vector2f(x + other.x, y + other.y);
    }
    //Resta
    vector2f operator-(const vector2f& other) const {
        return vector2f(x - other.x, y - other.y);
    }
    // Multiplicacion por escalar
    vector2f operator*(float scalar) const {
        return vector2f(x * scalar, y * scalar);
    }
    friend vector2f operator*(float scalar, const vector2f& v) {
        return vector2f(v.x * scalar, v.y * scalar);
    }
    // Division
    vector2f operator/(float scalar) const {
        return vector2f(x / scalar, y / scalar);
    }
    // Producto escalar
    float dot(const vector2f& other) const {
        return x * other.x + y * other.y;
    }
};

int Index(int i, int j, int cols, int rows);
float MapValue(float x, float in_min, float in_max, float out_min, float out_max);