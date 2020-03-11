
#ifndef LAB_O_TWO_LLOGS_H
#define LAB_O_TWO_LLOGS_H


#include <thread>
#include <cstdlib>
#include <vector>
#include <iostream>

#include <boost/log/trivial.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup.hpp>


#include "picosha2.h"

using std::thread;
using std::atoi;
using std::vector;
using std::cout;
using std::string;
using std::size_t;
using std::to_string;
using std::rand;


void init_logs() {
    auto log = boost::log::add_file_log(
            boost::log::keywords::file_name = "../logs/logFile_%N.log",
            boost::log::keywords::rotation_size = 10 * 1024 * 1024,
            boost::log::keywords::time_based_rotation = boost::log::sinks::file::rotation_at_time_point{ 0, 0, 0 },
            boost::log::keywords::format = "[%TimeStamp%]: %Message%"
    );

    auto log2 = boost::log::add_console_log(
            cout,
            boost::log::keywords::format = "[%TimeStamp%]: %Message%"
    );

    log->set_filter(
            boost::log::trivial::severity >= boost::log::trivial::trace
    );
    log2->set_filter(
            boost::log::trivial::severity >= boost::log::trivial::info
    );
}



#endif //LAB_O_TWO_LLOGS_H
