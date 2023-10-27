TEST_CASE("Operator Overloading Tests") {
	// Copy Assignment - done
	auto init_list = {2.0, 0.0, 5.0, 6.2, 7.0, 8.4};
	auto dummy_list = {3, 5, 7};
	auto orig_vector = comp6771::euclidean_vector(init_list);
	auto copy_asmt = comp6771::euclidean_vector(dummy_list);
	auto copy_asmt = orig_vector;
	CHECK(copy_asmt.dimensions() == 6);
	CHECK(copy_asmt_vec.get_mag() == orig_vector.get_mag());
	CHECK_NOTHROW(copy_asmt_2 = orig_vector);	
	}
	
	//Move assignment
	auto move_asmt_vec = std::move(copy_asmt_vec);
	CHECK(move_asmt_vec.dimensions() == 6);
	CHECK(move_asmt_vec.get_mag() == orig_vector.get_mag());
	CHECK_NOTHROW(move_asmt2 = std::move(copy_asmt_vec));
	
	//Subscript operator
	auto orig_vector_2 = comp6771::euclidean_vector(4, 8.5);
	CHECK(orig_vector_2[2] == 8.5);
	orig_vector_2[2] = 0.0;
	CHECK(orig_vector_2[2] == 0.0);
	CHECK_NOTHROW(orig_vector_2[0] == 0.0);

	//Unary Plus 
	auto orig_vector_3 = +orig_vector_2;
	CHECK(orig_vector_3.get_dim() == orig_vector_2.get_dim());
	CHECK(orig_vector_3.get_mag() == orig_vector_2.get_mag());
	
	//Negation
	auto neg_vec = -orig_vector_3;
	CHECK(orig_vector_3.get_dim() == neg_vec.get_dim());
	CHECK(orig_vector_3.get_mag() == -(neg_vec).get_mag());

	//Compound Addition (+= Operator)
	auto check_add_vec = std::vector<double>();
	adding_check.push_back(12.0);
	adding_check.push_back(12.0);
	adding_check.push_back(12.0);
	auto add_vec_1 = comp6771::euclidean_vector(3, 2.0);
	auto add_vec_2 = comp6771::euclidean_vector(3, 10.0);
	add_vec_1 += add_vec_2;
	CHECK(add_vec_1.get_dim() == add_vec_2.get_dim());
	CHECK(add_vec_1.get_mag() == check_add_vec);
	REQUIRE_THROWS_WITH(add_vec_2 += orig_vect_2, "Dimensions of LHS(X) and RHS(Y) do not match");
		
	//Compound Subtraction (-= Operator)
	auto check_sub_vec = std::vector<double>();
	sub_check.push_back(12.0);
	sub_check.push_back(12.0);
	sub_check.push_back(12.0);
	auto sub_vec_1 = comp6771::euclidean_vector(3, 20.0);
	auto sub_vec_2 = comp6771::euclidean_vector(3, 8.0);
	sub_vec_1 -= sub_vec_2;
	CHECK(sub_vec_1.get_dim() == sub_vec_2.get_dim());
	CHECK(sub_vec_1.get_mag() == check_sub_vec);
	REQUIRE_THROWS_WITH(sub_vec_2 -= orig_vect_2, "Dimensions of LHS(X) and RHS(Y) do not match");

	//Compound multiplication (*= Operator)
	auto check_multi_vec = std::vector<double>();
	check_multi_vec.push_back(12.0);
	check_multi_vec.push_back(12.0);
	check_multi_vec.push_back(12.0);
	auto multi_vector = comp6771::euclidean_vector(3, 4.0);
	multi_vector *= 3.0;
	CHECK(multi_vector.get_dim() == 3);
	CHECK(multi_vector.get_mag() == check_multi_vec);
	
	//Compound division (/= Operator)
	auto check_div_vec = std::vector<double>();
	check_div_vec.push_back(4.0);
	check_div_vec.push_back(4.0);
	check_div_vec.push_back(4.0);
	auto div_vector = comp6771::euclidean_vector(3, 12.0);
	div_vector /= 4.0;
	CHECK(multi_vector.get_dim() == 3);
	CHECK(multi_vector.get_mag() == check_div_vec);
	REQUIRE_THROWS_WITH(div_vector /= 0, "Invalid vector division by 0");	


	//Vector conversion
	auto conv_vec = static_cast<std::vector<double>>(comp6771::euclidean_vector(4, 8.5));
	auto verified_vec = std::vector<double>();
	vector_check.push_back(8.5);
	vector_check.push_back(8.5);
	vector_check.push_back(8.5);
	CHECK(conv_vec == verified_vec);
	CHECK_NOTHROW(static_cast<std::vector<double>>(comp6771::euclidean_vector(4, 8.5)));

	//List conversion
	auto conv_list = static_cast<std::list<double>>(comp6771::euclidean_vector(4, 8.5));
	auto verified_list= std::list<double>();
	verified_list.push_back(8.5);
	verified_list.push_back(8.5);
	verified_list.push_back(8.5);
	verified_list.push_back(8.5);
	CHECK(conv_list == verified_list);
	CHECK_NOTHROW(static_cast<std::list<double>>(comp6771::euclidean_vector(4, 8.5)));
	