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
		x = y = z = 0;
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
	Vec3 operator+ (Vec3 & p);
	Vec3 operator= (Vec3 & p);
	
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

	Vec3<int> ini;
	T dist = distance_to(ini);
	return (Vec3<T>(x / dist, y / dist, y /dist));
}

template<class T>
Vec3<T> Vec3<T>::operator+(Vec3 & p) {
	return (Vec3<T>(x + p.x, y + p.y, z + p.z));
}

template<class T>
Vec3<T> Vec3<T>::operator=(Vec3 & p) {
	this.x = p.x;
	this.y = p.y;
	this.z = p.z;
	return *this;
}

// String Class ---------------------------------------
class cadena {
public:
	char* ini;
	int tamany;

public:
	cadena(const char p[]);
	cadena(const cadena & p);
	void printCad();
	cadena operator+(cadena & b);
	cadena operator=(cadena & b);
	bool operator==(cadena & b);
	bool operator==(char s[]);
	int length();
	void clear();

};

cadena::cadena(const char p[]) {
	ini = new char();
	tamany = 0;
	while (p[tamany] != 0) {
		*(ini + tamany) = p[tamany];	
		tamany++;
	}
}

cadena::cadena(const cadena & p) {
	ini = new char();
	tamany = 0;
	while (tamany < p.tamany) {
		*(ini + tamany) = *(p.ini + tamany);
		++tamany;
	}
}

cadena cadena::operator+(cadena & p) {
	 cadena ret(*this);
	 int itRet = ret.tamany;
	 int itp = 0;
	 ret.tamany = ret.tamany + p.tamany;
	 while (itRet < ret.tamany) {
		 *(ret.ini + itRet) = *(p.ini + itp);
		 ++itp;
		 ++itRet;
	 }
	 return ret;
}

cadena cadena::operator=(cadena & p) {
	tamany = 0;
	while (tamany < p.tamany) {
		*(ini + tamany) = *(p.ini + tamany);
		++tamany;
	}
	return *this;
}

void cadena::printCad() {
	int i = 0;
	while (i < tamany) {
		cout << *(ini + i);
		++i;
	}
	cout << endl;
}

bool cadena::operator==(cadena & p) {
	if (tamany != p.tamany) return false;
	for (int i = 0; i < tamany; ++i) if (*(ini + i) != *(p.ini + i)) return false;
	return true;
}
/*
bool cadena::operator==(char s[]) {

	return (cadena(*this) == cadena(s));
}*/

int cadena::length() {
	return tamany;
}

void cadena::clear() {
	tamany = 0;
}

int main()
{
	/*
	// Classe Vec3
	Vec3 <int> a;
	Vec3 <int> b(0, 1, 0);
	Vec3 <int> d(0, 0, 2);
	Vec3 <int> c(b);

	cout << c.distance_to(b) << endl;
	(b.normal()).printV();
	(b + d).printV();
	
	// classe cadena
	cadena s("hello");
	cadena d(s);	

	cadena h("ola");
	cadena g("no");
	h = g;
	(s + g).printCad();

	cout << (g == h) << "," << (g == s) << endl;

	int f;
	cin >> f;*/
    return 0;
}

/*
en una funcio de cadena, el this que es? perque no puc fer cadena(this) i he de fer cadena(*this)?
no hi ha conflicte de memoria amb el que hem fet?

*/
