set(BINARY ${CMAKE_PROJECT_NAME})
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.hpp *.cpp)
set(SOURCES ${SOURCES})

#path variables           
#set(LEXER_DIR Lexer)
#set(PARSER_DIR Parser)
#set(EVAL_DIR Evaluator)
#set(SEMA_DIR Sema)

#Build
#add_executable( 
#		mar
#		main.cpp
#		${LEXER_DIR}/Lexer.cpp
#		${LEXER_DIR}/Token.hpp
#		${PARSER_DIR}/Parser.cpp
#		${PARSER_DIR}/Nodes/Expr.hpp
#		${PARSER_DIR}/Nodes/Stmt.hpp
#		${PARSER_DIR}/Nodes/Decl.hpp
#	 	${EVAL_DIR}/ASTVisualizer.cpp
#       ${EVAL_DIR}/Visitor/Visitor.hpp
#       ${SEMA_DIR}/SemanticAnalyzer.cpp
#		${SEMA_DIR}/SymbolTable/SymbolTable.cpp
#)
add_executable(${BINARY}_run ${SOURCES})
add_library(${BINARY}_lib STATIC ${SOURCES})
