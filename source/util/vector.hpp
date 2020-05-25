#pragma once

#include <framework_fengine.h>

#pragma warning( disable : 4251 )
namespace fe
{
	template<typename T>
	struct API_DECLSPEC Vector3D
	{
		T	x;
		T	y;
		T	z;
		Vector3D() :x(0), y(0), z(0) {}
		~Vector3D() {}
		Vector3D(T vx, T vy, T vz) :x(vx), y(vy), z(vz) {}
		Vector3D(const Vector3D<T>& v) : x(v.x), y(v.y), z(v.z) {}
		Vector3D(const Vector3D<T>&& v) : x(v.x), y(v.y), z(v.z) {}
		Vector3D(const Vector3D<T>* v) : Vector3D(*v) {}
		Vector3D& operator=(const Vector3D& v) { x = v.x; y = v.y; z = v.z; return this; }
	};

	template<typename T>
	struct API_DECLSPEC Vector2D
	{
		T	x;
		T	y;
		Vector2D() :x(0), y(0) {}
		~Vector2D() {}
		Vector2D(T vx, T vy, T vz) :x(vx), y(vy) {}
		Vector2D(const Vector3D<T>& v) : x(v.x), y(v.y) {}
		Vector2D(const Vector3D<T>&& v) : x(v.x), y(v.y) {}
		Vector2D(const Vector3D<T>* v) : Vector2D(*v) {}
		Vector2D& operator=(const Vector2D& v) { x = v.x; y = v.y; return this; }
	};
}
#pragma warning( default : 4251 )
