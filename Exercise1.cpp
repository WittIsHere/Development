#define CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

template<typename T>

// Aram Galarza

class vec3
{

public:

	// Constructors

	vec3() : x(0), y(0), z(0) {}

	vec3(T x0, T y0, T z0) : x(x0), y(y0), z(z0) {}

	vec3(const vec3 &v)  {
	
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
	}


	~vec3() {}

	// Operators

	T operator+(const vec3 &a) const
	{
		this->x = this->x + a.x;
		this->y = this->y + a.y;
		this->z = this->z + a.z;
		
	}

	T operator-(const vec3& a) const
	{
		this->x = this->x - a.x;
		this->y = this->y - a.y;
		this->z = this->z - a.z;

	}

	T operator+=(const vec3& a) const
	{
		this->x = this->x += a.x;
		this->y = this->y += a.y;
		this->z = this->z += a.z;

	}

	T operator=(const vec3& a) const
	{
		this->x = a.x;
		this->y = a.y;
		this->z = a.z;

	}

	bool operator==(const vec3& a) const
	{
		if (this->x == a.x && this->y == a.y)
		{
			if (this->z == a.z)
			{
				return 1;
			}
		}
		else
			return 0;
	}
	
	
	// -Methods-
	

	void Normalize()
	{
		T a = (this->x ^ 2) + (this->y ^ 2) + (this->z ^ 2);
		T lenght = pow(a, 0.5);
		this->x = this->x / lenght;
		this->y = this->y / lenght;
		this->z = this->z / lenght;

	}

	void Zero()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	bool isZero() const
	{
		T a = 0;
		a = (this->x + this->y + this->z);
		if (a == 0)
			return 1;
		else
			return 0;
	}

	T DistanceTo(vec3 u)
	{
		T aix = (u.x - x);
		aix = aix * aix;
		T aiy = (u.y - y);
		aiy = aiy * aiy;
		T aiz = (u.z - z);
		aiz = aiz * aiz;

		T total = aix + aiy + aiz;
		return sqrt(total);
	}

private:
	
	T x;
	T y;
	T z;


};

int main()
{
	//vec3<int> test;

	vec3<int> v = { 1,2,3 };
	
	vec3<int> u = { 3,3,4 };

	printf("\n The distance between v and u is: %d", v.DistanceTo(u));

	if (v == u)
	{
		printf("\n Vecs are equal");
	}
	else
		printf("\n Vecs are not equal");

	u.Zero();
	v.Zero();

	if (v == u)
	{
		printf("\n Vecs are equal");
	}
	else
		printf("\n Vecs are not equal");

	printf("\n ");
	system("pause");
	return 0;
}