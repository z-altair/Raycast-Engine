#pragma once
#include <cmath>

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
    // Cambio de signo
    vector2f operator-() const {
        return vector2f(-x, -y);
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
        return scalar == 0 ? vector2f(0,0) : vector2f(x / scalar, y / scalar);
    }
    // Producto escalar
    float dot(const vector2f& other) const {
        return x * other.x + y * other.y;
    }
    // Normalizar
    vector2f normalize() const {
        float length = magnitude();
        if (length == 0.0f) return vector2f(0.0f, 0.0f);
        return vector2f(x / length, y / length);
    }
    // Conseguir longitud
    float magnitude() const {
        return sqrt(x * x + y * y);
    }

    // Comparaciones logicas
    bool operator==(const vector2f& other) const {
        return x == other.x && y == other.y;
    }
    bool operator!=(const vector2f& other) const {
        return !(*this == other);
    }
};

int Index(int i, int j, int cols, int rows);
float MapValue(float x, float in_min, float in_max, float out_min, float out_max);