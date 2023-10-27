//Single argument ctor:
TEST_CASE("Constructor with single argument"){
	auto const single_arg_ctr = ev::euclidean_vector(4);
	auto single_arg_vector = std::vector<double>();
	for (auto iter = 0; iter < 4; iter++){
		single_arg_vector.push_back(0.0);
	}
	CHECK(single_arg_ctr.dimensions() == 4);
	CHECK(single_arg_ctr.get_mag() == single_arg_vector);

}

//Two argument ctor:
TEST_CASE("Constructor with two arguments"){
	auto const double_arg_ctr = ev::euclidean_vector(4, 2.0);
	auto double_arg_vector = std::vector<double>();
	for (auto iter = 0; iter < 4; iter++){
		double_arg_vector.push_back(2.0);
	}
	CHECK(double_arg_ctr.dimensions() == 4);
	CHECK(double_arg_ctr.get_mag() == double_arg_vector);

}

//Iterator ctor:
TEST_CASE("Constructor with iterator"){
	auto iter_vec = std::vector<double>();
	iter_vec.push_back(2.0);
	iter_vec.push_back(0.0);
	iter_vec.push_back(5.0);
	iter_vec.push_back(55.0);
	auto const iter_arg_ctr = ev::euclidean_vector(iter_vec.begin(), iter_vec.end());
	CHECK(iter_arg_ctr.dimensions() == 4);
	CHECK(iter_arg_ctr.get_mag() == iter_vec);

}

//Initializer list ctor:
TEST_CASE("Constructor with Initializer List"){
	auto init_list = {2.0, 0.0, 5.0, 6.2, 7.0, 8.4};
	auto init_vector = std::vector<double>(init_list);
	auto const init_list_ctr = ev::euclidean_vector(init_list);
	CHECK(init_list_ctr.dimensions() == 6);
	CHECK(init_list_ctr.get_mag() == init_vector);

}

//Copy ctor:
TEST_CASE("Copy constructor test"){
	auto const double_arg_ctr = ev::euclidean_vector(4, 2.0);
	auto copy_ctr = ev::euclidean_vector(double_arg_ctr);
	auto double_arg_vector_cpy = std::vector<double>();
	for (auto iter = 0; iter < 4; iter++){
		double_arg_vector_cpy.push_back(2.0);
	}
	CHECK(copy_ctr.dimensions() == 4);
	CHECK(copy_ctr.get_mag() == double_arg_vector_cpy);
}

//Move ctor:
TEST_CASE("Move constructor test"){
	auto const double_arg_ctr = ev::euclidean_vector(4, 2.0);
	auto temp_move_ctr = ev::euclidean_vector(double_arg_ctr);
	auto move_ctr = ev::euclidean_vector(std::move(temp_move_ctr));
	auto double_arg_vector_cpy = std::vector<double>();
	for (auto iter = 0; iter < 4; iter++){
		double_arg_vector_cpy.push_back(2.0);
	}
	CHECK(move_ctr.dimensions() == 4);
	CHECK(move_ctr.get_mag() == double_arg_vector_cpy);
	CHECK(temp_move_ctr.dimensions() == 0);
	//CHECK(temp_move_ctr.get_mag() == 0);
}
