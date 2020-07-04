#include "gtest/gtest.h"
#include "/Users/gabeiglio/Desktop/Developer/Mar/src/Lexer/Lexer.hpp"
#include "/Users/gabeiglio/Desktop/Developer/Mar/src/Lexer/Token.hpp"

#include <iostream>

TEST(LexerTest, tokens) {
    //Test code
     char*  code = "var age int = 19";

    //Init lexer and tokenize
    Lexer lex(code);
    std::vector<Token> tokens = lex.tokenize();

    //std::cout << &tokens << std::endl;

    //Exptexted output
    std::vector<Token> expected = {Token{TokenType::varKey, "var"}, Token{TokenType::identifier, "age"},
                                    Token{TokenType::intType, "int"}, Token{TokenType::equal, "="},
                                    Token{TokenType::intLiteral, "19"}};

    std::cout << "here\n";
    //Assert vector size first
    //EXPECT_TRUE(tokens.size() == expected.size());

    std::cout << "wqwq\n";
    //for (unsigned int i; i < tokens.size(); i++)
    //    EXPECT_TRUE(tokens[i].type == expected[i].type && tokens[i].lexeme == expected[i].lexeme);

}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
