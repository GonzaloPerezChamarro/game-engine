#pragma once


#include <string>


using std::string;
namespace imeng
{

	class Variant
	{
	public:

		Variant():type(NONE) {}
		Variant(bool b) :type(BOOL) { data.b_value = b; }
		Variant(int i) :type(BOOL) { data.n_value = i; }
		Variant(float f) :type(BOOL) { data.f_value = f; }
		Variant(string s) :type(BOOL) { data.s_value = new string(s); }

		~Variant() 
		{ 
			if (type == STRING) 
				delete data.s_value; 

			type = NONE;
		}

	private:

		union Data
		{
			bool b_value;
			int n_value;
			float f_value;
			string * s_value;
		}data;

		enum Type
		{
			BOOL = 0, 
			INT = 1,
			FLOAT = 2,
			STRING = 3,
			NONE = 4
		}type;

	};
}