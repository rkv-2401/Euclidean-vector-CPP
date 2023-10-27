TEST_CASE("Member Functions Tests") {
	// At reference
	auto init_list = {1.2, 2.4, 3.6, 4.8, 6.0, 7.2};
	auto init_vector= comp6771::euclidean_vector(init_list);
	CHECK(init_vector.at(0) == 1.2);
	init_vector.at(0) = 8.5;
	CHECK(init_vector.at(0) == 8.5);

	// Dimensions
	auto dim_init_vector = comp6771::euclidean_vector(init_list);
	auto dim_vector = dim_init_vector.get_mag();
	CHECK(dim_vector.dimensions() == static_cast<int>(dim_init_vector.size()));

}