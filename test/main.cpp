#include "gtest/gtest.h"
#include "Lexer/Lexer.hpp"
#include "Lexer/Token.hpp"

TEST(LexerTest, tokens) {
    //Test code
     char*  code = "var age int = 19";

    //Init lexer and tokenize
    Lexer lex(code);
    std::vector<Token> tokens = lex.tokenize();

    //Exptexted output
    std::vector<Token> expected = {Token{TokenType::varKey, "var"}, Token{TokenType::identifier, "age"},
                                    Token{TokenType::intType, "int"}, Token{TokenType::equal, "="},
                                    Token{TokenType::intLiteral, "19"}};

    //Assert vector size first
    EXPECT_TRUE(tokens.size() == expected.size());

    for (unsigned int i; i < tokens.size(); i++)
        EXPECT_TRUE(tokens[i].type == expected[i].type && tokens[i].lexeme == expected[i].lexeme);

}

TEST(LexerTest, constTokens) {
    
    //Test code
    char* code = "const isBool bool = false";

    //Init Lexer and tokenize
    Lexer lex(code);
    std::vector<Token> tokens = lex.tokenize();

    //Expected output
    std::vector<Token> expected = {Token{TokenType::constKey, "const"},Token{TokenType::identifier, "isBool"}, 
        Token{TokenType::boolType, "bool"}, Token{TokenType::equal, "="}, Token{TokenType::boolLiteral, "false"}};

    //Assert vectors size first
    EXPECT_TRUE(tokens.size() == expected.size());

    //Compare types and lexemes
    for (unsigned int i; i < tokens.size(); i++)
        EXPECT_TRUE(tokens[i].type == expected[i].type && tokens[i].lexeme == expected[i].lexeme);
        
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
