cmake_minimum_required(VERSION 3.0)

#Specify C++ version
set (CMAKE_CXX_STANDARD 17)

project(Mar)

#path variables
set(LEXER_DIR Lexer)
set(PARSER_DIR Parser)
set(EVAL_DIR Evaluator)

add_executable( 
		Mar
		main.cpp
		${LEXER_DIR}/Lexer.cpp
		${LEXER_DIR}/Token.hpp
		${PARSER_DIR}/Parser.cpp
		${PARSER_DIR}/Nodes/Expr.hpp
 		${PARSER_DIR}/Nodes/Stmt.hpp
		${PARSER_DIR}/Nodes/Decl.hpp
	 	${EVAL_DIR}/Evaluator.cpp
)
		
