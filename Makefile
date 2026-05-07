all:
	clang++ -dynamiclib -arch arm64 modff.cpp -o modff.dylib
