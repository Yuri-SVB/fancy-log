/*
 * fancy_cout.hpp
 *
 *  Created on: Mar 27, 2015
 *      Author: yuri
 */

#if !defined(FANCY_COUT_HPP_)
#include <string>
#include "help.hpp"

#define FANCY_COUT_HPP_
 
#define YSVB_TITLE_1(X) std::cout<<"============"<<#X<<"============"<<std::endl<<std::endl<<std::endl;

#define YSVB_TITLE_2(X) std::cout<<"========="<<#X<<"========="<<std::endl<<std::endl;

#define YSVB_TITLE_3(X) std::cout<<"==="<<#X<<"==="<<std::endl;

#if 0	//old way
#if defined(__FLOG__)
//	#define YSVB_FLOG(X) X{if(){std::cout<<#X<<"	at	"<<__FILE__<<"	line	"<<__LINE__<<std::endl;}
 	#define YSVB_FLOG_INDENT(B,X)	if(B){std::cout<<__FILE__<<"\t"<<__LINE__<<"\t"<<#X<<std::endl<<(#X);}
 	#define YSVB_FLOG(X,B)			X{const bool YSVB_FL_FLAG=B;YSVB_FLOG_INDENT_P(YSVB_FL_FLAG)
#else
 	#define YSVB_FLOG_INDENT(B,X)	
	#define YSVB_FLOG(X,B)			X{
#endif
#endif

#if defined(__FLOG__)
		 	#define YSVB_FLOG_INDENT(L,X)		if(L){std::cout<<__FILE__<<" "<<__LINE__<<" "<<X; YSVB_FL_INDENTATION_COUNTER++;}
		 	#define YSVB_FLOG_INDENT_I(L,X)		if(L){std::cout<<(X)<<" "<<__FILE__<<" "<<__LINE__ << "\n";}
 	#define YSVB_FLOG(T,X,L)		T X\
									{\
										/*T YSVB_FL_ret;*/\
										const bool YSVB_FL_FLAG=L;\
										int YSVB_FL_INDENTATION_COUNTER = 0;\
										std::string YSVB_FL_STR_FUN = (std::string(#T) + " " + #X);\
										YSVB_FLOG_INDENT_P
 	#define V_YSVB_FLOG(X,L)		void X\
									{\
										std::string YSVB_FL_STR_FUN = (std::string("void ") + #X);\
										const bool YSVB_FL_FLAG=L;\
										int YSVB_FL_INDENTATION_COUNTER = 0;\
										YSVB_FLOG_INDENT_P
 	#define C_YSVB_FLOG(C,L)		C\
									{\
										std::string YSVB_FL_STR_FUN(#C);\
										const bool YSVB_FL_FLAG=L;\
										int YSVB_FL_INDENTATION_COUNTER = 0;\
										YSVB_FLOG_INDENT_P
	#define YSVB_FL_RET(X)			/*YSVB_FL_ret = X;*/	YSVB_FLOG_INDENT_M	return(X/*YSVB_FL_ret*/);
	#define YSVB_FL_RET_P(X)		YSVB_SHOW(X)	YSVB_FL_RET(X)
#else
 	#define YSVB_FLOG_INDENT(L,X)		
 	#define YSVB_FLOG_INDENT_I(B,X)		
	#define YSVB_FLOG(T,X,B)		T X{
 	#define V_YSVB_FLOG(X,L)		void X{
 	#define C_YSVB_FLOG(C,L)		C{
	#define YSVB_FL_RET(X)			return(X);
	#define YSVB_FL_RET_P(X)		YSVB_SHOW(X)	return(X);
#endif

#define YSVB_FL_RET_V(X)		YSVB_FLOG_INDENT_M	return(X);
#define YSVB_FL_RET_P_V(X)		YSVB_SHOW(X)	YSVB_FL_RET_V(X)

#if defined(__FLOG__)
	#define YSVB_IF(B,L)			{\
										const bool YSVB_B_IF = (B);\
										const std::string YSVB_IF_B_STRING(#B);\
										const bool YSVB_FL_FLAG=L;\
										if (YSVB_B_IF)\
										{\
											std::string YSVB_FL_STR_FUN = (L)?(std::string("if ( ") + #B + " )	" + #B + " = " + (	(B)?"TRUE":"FALSE"	)	):("");\
											YSVB_FLOG_INDENT_P
	#define YSVB_FI					YSVB_FLOG_END}
	#define YSVB_ELSE					YSVB_FLOG_END\
									else {\
										std::string YSVB_FL_STR_FUN = (YSVB_FL_FLAG)?("else ( " + YSVB_IF_B_STRING + " )	" + YSVB_IF_B_STRING + " = " + (	(YSVB_B_IF)?"TRUE":"FALSE"	)	):("");\
										YSVB_FLOG_INDENT_P
	#define YSVB_FOR(A, B, C, L)	{\
										const bool YSVB_FL_FLAG = L;\
										for(A; B; C)\
											{\
											if (L) {}
#else
	#define YSVB_IF(B,L)			if (B)	{
	#define YSVB_ELSE				} else {
	#define YSVB_FI					}
#endif
	#define YSVB_FLOG_INDENT_P			YSVB_FLOG_INDENT(YSVB_FL_FLAG,YSVB_FL_STR_FUN + "{\n")\
											YSVB_CHECK_1(YSVB_FL_INDENTATION_COUNTER, >=, 0, "Indentation is non-negative.")\
											YSVB_FL_INDENTATION_COUNTER++;

	#define	YSVB_FLOG_INDENT_GP(S)		YSVB_FLOG_INDENT(YSVB_FL_FLAG, std::string(S) + "{\n")\
											YSVB_CHECK_1(YSVB_FL_INDENTATION_COUNTER, >=, 0, "Indentation is non-negative.")\
											YSVB_FL_INDENTATION_COUNTER++;

	#define YSVB_FLOG_INDENT_M			YSVB_FLOG_INDENT_I(YSVB_FL_FLAG,"}	\\\\" + YSVB_FL_STR_FUN)\
											YSVB_CHECK_1(YSVB_FL_INDENTATION_COUNTER, >=, 1, "Indentation is non-negative.")\
											YSVB_FL_INDENTATION_COUNTER--;

	#define	YSVB_FLOG_INDENT_GM(S)		YSVB_FLOG_INDENT_I(YSVB_FL_FLAG,"}	\\\\" + std::string(S))\
											YSVB_CHECK_1(YSVB_FL_INDENTATION_COUNTER, >=, 1, "Indentation is non-negative.")\
											YSVB_FL_INDENTATION_COUNTER--;

#define		YSVB_FLOG_END				YSVB_FLOG_INDENT_M}



#define YSVB_FL_DEVELOPMENT_UNUSEFUL_BRACKETS	}}}}}}}}}
// #define YSVB_FLOG_END }

#if defined(__DBG__)
	#define YSVB_SWITCH(T,X,L)	{\
									std::stringstream YSVB_SWITCH_INNER_STRING_STREAM_OF_X;\
									YSVB_SWITCH_INNER_STRING_STREAM_OF_X << X;\
									std::string YSVB_SWITCH_INNER_STRING_OF_X = YSVB_SWITCH_INNER_STRING_STREAM_OF_X.str();\
									YSVB_FLOG_INDENT_GP(std::string("switch(") + #X + ") such that " + #X + " = " + YSVB_SWITCH_INNER_STRING_OF_X)\
									T YSVB_SWITCH_LOG_HANDLER_VARIABLE = X;\
									switch(X){
	#define YSVB_CASE(X)		case (X):\
									YSVB_FLOG_INDENT_GP(std::string("case X = ") + #X + " = " + YSVB_SWITCH_INNER_STRING_OF_X + " :")
	#define YSVB_CASE_END		YSVB_FLOG_INDENT_GM(std::string("case X = ") + YSVB_SWITCH_INNER_STRING_OF_X + ".")\
									break;
	#define YSVB_DEFAULT		default:\
									YSVB_FLOG_INDENT_GP(std::string("default X = ") + YSVB_SWITCH_INNER_STRING_OF_X + " :")
	#define YSVB_DEFAULT_END	YSVB_FLOG_INDENT_GM(std::string("default X = ") + YSVB_SWITCH_INNER_STRING_OF_X + " :")\
									break;
	#define YSVB_END_SWITCH		}YSVB_FLOG_INDENT_GM(std::string("switch(X)") + " = " + YSVB_SWITCH_INNER_STRING_OF_X)}
#else
	#define YSVB_SWITCH(X,L)	switch (X) {
	#define CASE(X)				case (X):
	#define YSVB_CASE_END		break;
	#define DEFAULT				default:
	#define YSVB_DEFAULT_END	break;
	#define YSVB_END_SWITCH		}
#endif

#endif /* FANCY_COUT_HPP_ */
