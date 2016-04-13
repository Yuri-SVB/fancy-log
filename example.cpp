/*
 * example.cpp
 *
 *  Created on: Apr 12, 2016
 *      Author: yuri
 *
 *  This program is a simple example of fancy log put into action.
 * by running it with the compilation directives activated, it outputs
 * a string that if saved and automatically indented (in your favorit IDE), will
 * provide you with an acruate view of the program flow and function nesting.
 *
 */

#include <iostream>
#include <string>

#include "ysvb_fancy_log.hpp"

YSVB_FLOG(int, fibonachi(int nest), true)	//simple recursion example
//{
	int ret;
	YSVB_IF((nest == 0 || nest == 1), true)
		ret = 1;
	YSVB_ELSE
		ret = fibonachi(nest-1) + fibonachi(nest-2);
	YSVB_FI
	YSVB_FL_RET_P(ret);
YSVB_FLOG_END//}

int main ()
{
	int N = 10;
	std::cout << "The " << N << "th fibonachi number is " << fibonachi(N) << "." << std::endl;
	return 0;
}
