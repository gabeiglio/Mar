cmake_minimum_required(VERSION 3.0)
project(mar)

#Specify C++ version
set (CMAKE_CXX_STANDARD 17)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})


#path variables
set(LEXER_DIR Lexer)
set(PARSER_DIR Parser)
set(EVAL_DIR Evaluator)
set(SEMA_DIR Sema)
set(CODEGEN_DIR Codegen)

#Build
add_executable( 
		mar
		main.cpp
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
        ${CODEGEN_DIR}/Codegen.cpp
)

#use libraries that we want tu use for the project
llvm_map_components_to_libnames(llvm_libs native)

#link against LLVM libraries
target_link_libraries(mar ${llvm_libs})
