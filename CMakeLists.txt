cmake_minimum_required(VERSION 3.0)
project(mar)

#Specify version of c++
set(CMAKE_CXX_STANDARD 17)

#path variables           
set(LEXER_DIR src/Lexer)
set(PARSER_DIR src/Parser)
set(EVAL_DIR src/Evaluator)
set(SEMA_DIR src/Sema)

#Build
add_executable( 
		mar
		src/main.cpp
		${LEXER_DIR}/Lexer.cpp
		${LEXER_DIR}/Token.hpp
		${PARSER_DIR}/Parser.cpp
		${PARSER_DIR}/Nodes/Expr.hpp
 		${PARSER_DIR}/Nodes/Stmt.hpp
		${PARSER_DIR}/Nodes/Decl.hpp
	 	${EVAL_DIR}/ASTVisualizer.cpp
        ${EVAL_DIR}/Visitor/Visitor.hpp
        ${SEMA_DIR}/SemanticAnalyzer.cpp
		${SEMA_DIR}/SymbolTable/SymbolTable.cpp
)


# If we ommit it, then the test
# will not be able to find header files
#include_directories(Source)

#Add subdirectories
#add_subdirectory(Source)
#add_subdirectory(Test)
#add_subdirectory(Lib/googletest)
