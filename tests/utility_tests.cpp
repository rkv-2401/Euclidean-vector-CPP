TEST_CASE("Utility Tests") {
	// Euclidean Norm
	//4 + 9 + 25 = 38
	//capture floating point error - how? Epsilon?
	auto init_list = {2.0, 3.0, 5.0};
	auto norm_vector = ev::euclidean_vector(init_list);
	CHECK(ev::euclidean_norm(norm_vector) == sqrt(38));
	norm_vector[2] = 0;
	CHECK(ev::euclidean_norm(norm_vector) == 4);
	//what's the point, obviously it hasn't thrown any exceptions so far?
	CHECK_NOTHROW(ev::euclidean_norm(norm_vector));
	
	// Unit Vector
	auto init_list = {2.0, 3.0};
	auto norm_vector = ev::euclidean_vector(init_list);
	auto unit_vector = norm_vector /= 4;
	CHECK(ev::unit(norm_vector) == unit_vector);
	REQUIRE_THROWS_WITH(ev::unit(ev::euclidean_vector()),
			  "euclidean_vector with zero euclidean normal does not have a unit "
			   "vector");

	// Dot product
	//[1 6] [6 1] = 1 * 6 + 6 * 1 = 12
	//[1 2] [3 4] = 1 * 3 + 2 *4 = 11
	auto init_vec_1 = ev::euclidean_vector({1, 6});
	auto init_vec_2 = ev::euclidean_vector({6, 1});	
	auto init_vec_3 = ev::euclidean_vector({1, 2});
	auto init_vec_4 = ev::euclidean_vector({3, 4});
	CHECK(ev::dot(init_vec_1, init_vec_2) == 12);
	CHECK(ev::dot(init_vec_3, init_vec_4) == 11);
	REQUIRE_THROWS_WITH(ev::unit(ev::euclidean_vector()),
			  "euclidean_vector with zero euclidean normal does not have a unit"
			   "vector");
