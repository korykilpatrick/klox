### NOTES ###

Breakpoints:

9/4/19
left off on ch. 21 Global Variables section 21.2 Variable Declarations

Notes:
- our bytecode VM uses a single-pass compiler, meaning it parses and generates bytecode on the fly without any intermediate AST. Which has made this easier to implement overall, but makes assignemnts harder.
  e.g. menu.brunch(sunday).beverage = "kombucha";
  -> we emit bytecode treating this like an expression and then go 'oh shit its an assignment' when we hit the '='
  
