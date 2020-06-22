//
//  Parser.cpp
//  Mar
//
//  Created by Gabriel Igliozzi on 11/14/19.
//  Copyright © 2019 Gabriel Igliozzi. All rights reserved.
//

#include "Parser.hpp"

std::vector<std::unique_ptr<Node>> Parser::parse() {
    std::vector<std::unique_ptr<Node>> nodes;
    
    while (index < tokens.size()) {
        switch (tokens[index].type) {
            case TokenType::varKey: nodes.push_back(parseVariableDecl()); break;
            case TokenType::constKey: nodes.push_back(parseConstDecl()); break;
            case TokenType::funcKey: nodes.push_back(parseFuncDecl()); break;
            case TokenType::classKey: nodes.push_back(parseClassDecl()); break;
            case TokenType::whileKey: nodes.push_back(parseWhileStmt()); break;
            case TokenType::ifKey: nodes.push_back(parseIfStmt()); break;
            case TokenType::returnKey: nodes.push_back(parseReturnStmt()); break;
			case TokenType::forKey: nodes.push_back(parseForInStmt()); break;
			default: nodes.push_back(parseOrLogicalExpr());
        }
    }
    
    return nodes;
}

//Parse Block
std::unique_ptr<Block> Parser::parseBlock() {
    std::vector<std::unique_ptr<Node>> nodes;
    consume(TokenType::openBrace);
    
    while (tokens[index].type != TokenType::closeBrace) {
        if (tokens[index].type == TokenType::whileKey) nodes.push_back(parseWhileStmt());
        else if (tokens[index].type == TokenType::returnKey) nodes.push_back(parseReturnStmt());
        else if (tokens[index].type == TokenType::ifKey) nodes.push_back(parseIfStmt());
        else if (tokens[index].type == TokenType::forKey) nodes.push_back(parseForInStmt());
        else if (tokens[index].type == TokenType::varKey) nodes.push_back(parseVariableDecl());
        else if (tokens[index].type == TokenType::constKey) nodes.push_back(parseConstDecl());
        else if (tokens[index].type == TokenType::funcKey) nodes.push_back(parseFuncDecl());
        else if (tokens[index].type == TokenType::classKey) nodes.push_back(parseClassDecl());
		else nodes.push_back(parseOrLogicalExpr());
	}
    
    consume(TokenType::closeBrace);
    return std::unique_ptr<Block> { new Block{nodes} };
}

/* ---- MARK: Parsing Declarations ------ */

std::unique_ptr<Decl> Parser::parseVariableDecl() {
    std::unique_ptr<IdentifierExpr> identifier;
    TokenType type;
    
    consume(TokenType::varKey);
    
    //Get identifier
    if (IdentifierExpr* result = dynamic_cast<IdentifierExpr*>(parsePrimaryExpr().get())) {
        std::string str = result->lexeme;
		identifier = std::unique_ptr<IdentifierExpr> {new IdentifierExpr{str}};
    } else throw "[ERROR] Variable declaration must containt a valid identifier";

    //Check for type
	if (index < tokens.size() && (tokens[index].isType() || !tokens[index].isType())) {
		type = tokens[index].type;
        index++;
	} else throw "[ERROR] Variable declaration must containt a valid type";

	//We perform this check in order to know if the variable will be initialized
    if (index < tokens.size() && tokens[index].type == TokenType::equal) {
        consume(TokenType::equal);
        return std::unique_ptr<VarDecl> { new VarDecl{identifier, type, parseOrLogicalExpr()} };
    }
    
    return std::unique_ptr<VarDecl> { new VarDecl{identifier, type, nullptr} };
}

std::unique_ptr<Decl> Parser::parseConstDecl() {
    std::unique_ptr<IdentifierExpr> identifier;
    TokenType type;
    
    consume(TokenType::constKey);
    
    //Get identifier
    if (IdentifierExpr* result = dynamic_cast<IdentifierExpr*>(parsePrimaryExpr().get())) {
        std::string str = result->lexeme;
        identifier = std::unique_ptr<IdentifierExpr> {new IdentifierExpr{str}};
    } else throw "[ERROR] Variable declaration must containt a valid identifier";
   
    //Check for type
    if (index < tokens.size() && (tokens[index].isType() || !tokens[index].isType())) {
		type = tokens[index].type;
        index++;
    } else throw "[ERROR] Variable declaration must containt a valid type";
    
    if (index < tokens.size() && tokens[index].type == TokenType::equal) {
        consume(TokenType::equal);
        return std::unique_ptr<ConstDecl> { new ConstDecl{identifier, type, parseOrLogicalExpr()} };
    }
    
    return std::unique_ptr<ConstDecl> { new ConstDecl{identifier, type, nullptr} };
}

std::unique_ptr<Decl> Parser::parseFuncDecl() {
    
    //Function properties
    std::unique_ptr<IdentifierExpr> identifier;
    std::vector<std::unique_ptr<ParamDecl>> params;
    TokenType type;
    std::unique_ptr<Block> body;
    
    consume(TokenType::funcKey);
    
    //Get identifier
    if (IdentifierExpr* result = dynamic_cast<IdentifierExpr*>(parsePrimaryExpr().get())) {
        std::string str = result->lexeme;
        identifier = std::unique_ptr<IdentifierExpr> { new IdentifierExpr{str} };
    } else throw "[ERROR] Function declaration must containt a valid identifier";
    
    //Get parameter list if there is any
    params = parseParameterList();
        
    //Check if the type is a valid parameter
    //Later this will have to support custom types
    if (tokens[index].isType()) {
        type = tokens[index].type;
        index++;
    } else throw "[ERROR] Function does not return a valid type";
    
    //Get the body of the funciton
    body = parseBlock();
    return std::unique_ptr<FuncDecl> { new FuncDecl{identifier, params, type, body} };
}

std::unique_ptr<Decl> Parser::parseClassDecl() {
    std::unique_ptr<IdentifierExpr> identifier;
    
    //Consume class key
    consume(TokenType::classKey);

    //Get identifier
    if (IdentifierExpr* result = dynamic_cast<IdentifierExpr*>(parsePrimaryExpr().get())) {
        std::string str = result->lexeme;
        identifier = std::unique_ptr<IdentifierExpr> { new IdentifierExpr{str} };
    } else throw "[ERROR] Function declaration must containt a valid identifier";
    
    return std::unique_ptr<ClassDecl> { new ClassDecl{identifier, parseBlock()} };
}

/* ---- MARK: Parsing Statements ------ */

std::unique_ptr<Stmt> Parser::parseReturnStmt() {
    consume(TokenType::returnKey);
    return std::unique_ptr<ReturnStmt> { new ReturnStmt{parseOrLogicalExpr()} };
}

std::unique_ptr<Stmt> Parser::parseWhileStmt() {
    consume(TokenType::whileKey);
    return std::unique_ptr<WhileStmt> { new WhileStmt{parseOrLogicalExpr(), parseBlock()} };
}

std::unique_ptr<Stmt> Parser::parseForInStmt() {
	consume(TokenType::forKey);
	std::unique_ptr<IdentifierExpr> identifier;
	
	//Get identifier
	if (IdentifierExpr* result = dynamic_cast<IdentifierExpr*>(parsePrimaryExpr().get())) {
		std::string str = result->lexeme;
		identifier = std::unique_ptr<IdentifierExpr> { new IdentifierExpr{str} };
	} else throw "[ERROR] For loop must contain a valid identifier";

	consume(TokenType::inKey);

	return std::unique_ptr<ForInStmt> { new ForInStmt{identifier, parsePrimaryExpr(), parseBlock()} };
}

std::unique_ptr<Stmt> Parser::parseIfStmt() {
    consume(TokenType::ifKey);
    return std::unique_ptr<IfStmt> { new IfStmt{parseOrLogicalExpr(), parseBlock()} };
}

std::unique_ptr<Stmt> Parser::parseExprStmt() {
    return std::unique_ptr<ExprStmt> { new ExprStmt {parseOrLogicalExpr()} };
}

/* ---- MARK: Parsing Expressions ----- */

std::unique_ptr<Expr> Parser::parseOrLogicalExpr() {
    std::unique_ptr<Expr> rhs = parseAndLogicalExpr();
    
    if (tokens[index].type == TokenType::orOperator) {
        TokenType type = tokens[index].type;
        index++;
        return std::unique_ptr<Expr> { new BinaryOpExpr {rhs, parseOrLogicalExpr(), type} };
    }
    
    return rhs;
}

std::unique_ptr<Expr> Parser::parseAndLogicalExpr() {
    std::unique_ptr<Expr> rhs = parseRelationalExpr();
    
    if (tokens[index].type == TokenType::andOperator) {
        TokenType type = tokens[index].type;
        index++;
        return std::unique_ptr<Expr> { new BinaryOpExpr {rhs, parseAndLogicalExpr(), type} };
    }
    
    return rhs;
}

std::unique_ptr<Expr> Parser::parseRelationalExpr() {
    std::unique_ptr<Expr> rhs = parseSumExpr();
    
    if (tokens[index].type == TokenType::doubleEqual || tokens[index].type == TokenType::notEqual || tokens[index].type == TokenType::leftEqual
        || tokens[index].type == TokenType::rightEqual || tokens[index].type == TokenType::arrowLeft || tokens[index].type == TokenType::arrowRight) {
        TokenType type = tokens[index].type;
        index++;
        return std::unique_ptr<Expr> { new BinaryOpExpr {rhs, parseRelationalExpr(), type} };
    }
    
    return rhs;
}

std::unique_ptr<Expr> Parser::parseSumExpr() {
    std::unique_ptr<Expr> rhs = parseTermExpr();
    
    if (tokens[index].type == TokenType::plus || tokens[index].type == TokenType::hyphen) {
        TokenType type = tokens[index].type;
        index++;
        return std::unique_ptr<Expr> { new BinaryOpExpr {rhs, parseSumExpr(), type} };
    }
    
    return rhs;
}

std::unique_ptr<Expr> Parser::parseTermExpr() {
    std::unique_ptr<Expr> rhs = parseUnaryExpr();
    
    if (tokens[index].type == TokenType::star || tokens[index].type == TokenType::slash || tokens[index].type == TokenType::mod) {
        TokenType type = tokens[index].type;
        index++;
        return std::unique_ptr<Expr> { new BinaryOpExpr {rhs, parseTermExpr(), type} };
    }
    
    return rhs;
}

std::unique_ptr<Expr> Parser::parseUnaryExpr() {
    if (tokens[index].type == TokenType::hyphen || tokens[index].type == TokenType::notOperator) {
        index++;
        return std::unique_ptr<UnaryExpr> { new UnaryExpr{tokens[index - 1].type, parsePrimaryExpr()} };
    }
    
    return parseCallOrAssignmentExpr();
}

std::unique_ptr<Expr> Parser::parseCallOrAssignmentExpr() {
    std::unique_ptr<Expr> identifier = parsePrimaryExpr();
    
    //Perform check to know for sure is an identifier, if not then is an error
    if (IdentifierExpr* result = dynamic_cast<IdentifierExpr*>(identifier.get())) {
        
        //Argument list
        if (tokens[index].type == TokenType::openParen) {
            return std::unique_ptr<CallExpr> { 
                new CallExpr{std::unique_ptr<IdentifierExpr> { new IdentifierExpr {result->lexeme}}, parseArgumentList()} };
        }
        
        //Assigment expr
        if (tokens[index].type == TokenType::equal) {
            consume(TokenType::equal);
            std::unique_ptr<IdentifierExpr> name = std::unique_ptr<IdentifierExpr> { new IdentifierExpr{result->lexeme} };
            return std::unique_ptr<AssignExpr> { new AssignExpr{name, parseOrLogicalExpr()} };
        }
    }
    
    return identifier;
}

std::unique_ptr<Expr> Parser::parsePrimaryExpr() {

    //First we want to know if there are any available
    if (index >= tokens.size()) throw "[ERROR] Unexpexted " + tokens[--index].lexeme;

    switch (tokens[index].type) {
        case TokenType::identifier: index++; return std::unique_ptr<IdentifierExpr> { new IdentifierExpr {tokens[index - 1].lexeme} };
        case TokenType::intLiteral: index++; return std::unique_ptr<IntegerExpr> { new IntegerExpr {stoi(tokens[index - 1].lexeme)} };
        case TokenType::doubleLiteral: index++; return std::unique_ptr<DoubleExpr> { new DoubleExpr {stod(tokens[index - 1].lexeme)} };
        case TokenType::boolLiteral: index++; return std::unique_ptr<BoolExpr> { new BoolExpr { tokens[index - 1].lexeme == "true"}};
        case TokenType::charLiteral: index++; return std::unique_ptr<CharExpr> { new CharExpr { tokens[index - 1].lexeme[0] }};
        case TokenType::stringLiteral: index++; return std::unique_ptr<StringExpr> { new StringExpr { tokens[index - 1].lexeme }};
        case TokenType::nilLiteral: index++; return nullptr;
        default: throw "[ERROR] Token '" + tokens[index].lexeme + "' not found";
    }
}

/* ---- MARK: Helper functions ----- */

void Parser::consume(TokenType type) {
    if (tokens[index].type != type)
        throw "[ERROR] Unexpected token '" + tokens[index].lexeme + "' at line: ";
    index++;
}

std::vector<std::unique_ptr<Expr>> Parser::parseArgumentList() {
    std::vector<std::unique_ptr<Expr>> args;
    
    consume(TokenType::openParen);
    while (tokens[index].type != TokenType::closeParen) {
        args.push_back(parseOrLogicalExpr());
        
        if (tokens[index].type != TokenType::closeParen)
            consume(TokenType::comma);
    }
    consume(TokenType::closeParen);
    
    return args;
}

std::vector<std::unique_ptr<ParamDecl>> Parser::parseParameterList() {
    std::vector<std::unique_ptr<ParamDecl>> params;
    
    consume(TokenType::openParen);
    while (tokens[index].type != TokenType::closeParen) {
        std::unique_ptr<IdentifierExpr> identifier;
        TokenType type;
        
        if (tokens[index].type == TokenType::identifier) {
            identifier = std::unique_ptr<IdentifierExpr> {new IdentifierExpr{tokens[index].lexeme} };
            index++;
        } else throw "[ERROR] Parameter list contains an invalid parameter";
        
        if (tokens[index].isType()) {
            type = tokens[index].type;
            index++;
        } else throw "[ERROR] Parameter list contains an invalid parameter";
        
        if (tokens[index].type != TokenType::closeParen)
            consume(TokenType::comma);
        
        params.push_back(std::unique_ptr<ParamDecl> { new ParamDecl {identifier, type} });
    }
    consume(TokenType::closeParen);
    
    return params;
}
