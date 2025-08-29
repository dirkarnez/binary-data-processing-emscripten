#include <iostream>
#include <string>
#include <vector>
#include <emscripten/bind.h>
#include <emscripten/val.h>

using namespace emscripten;

val get_bytes(std::string input) {
    std::vector<unsigned char> vals(input.length());
    for (int i = 0; i < input.length(); i++)  //We interate through string passed and add to vectors
    {
        vals.push_back((unsigned char)input.at(i));
    }
    return val(typed_memory_view(vals.size(), vals.data()));
}


// This is the extra code you need to write to expose your function to JS
EMSCRIPTEN_BINDINGS(my_module) {
    function("getBytes", &get_bytes);
}

// #include <fnmatch.h>
// #include <string>
// #include <iostream>

// #include <emscripten/bind.h>
// using namespace emscripten;

// int fnmatch_wrapped(std::string pattern, std::string input, int flags) {
//     return fnmatch(pattern.c_str(), input.c_str(), flags);
// }

// EMSCRIPTEN_BINDINGS(my_module) {
//     function("fnmatch", &fnmatch_wrapped);
//     constant("FNM_PATHNAME", FNM_PATHNAME);
//     constant("FNM_NOESCAPE", FNM_NOESCAPE);
//     constant("FNM_PERIOD", FNM_PERIOD);
    
//     constant("FNM_NOMATCH", FNM_NOMATCH);
    
//     // constant("FNM_FILE_NAME", FNM_FILE_NAME);
//     // constant("FNM_LEADING_DIR", FNM_LEADING_DIR);
//     // constant("FNM_CASEFOLD", FNM_CASEFOLD);
//     // constant("FNM_EXTMATCH", FNM_EXTMATCH);
// }
