#include "nyastega8.cpp"

#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(nyastega8) {
    function("encode", &nyastega8::encode);
    function("decode", &nyastega8::decode);
}

int main() {
    printf("hello nyastega8");
}