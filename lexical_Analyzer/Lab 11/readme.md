**Simple Arithmatic Calculator using bison and flex**

_commands_ <br />

`flex calc.l ` - Generates the lex.yy.c file <br />
`bison -d calc.y ` - Generates calc.tab.c and calc.tab.h required for generating the calculator application <br />
`gcc -o calculator calc.tab.c lex.yy.c -lm` generates the calculator app <br />

_usage_<br />

After running the above commands in order, a calculator application will be generated which we can run using the following command <br />

`./calculator`<br />

Enter your expression and get the output, ignore the syntax error if occurs <br />

_example_<br />
![example](example.png)

**Note**
Make sure to add '=' symbol at the end of the expression<br />
