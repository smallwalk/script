template <class AssociativeContainer>
class T : public P {
	
	public:
	 	T(AssociativeContainer& container) : m_var(container) {}

	private:
		AssociativeContainer &my_var;
}

int main() 
{
	
}
