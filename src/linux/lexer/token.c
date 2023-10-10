#include <stdio.h>

#include "../compiler/comet.h"
#include "token.h"

const char *get_token_type(TokenType type) {
  switch (type) {
  case LEFT_PAREN:
    return "Left Paren";
    break;
  case RIGHT_PAREN:
    return "Right Paren";
    break;
  case LEFT_BRACKET:
    return "Left Bracket";
    break;
  case RIGHT_BRACKET:
    return "Right Bracket";
    break;
  case LEFT_BRACE:
    return "Left Brace";
    break;
  case RIGHT_BRACE:
    return "Right Brace";
    break;
  case LEFT_ANGLE:
    return "Left Angle";
    break;
  case RIGHT_ANGLE:
    return "Right Angle";
    break;
  case PIPE:
    return "Pipe";
    break;
  case BANG:
    return "Bang";
    break;
  case ASSIGN:
    return "Assign";
    break;
  case COMMA:
    return "Comma";
    break;
  case DOT:
    return "Dot";
    break;
  case TACK:
    return "Tack";
    break;
  case PLUS:
    return "Plus";
    break;
  case SEMICOLON:
    return "Semicolon";
    break;
  case FORWARD_SLASH:
    return "Forward Slash";
    break;
  case ASTERISK:
    return "Asterisk";
    break;
  case BACKWARD_SLASH:
    return "Backward Slash";
    break;
  case AMPERSAND:
    return "Ampersand";
    break;
  case GREATER:
    return "Greater";
    break;
  case LESSER:
    return "Lesser";
    break;
  case QUESTION_MARK:
    return "Question Mark";
    break;
  case UNDERSCORE:
    return "Underscore";
    break;
  case COLON:
    return "Colon";
    break;
  case BIT_OR:
    return "Bit Or";
    break;
  case BIT_AND:
    return "Bit And";
    break;
  case BANG_EQUAL:
    return "Bang Equal";
    break;
  case EQUAL:
    return "Equal";
    break;
  case GREATER_EQUAL:
    return "Greater Equal";
    break;
  case LESSER_EQUAL:
    return "Lesser Equal";
    break;
  case DOUBLE_PIPE:
    return "Double Pipe";
    break;
  case DOUBLE_AMP:
    return "Double Amp";
    break;
  case IDENTIFIER:
    return "Identifier";
    break;
  case STRING:
    return "String";
    break;
  case CHAR:
    return "Char";
    break;
  case NUM:
    return "Num";
    break;
  case IDENT:
    return "Ident";
    break;
  case IF:
    return "If";
    break;
  case FOR:
    return "For";
    break;
  case ELSE:
    return "Else";
    break;
  case FN:
    return "Function";
    break;
  case RETURN:
    return "Return";
    break;
  case THIS:
    return "This";
    break;
  case WHILE:
    return "While";
    break;
  case TRUE:
    return "True";
    break;
  case FALSE:
    return "False";
    break;
  case MATCH:
    return "Match";
    break;
  case STRUCT:
    return "Struct";
    break;
  case ENUM:
    return "Enum";
    break;
  case MOD:
    return "Mod";
    break;
  case ENOF:
    return "Enof";
    break;
  }

  return "Unexpected";
}

void report(int line_num, char *where, char *message, Comet *comet) {
  printf("[line %d ] Error %s: %s\n", line_num, where, message);
  comet->had_error = true;
}

void error(int line_num, char *message, Comet *comet) {
  report(line_num, "", message, comet);
}
