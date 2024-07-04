template<typename T>
class Less_than {
	const T val;
public:
	Less_than(const T& v) :val{v} {}
	bool operator()(const T& x) const { return x<val; }
};
