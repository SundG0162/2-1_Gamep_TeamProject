#pragma once
#include<iostream>
struct Vector2
{
	Vector2(int x, int y) : x{ x }, y{ y } {};
	int x;
	int y;

    // ���� ������ �����ε�
    Vector2 operator+(const Vector2& other) const {
        return Vector2(x + other.x, y + other.y);
    }

    // ���� ������ �����ε�
    Vector2 operator-(const Vector2& other) const {
        return Vector2(x - other.x, y - other.y);
    }

    // ���� ������ �����ε� (��Į�� ��)
    Vector2 operator*(int scalar) const {
        return Vector2(x * scalar, y * scalar);
    }

    // ��� ������ �����ε�
    friend std::ostream& operator<<(std::ostream& os, const Vector2& vec) {
        os << "(" << vec.x << ", " << vec.y << ")";
        return os;
    }
};

