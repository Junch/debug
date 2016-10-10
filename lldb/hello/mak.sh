#http://clang.llvm.org/docs/UsersManual.html#controlling-debug-information

#clang -Wall -framework Foundation -gline-tables-only hello.m -o hello
clang -Wall -framework Foundation -g hello.m -o hello