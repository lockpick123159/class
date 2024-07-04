#include <iostream>
template<typename T>
class Vector2 {
public:
	using value_type = T;

	Vector2(std::initializer_list<T>);

	template<typename Iter>
		Vector2(Iter b, Iter e);
};

template <typename Iter>
	Vector2(Iter, Iter) -> Vector2<typename Iter::value_type>;
