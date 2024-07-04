template<typename C, typename Oper>
void for_all(C& c, Oper op)
{
	for(auto& x : c)
		op(x);
}

void user2();
