// DeuresClasses1.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


// Vector3 Class ----------------------------------------

template <class T>
class Vec3 {
	T x, y, z;

public:
	Vec3() {
		x = y = z = NULL;
	}

	Vec3(T x, T y, T z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	
	Vec3(const Vec3 &v) {
		x = v.x;
		y = v.y;
		z = v.z;
	}

	void printV();
	T distance_to(Vec3 & p);
	Vec3 normal();
	
};

template<class T>
void Vec3<T>::printV() {
	cout << "(" << x << "," << y << "," <<  z << ")" << endl;
}

template<class T>
T Vec3<T>::distance_to(Vec3 & v) {
	
	return sqrt(pow(x - v.x, 2) + pow(y - v.y, 2) + pow(z - v.z, 2));
}

template<class T>
Vec3<T> Vec3<T>::normal() {

	return this;
}


// String Class ---------------------------------------

int main()
{
	// Classe Vec3
	Vec3 <int> a;
	Vec3 <int> b(0, 1, 0);
	Vec3 <int> c(b);

	cout << c.distance_to(b);

	int f;
	cin >> f;
    return 0;
}

