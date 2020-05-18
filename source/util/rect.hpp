#include "framework_fengine.h"

#pragma warning( disable : 4251 )
namespace fe
{
	template<typename T>
	struct API_DECLSPEC Rect
	{
		T	top = 0;
		T	bottom = 0;
		T	left = 0;
		T	right = 0;

		Rect(T t, T b, T l, T r) : top(t), bottom(b), left(l), right(r) {}
		Rect(const Rect* o) : Rect(*o) {}
		Rect() = default;
		Rect(const Rect&) = default;
		Rect(Rect&&) noexcept = default;
		Rect& operator=(const Rect&) = default;
		Rect& operator=(Rect&&) = default;
		virtual ~Rect() = default;
	};
}
#pragma warning( default : 4251 )
