#include "framework_fressource.h"

#pragma warning( disable : 4251 )
namespace fe
{
	template<typename T>
	struct API_DECLSPEC Vector3D
	{
		T	x;
		T	y;
		T	z;
		Vector3D() :x(), y(), z() {}
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
		Vector3D() :x(), y() {}
		~Vector3D() {}
		Vector3D(T vx, T vy, T vz) :x(vx), y(vy) {}
		Vector3D(const Vector3D<T>& v) : x(v.x), y(v.y) {}
		Vector3D(const Vector3D<T>&& v) : x(v.x), y(v.y) {}
		Vector3D(const Vector3D<T>* v) : Vector3D(*v) {}
		Vector3D& operator=(const Vector3D& v) { x = v.x; y = v.y; return this; }
	};
}
#pragma warning( default : 4251 )