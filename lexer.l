%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	int ErrFlag = 0;
	#include "symbol_table.h"
    #include "y.tab.h"

	//void yyerror(char *s);
	//int yylex(void);
	extern int yylineno;

	//Count the columns
	extern int yyleng;
    extern int columnNo = 0;

	extern symtab_t* SymbolTable;
	//scope for indicating the scope of the variable
	extern int scope = 0; 

	
%}

alpha [A-Za-z]
digit [0-9]
digits {digit}+
fraction 	(\.{digits})?
exponent 	([Ee][+-]?{digits})?
number 		{digits}{fraction}{exponent}
dec 		([+-]?({digit}*)["."]({digit}+))|([+-]?({digit}+)["."]({digit}*))
whitespace [ \t\r\f\v]+
char '\.\'
space [ ]
tab ['\t']
line ['\n']
string \"(.^([%d]|[%f]|[%s]|[%c]))\"
identifier (_|{alpha})({alpha}|{digit}|_)*
input_output ("printf"|"scanf"|"fprintf"|"fscanf"|"getc"|"putc"|"fgetc"|"fputc")

/* States */
%x PREPROCESSOR
%x MLCOMMENT
%x SLCOMMENT
%%

int 		{ 
			  printf("<keyword, %s>\n", yytext);
			  columnNo += yyleng;
			  return T_INT;
			}
short 		{ 
			  printf("<keyword, %s>\n", yytext);
			  columnNo += yyleng;
			  return T_SHORT;
			}
long 		{ 
			  printf("<keyword, %s>\n", yytext);
			  columnNo += yyleng;
			  return T_LONG;
			}
float 		{ 
			  printf("<keyword, %s>\n", yytext);
			  columnNo += yyleng;
			  return T_FLOAT;
			}
char 		{ 	
				printf("<keyword, %s>\n", yytext);
				columnNo += yyleng;
				return T_CHAR;
			}
double 		{ 
			  printf("<keyword, %s>\n", yytext);
			  columnNo += yyleng;
			  return T_DOUBLE;
			}
void 		{ printf("<keyword, %s>\n", yytext);
			  columnNo += yyleng;
			  return T_VOID;
			}
if 			{ printf("<keyword, %s>\n", yytext);
			  columnNo += yyleng;
			  return T_IF;
			}
else 		{ printf("<keyword, %s>\n", yytext);
			  columnNo += yyleng;
			  return T_ELSE;
			}
while 		{ printf("<keyword, %s>\n", yytext);
			  columnNo += yyleng;
			  return T_WHILE;
			}
break 		{ printf("<keyword, %s>\n", yytext);
			  columnNo += yyleng;
			  return T_BREAK;
			}
return 		{ printf("<keyword, %s>\n", yytext);
			  columnNo += yyleng;
			  return T_RETURN;
			}
main		{ printf("<keyword, %s>\n", yytext);
			  columnNo += yyleng;
			  return T_MAIN;
			}
{input_output}      { //It is a identifier of type builtin function name, it cannot be called as keyword
				columnNo += yyleng;
				return T_IDENTIFIER;
			}

"\t"          {columnNo += 4;}
{whitespace}  {columnNo += yyleng;}

^"#include"  					{BEGIN PREPROCESSOR;}
<PREPROCESSOR>{whitespace} 		;
<PREPROCESSOR>"<"[^<>\n]*">"	{BEGIN INITIAL;}
<PREPROCESSOR>\"[^<>\n]*\"		{BEGIN INITIAL;}
<PREPROCESSOR>"\n"				{ yylineno++; 
								  BEGIN INITIAL;
								  ErrFlag=1;
								  columnNo = 0;	
								}
<PREPROCESSOR>.					{ yyerror("Improper defined Header");}


[0][xX][0-9a-fA-F]+ 							{ //insert(SymbolTable, "T_HEX_CONSTANT", yytext, scope); 
			  									yylval.dval = (int)strtol(yytext, NULL, 16);
												printf("Constant, %lf\n", yylval.dval);
												columnNo += yyleng;
			  									return T_HEX_CONSTANT;
			  									}
[+-]?{digit}+									{ //insert(SymbolTable, "T_INT_CONSTANT", yytext,scope);
			  									yylval.dval = atoi(yytext);
												printf("Constant, %d\n", (int)yylval.dval);
												columnNo += yyleng;
			  									return T_INT_CONSTANT;
			  									}
{dec}											{ //insert(SymbolTable, "T_DEC_CONSTANT", yytext, scope);
			  									yylval.dval = atof(yytext);
												printf("Constant, %lf\n", yylval.dval);
												columnNo += yyleng;
			  									return T_DEC_CONSTANT;
			  									}
({digit}*)["."]?{digits}[eE][+-]?{digits}		{ //insert(SymbolTable, "T_DEC_CONSTANT", yytext, scope);
			  									yylval.dval = atof(yytext);
												printf("Constant, %lf\n", yylval.dval);
												columnNo += yyleng;
			  									return T_DEC_CONSTANT;
			  									}

\"[^\"\n]*$ 			{yyerror("EOF encountered in string.");
						yyterminate();}
\"[^\"\n]*\"			{
						if(yytext[yyleng-2] == '\\'){yyless(yyleng-1);yymore();}
						else{//insert(SymbolTable, "T_STRING", yytext, scope); 
						columnNo += yyleng;
						return T_STRING;
						}
						}
{identifier}	{
					if(strlen(yytext) <= 32)
					{
						insert(SymbolTable, "T_IDENTIFIER", yytext, scope, yylineno, columnNo, columnNo+yyleng);
						yylval.tbEntry = exists(SymbolTable, yytext, scope);
						return T_IDENTIFIER;
					}
					else
					{
						//printf("Error at line %d. Identifier name exceeds limit (length of identifier must be between 1 and 32 characters both inclusive).\n", yylineno);
						yyerror("Identifier name exceeds limit (length of identifier must be between 1 and 32 characters both inclusive).");
						ErrFlag = 1;
					}
					columnNo += yyleng;
				}

"/*"			{BEGIN MLCOMMENT;}
<MLCOMMENT>.		;
<MLCOMMENT>"\n"		{++yylineno;}
<MLCOMMENT><<EOF>>	{yyerror("EOF encountered while parsing multi line comment");
					yyterminate();
					}
<MLCOMMENT>"*/"	{BEGIN INITIAL;}

"//"			{BEGIN SLCOMMENT;}
<SLCOMMENT>.	;
<SLCOMMENT><<EOF>>	{yyerror("EOF encountered while parsing single line comment");
					yyterminate();
					}
<SLCOMMENT>"\n" 	{++yylineno;
				BEGIN INITIAL;}

"+"                                 {printf("< symbol, %s >\n", yytext);
									 columnNo += yyleng;
									return T_ADD;}
"-"                                 {printf("< symbol, %s >\n", yytext);
									 columnNo += yyleng;
									return T_SUBTRACT;}
"*"                                 {printf("< symbol, %s >\n", yytext);
									 columnNo += yyleng;
									return T_MULTIPLY;}
"/"                                 {printf("< symbol, %s >\n", yytext);
									 columnNo += yyleng;
									return T_DIVIDE;}
"%"                                 {printf("< symbol, %s >\n", yytext);
									 columnNo += yyleng;
									return T_MOD;}
"="                                 {printf("< symbol, %s >\n", yytext);
									columnNo += yyleng;
									return T_ASSIGN;}
"--"                                {printf("< symbol, %s >\n", yytext);
									 columnNo += yyleng;
									return T_DECREMENT;}
"++"                                {printf("< symbol, %s >\n", yytext);
									 columnNo += yyleng;
									return T_INCREMENT;}
"+="                                {printf("< symbol, %s >\n", yytext);
								     columnNo += yyleng;
									return T_ADD_ASSIGN;}
"-="                                {printf("< symbol, %s >\n", yytext);
									 columnNo += yyleng;
									return T_SUB_ASSIGN;}
"*="                                {printf("< symbol, %s >\n", yytext);
									 columnNo += yyleng;
									return T_MUL_ASSIGN; }
"/="                                {printf("< symbol, %s >\n", yytext);
									 columnNo += yyleng;
									return T_DIV_ASSIGN;}
"%="                                {printf("< symbol, %s >\n", yytext);
									 columnNo += yyleng;
									return T_MOD_ASSIGN;}

">"                                 {printf("< symbol, %s >\n", yytext);
									 columnNo += yyleng;
									return T_GREATER_THAN;}
"<"                                 {printf("< symbol, %s >\n", yytext);
									 columnNo += yyleng;
									return T_LESSER_THAN;}
">="                                {printf("< symbol, %s >\n", yytext);
								     columnNo += yyleng;
									return T_GREATER_EQ;}
"<="                                {printf("< symbol, %s >\n", yytext);
									 columnNo += yyleng;
									return T_LESSER_EQ;}
"=="                                {printf("< symbol, %s >\n", yytext);
									 columnNo += yyleng;
									return T_EQUAL;}

"||"                                {printf("< symbol, %s >\n", yytext);
									 columnNo += yyleng;
									return T_LG_OR;}
"&&"                                {printf("< symbol, %s >\n", yytext);
									 columnNo += yyleng;
									return T_LG_AND;}
"!"                                 {printf("< symbol, %s >\n", yytext);
									 columnNo += yyleng;
									return T_NOT;}
"!="                                {printf("< symbol, %s >\n", yytext);
									 columnNo += yyleng;
									return T_NOT_EQ;}

"{"			{
				scope++;
				columnNo += yyleng;
				return yytext[0];
			}

"}"			{
				scope--;
				columnNo += yyleng;
				if(scope < 0)
					yyerror("Undefined scope");
					return yytext[0];

			}

"\n"		{yylineno++;
			 columnNo = 0;
			 }


.			{ printf("< symbol, %c >\n", yytext[0]);
			  columnNo += yyleng;
				//if(scope > 0)
					//yyerror("Unmatched number of '{}'"); unmatched paranthesis to be matched in the semantic analysis phase
			return yytext[0];}


%%