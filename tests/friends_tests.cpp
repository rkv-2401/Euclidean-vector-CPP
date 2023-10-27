TEST_CASE("Equal and not equal") {
	//Equal and not equal
	auto init_list = {1.2, 2.4, 3.6, 4.8, 6.0, 7.2};
	auto diff_init_list = {2.0, 3.2, 5.0, 6.2, 7.0, 8.4};
	auto init_vector= ev::euclidean_vector(init_list);
	auto init_vector_copy = ev::euclidean_vector(init_list);
	auto diff_init_vector = ev::euclidean_vector(diff_init_list);
	CHECK(init_vector == init_vector_copy);
	CHECK(init_vector != diff_init_vector);
	CHECK(!(init_vector == diff_init_vector));
	CHEK(!(init_vector != init_vector_copy));

TEST_CASE("Arithmetic operations"){
	auto a1 = ev::euclidean_vector(5, 1.0);
	auto a1_vec = a1.get_mag();
	auto a2 = ev::euclidean_vector(5, 2.0);
	auto a2_vec = a2.get_mag();
	auto a3 = ev::euclidean_vector(5, 3.0);
	auto a3= a3.get_mag();
	auto a4= ev::euclidean_vector(5, 5.0);
	auto a4= a4.get_mag();
	auto a5= ev::euclidean_vector(5, 6.0);
	auto a5= a5.get_mag();
	auto a6= ev::euclidean_vector(5, 10.0);
	auto a6= a6.get_mag();
	//operations:
	auto addition = a1 + a1;
	auto subtraction = a4 - a2;
	auto division = a5 / 2;
	auto multiply = a2 * 3;
	auto multiply_2 = 2 * a4
	CHECK(addition == a2);
	CHECK(subtraction == a3);
	CHECK(division == a3);
	CHECK(multiply == a5);
	CHECK(multiply == a6);
}
	
