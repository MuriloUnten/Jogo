#pragma once

#include <iostream>

namespace Math {
    template <typename TL>
    class Coordinate {
    public:
        TL x;
        TL y;

    public:
        Coordinate(TL x, TL y);
        Coordinate();
        ~Coordinate() { }

        void operator=(Coordinate<TL> other);
        void operator+=(Coordinate<TL> other);
        void operator-=(Coordinate<TL> other);
        void operator*=(double scalar);
        void operator/=(double scalar);

        Coordinate<TL> operator+(Coordinate<TL> other);
        Coordinate<TL> operator-(Coordinate<TL> other);
        Coordinate<TL> operator*(Coordinate<TL> other);
        Coordinate<TL> operator*(double scalar);
        Coordinate<TL> operator/(Coordinate<TL> other);
        Coordinate<TL> operator/(double scalar);
    };

    typedef Coordinate<double> CoordD;
    typedef Coordinate<float> CoordF;
    typedef Coordinate<int> CoordI;
    typedef Coordinate<unsigned int> CoordU;

    template <typename TL>
    Coordinate<TL>::Coordinate(TL x, TL y) :
    x(x),
    y(y) { }

    template <typename TL>
    Coordinate<TL>::Coordinate() {
        this->x = 0;
        this->y = 0;
    }

    template <typename TL>
    void Coordinate<TL>::operator=(Coordinate<TL> other) {
        this->x = other.x;
        this->y = other.y;
    }

    template <typename TL>
    void Coordinate<TL>::operator+=(Coordinate<TL> other) {
        this->x += other.x;
        this->y += other.y;
    }

    template <typename TL>
    void Coordinate<TL>::operator-=(Coordinate<TL> other) {
        this->x -= other.x;
        this->y -= other.y;
    }

    template <typename TL>
    void Coordinate<TL>::operator*=(double scalar) {
        this->x = this->x * scalar;
        this->y = this->y * scalar;
    }

    template <typename TL>
    void Coordinate<TL>::operator/=(double scalar) {
        if (scalar == 0.0f) {
            std::cout << "ERROR: Cannot divide by zero." << std::endl;
            exit(1);
        }
        this->x /= scalar;
        this->y /= scalar;
    }

    template <typename TL>
    Coordinate<TL> Coordinate<TL>::operator+(Coordinate<TL> other) {
        return Coordinate<TL>(this->x + other.x, this->y + other.y);
    }

    template <typename TL>
    Coordinate<TL> Coordinate<TL>::operator-(Coordinate<TL> other) {
        return Coordinate<TL>(this->x - other.x, this->y - other.y);
    }

    template <typename TL>
    Coordinate<TL> Coordinate<TL>::operator*(Coordinate<TL> other) {
        return Coordinate<TL>(this->x * other.x, this->y * other.y);
    }

    template <typename TL>
    Coordinate<TL> Coordinate<TL>::operator*(double scalar) {
        return Coordinate<TL>(this->x * scalar, this->y * scalar);
    }

    template <typename TL>
    Coordinate<TL> Coordinate<TL>::operator/(Coordinate<TL> other) {
        if (other.x == 0.0f || other.y == 0.0f) {
            std::cout << "ERROR: Cannot divide by zero." << std::endl;
            exit(1);
        }
        return Coordinate<TL>(this->x / other.x, this->y / other.y);
    }

    template <typename TL>
    Coordinate<TL> Coordinate<TL>::operator/(double scalar) {
        if (scalar == 0.0f) {
            std::cout << "ERROR: Cannot divide by zero." << std::endl;
            exit(1);
        }

        return Coordinate<TL>(this->x / scalar, this->y / scalar);
    }

} //namespace Math