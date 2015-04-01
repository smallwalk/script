#include <stdio.h>
int main()
{
	//从右至左念 str is a point to const char（指向常量的指针）
	const char *str = "Hello";
	str = "YOU"; //合法	
	printf("%s\n", str);


	//str is a const point to char （指向char类型的常量指针，不可另外赋值）
	char *const p = "Hello";
	//p = "YOU"; point.c:8:6: error: read-only variable is not assignable
	printf("%s\n", p);
	return 0;
}
