// Copyright 2020 <telsamar>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <llogs.h>


void logs() {
    srand(*(new int));
    static const string ideal("0000");
    while (true) {
        string s = to_string(rand());
        string crypted = picosha2::hash256_hex_string(s);
        if (crypted.substr(crypted.size() - ideal.size()) != ideal)
            BOOST_LOG_TRIVIAL(trace) << "Non-positive result: " << crypted << ", which result of " << s;
        else
            BOOST_LOG_TRIVIAL(info) << "Positive result: " << crypted << ", which result of " << s;
    }
}
#endif // INCLUDE_HEADER_HPP_
