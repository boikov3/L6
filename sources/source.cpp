// Copyright 2020 <telsamar>
#include <header.hpp>

int main(int argc, char* argv[]) {
	size_t M = thread::hardware_concurrency();
	if (argc > 1)
		M = atoi(argv[1]);
	boost::log::register_simple_formatter_factory<boost::log::trivial::severity_level, char>("Severity");
	init_logs();
	boost::log::add_common_attributes();
	BOOST_LOG_TRIVIAL(trace) << "Threads amount: " << M;
	vector<thread*> threads;
	threads.resize(M);
	for (size_t i = 0; i < M; i++)
		threads[i] = new thread(logs);
	for (auto th : threads)
		th->join();
	return 0;
}

