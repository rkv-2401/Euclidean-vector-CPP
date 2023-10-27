/ Copyright (c) Christopher Di Bella.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
#include <comp6771/euclidean_vector.hpp>

namespace comp6771 {

	// Constructors:
	euclidean_vector::euclidean_vector() noexcept {
		dimensions_ = 1;
		// NOLINTNEXTLINE(modernize-avoid-c-arrays)
		magnitudes_ = std::make_unique<double[]>(static_cast<size_t>(dimensions_));
		for (auto iter = 0; iter < dimensions_; iter++) {
			// NOLINTNEXTLINE(modernize-avoid-c-arrays)
			magnitudes_[static_cast<size_t>(iter)] = 0;
		}
	}

	euclidean_vector::euclidean_vector(int input_dimension) noexcept {
		dimensions_ = input_dimension;
		// NOLINTNEXTLINE(modernize-avoid-c-arrays)
		magnitudes_ = std::make_unique<double[]>(static_cast<size_t>(dimensions_));
		for (auto iter = 0; iter < dimensions_; iter++) {
			// NOLINTNEXTLINE(modernize-avoid-c-arrays)
			magnitudes_[static_cast<size_t>(iter)] = 0;
		}
	}
	euclidean_vector::euclidean_vector(int input_dimension, double input_magnitude) noexcept {
		dimensions_ = input_dimension;
		// NOLINTNEXTLINE(modernize-avoid-c-arrays)
		magnitudes_ = std::make_unique<double[]>(static_cast<size_t>(dimensions_));
		for (auto iter = 0; iter < dimensions_; iter++) {
			// NOLINTNEXTLINE(modernize-avoid-c-arrays)
			magnitudes_[static_cast<size_t>(iter)] = input_magnitude;
		}
	}
	euclidean_vector::euclidean_vector(std::vector<double>::const_iterator start_iterator,
	                                   std::vector<double>::const_iterator end_iterator) noexcept {
		int int_iter = 0;
		for (auto i = start_iterator; i < end_iterator; i++) {
			int_iter++;
		}
		dimensions_ = int_iter;
		// NOLINTNEXTLINE(modernize-avoid-c-arrays)
		magnitudes_ = std::make_unique<double[]>(static_cast<size_t>(dimensions_));
		int_iter = 0;
		for (auto i = start_iterator; i < end_iterator; i++) {
			// NOLINTNEXTLINE(modernize-avoid-c-arrays)
			magnitudes_[static_cast<size_t>(int_iter)] = *i;
			int_iter++;
		}
	}
	euclidean_vector::euclidean_vector(std::initializer_list<double> input_list) noexcept {
		// NOLINTNEXTLINE(modernize-avoid-c-arrays)
		magnitudes_ = std::make_unique<double[]>(input_list.size());
		auto int_iter = 0;
		for (auto mag_iter : input_list) {
			// NOLINTNEXTLINE(modernize-avoid-c-arrays)
			magnitudes_[static_cast<size_t>(int_iter)] = mag_iter;
			int_iter++;
		}
		dimensions_ = int_iter;
	}
	euclidean_vector::euclidean_vector(const euclidean_vector& orig) noexcept {
		dimensions_ = orig.dimensions_;
		// NOLINTNEXTLINE(modernize-avoid-c-arrays)
		magnitudes_ = std::make_unique<double[]>(static_cast<size_t>(dimensions_));
		for (auto iter = 0; iter < dimensions_; iter++) {
			// NOLINTNEXTLINE(modernize-avoid-c-arrays)
			magnitudes_[static_cast<size_t>(iter)] = orig.at(iter);
		}
	}
	euclidean_vector::euclidean_vector(euclidean_vector&& orig) noexcept
	: dimensions_{std::exchange(orig.dimensions_, 0)}
	, magnitudes_{std::exchange(orig.magnitudes_, nullptr)} {};

	euclidean_vector::~euclidean_vector(){

	};

	// Operations:

	euclidean_vector& euclidean_vector::operator=(const euclidean_vector& orig) noexcept {
		dimensions_ = orig.dimensions();
		// NOLINTNEXTLINE(modernize-avoid-c-arrays)
		magnitudes_ = std::make_unique<double[]>(static_cast<size_t>(orig.dimensions_));
		for (auto iter = 0; iter < dimensions_; iter++) {
			// NOLINTNEXTLINE(modernize-avoid-c-arrays)
			magnitudes_[static_cast<size_t>(iter)] = orig.at(iter);
		}
		return *this;
	}

	euclidean_vector& euclidean_vector::operator=(euclidean_vector&& orig) noexcept {
		std::swap(dimensions_, orig.dimensions_);
		// NOLINTNEXTLINE(modernize-avoid-c-arrays)
		magnitudes_ = std::make_unique<double[]>(static_cast<size_t>(dimensions_));
		for (auto iter = 0; iter < dimensions_; iter++) {
			// NOLINTNEXTLINE(modernize-avoid-c-arrays)
			std::swap(magnitudes_[static_cast<size_t>(iter)], orig.at(iter));
		}
		orig.dimensions_ = 0;
		orig.magnitudes_.release();
		return *this;
	}

	double& euclidean_vector::operator[](const int& num) {
		return magnitudes_[static_cast<size_t>(num)];
	}

	double& euclidean_vector::operator[](const int& num) const {
		return magnitudes_[static_cast<size_t>(num)];
	}

	euclidean_vector euclidean_vector::operator+() noexcept {
		return *this;
	}

	euclidean_vector euclidean_vector::operator-() noexcept {
		auto temp_std_vec = this->get_mag();
		for (auto& iter : temp_std_vec) {
			iter = (0 - iter);
		}
		euclidean_vector temp_euc_vec = euclidean_vector(temp_std_vec.begin(), temp_std_vec.end());
		return temp_euc_vec;
	}

	euclidean_vector& euclidean_vector::operator+=(const euclidean_vector& input_vec) {
		if (dimensions_ != input_vec.dimensions()) {
			throw "Dimensions of LHS(X) and RHS(Y) do not match"; // tut 5
		}
		for (auto iter = 0; iter < dimensions_; iter++) {
			// NOLINTNEXTLINE(modernize-avoid-c-arrays)
			magnitudes_[static_cast<size_t>(iter)] += input_vec.at(iter);
		}
		return *this;
	}

	euclidean_vector& euclidean_vector::operator-=(const euclidean_vector& input_vec) {
		if (dimensions_ != input_vec.dimensions()) {
			throw "Dimensions of LHS(X) and RHS(Y) do not match";
		}
		for (auto iter = 0; iter < dimensions_; iter++) {
			// NOLINTNEXTLINE(modernize-avoid-c-arrays)
			magnitudes_[static_cast<size_t>(iter)] -= input_vec.at(iter);
		}
		return *this;
	}

	euclidean_vector& euclidean_vector::operator*=(const double& num) noexcept {
		for (auto iter = 0; iter < dimensions_; iter++) {
			// NOLINTNEXTLINE(modernize-avoid-c-arrays)
			magnitudes_[static_cast<size_t>(iter)] = (magnitudes_[static_cast<size_t>(iter)]) * num;
		}
		return *this;
	}

	euclidean_vector& euclidean_vector::operator/=(const double& num) {
		if (num == 0) {
			throw "Invalid vector division by 0";
		}
		for (auto iter = 0; iter < dimensions_; iter++) {
			// NOLINTNEXTLINE(modernize-avoid-c-arrays)
			magnitudes_[static_cast<size_t>(iter)] = (magnitudes_[static_cast<size_t>(iter)]) / num;
		}
		return *this;
	}

	// vector type conversion and list type conversion
	euclidean_vector::operator std::vector<double>() const noexcept {
		std::vector<double> new_vec(static_cast<size_t>(dimensions_));
		for (auto iter = 0; iter < dimensions_; iter++) {
			// NOLINTNEXTLINE(modernize-avoid-c-arrays)
			new_vec[static_cast<size_t>(iter)] = magnitudes_[static_cast<size_t>(iter)];
		}
		return new_vec;
	}

	euclidean_vector::operator std::list<double>() const noexcept {
		std::list<double> new_list = {};
		for (auto iter = 0; iter < dimensions_; iter++) {
			// NOLINTNEXTLINE(modernize-avoid-c-arrays)
			new_list.push_back(magnitudes_[static_cast<size_t>(iter)]);
		}
		return new_list;
	}

	// Member functions:
	double euclidean_vector::at(const int dim) const {
		if (dim < 0 || dim >= this->dimensions_) {
			throw std::runtime_error("Index " + std::to_string(dim)
			                         + " is not valid for this euclidean_vector object");
		}
		double return_num = this->magnitudes_[static_cast<size_t>(dim)];
		return return_num;
	}

	double& euclidean_vector::at(const int dim) {
		if (dim < 0 || dim >= this->dimensions_) {
			throw std::runtime_error("Index " + std::to_string(dim)
			                         + " is not valid for this euclidean_vector object");
		}
		return this->magnitudes_[static_cast<size_t>(dim)];
	}

	int euclidean_vector::dimensions() const {
		return this->dimensions_;
	}
	// friends
	bool operator==(euclidean_vector const& first_vec, euclidean_vector const& second_vec) noexcept {
		if (first_vec.dimensions_ != second_vec.dimensions_) {
			return false;
		}
		else {
			for (auto iter = 0; iter < first_vec.dimensions_; iter++) {
				if (first_vec.at(iter) != second_vec.at(iter)) {
					return false;
				}
			}
		}
		return true;
	}

	bool operator!=(euclidean_vector const& first_vec, euclidean_vector const& second_vec) noexcept {
		if (first_vec.dimensions_ != second_vec.dimensions_) {
			return true;
		}
		else {
			for (auto iter = 0; iter < first_vec.dimensions_; iter++) {
				if (first_vec.at(iter) != second_vec.at(iter)) {
					return true;
				}
			}
		}
		return false;
	}

	euclidean_vector operator+(euclidean_vector const& first_vec, euclidean_vector const& second_vec) {
		if (first_vec.dimensions_ != second_vec.dimensions_) {
			throw "Dimensions of LHS(X) and RHS(Y) do not match";
		}

		euclidean_vector temp_vec = euclidean_vector(first_vec);
		for (auto iter = 0; iter < first_vec.dimensions_; iter++) {
			temp_vec.at(iter) += second_vec.at(iter);
		}
		return temp_vec;
	}

	euclidean_vector operator-(euclidean_vector const& first_vec, euclidean_vector const& second_vec) {
		if (first_vec.dimensions_ != second_vec.dimensions_) {
			throw "Dimensions of LHS(X) and RHS(Y) do not match";
		}
		euclidean_vector temp_vec = euclidean_vector(first_vec);
		for (auto iter = 0; iter < temp_vec.dimensions_; iter++) {
			temp_vec.at(iter) -= second_vec.at(iter);
		}
		return temp_vec;
	}

	euclidean_vector operator*(euclidean_vector const& input_vec, double num) {
		euclidean_vector temp_vec = euclidean_vector(input_vec);
		for (auto iter = 0; iter < temp_vec.dimensions_; iter++) {
			temp_vec.at(iter) = (num * temp_vec.at(iter));
		}
		return temp_vec;
	}

	euclidean_vector operator*(double num, euclidean_vector const& input_vec) {
		// need two operators, as the scalar can be either side of the vector
		euclidean_vector temp_vec = euclidean_vector(input_vec);
		for (auto iter = 0; iter < temp_vec.dimensions(); iter++) {
			temp_vec.at(iter) = num * temp_vec.at(iter);
		}
		return temp_vec;
	}

	euclidean_vector operator/(euclidean_vector const& input_vec, double num) {
		if (num == 0) {
			throw "Invalid vector division by 0";
		}
		euclidean_vector temp_vec = euclidean_vector(input_vec);
		for (auto iter = 0; iter < temp_vec.dimensions_; iter++) {
			temp_vec.at(iter) = temp_vec.at(iter) / num;
		}
		return temp_vec;
	}

	std::ostream& operator<<(std::ostream& os, euclidean_vector const& input_vec) {
		for (auto iter = 0; iter < input_vec.dimensions(); iter++) {
			if (iter == 0) {
				os << "[" << input_vec.at(iter) << " ";
			}
			else if (iter == (input_vec.dimensions() - 1)) {
				os << input_vec.at(iter) << "]";
			}
			else {
				os << input_vec.at(iter) << " ";
			}
		}
		return os;
	}
	// Getters:

	// NOLINTNEXTLINE(modernize-avoid-c-arrays)
	auto euclidean_vector::get_mag() const -> std::vector<double> {
		auto dim = dimensions_;
		auto return_vec = std::vector<double>();
		for (auto iter = 0; iter < static_cast<int>(dim); iter++) {
			// NOLINTNEXTLINE(modernize-avoid-c-arrays)
			auto temp = magnitudes_[static_cast<size_t>(iter)];
			return_vec.push_back(temp);
		}
		return return_vec;
	}

	auto euclidean_vector::get_dim() const -> int {
		auto dim = dimensions();
		return dim;
	}

	// 6)Utility functions
	auto euclidean_norm(euclidean_vector const& v) -> double {
		double sq_norm = 0;
		if (v.dimensions() == 0) {
			return sq_norm;
		}
		for (auto iter = 0; iter < v.dimensions(); iter++) {
			sq_norm += (v.at(iter) * v.at(iter));
		}
		return std::sqrt(sq_norm);
	}

	auto unit(euclidean_vector const& v) -> euclidean_vector {
		auto dim = v.dimensions();
		if (dim == 0) {
			throw "euclidean_vector with no dimensions does not have a unit vector";
		}
		euclidean_vector temp_vec = euclidean_vector(dim);
		auto norm = euclidean_norm(v);
		if (norm == 0) {
			throw "euclidean_vector with zero euclidean normal does not have a unit vector";
		}
		for (auto iter = 0; iter < v.dimensions(); iter++) {
			temp_vec.at(iter) = (v.at(iter) / norm);
		}
		return temp_vec;
	}

	auto dot(euclidean_vector const& x, euclidean_vector const& y) -> double {
		auto x_dim = x.dimensions();
		auto y_dim = y.dimensions();
		if (x_dim != y_dim) {
			throw "Dimensions of LHS(X) and RHS(Y) do not match";
		}
		double dot_pdt = 0;
		for (auto iter = 0; iter < x_dim; iter++) {
			dot_pdt += (x.at(iter) * y.at(iter));
		}
		return dot_pdt;
	}

} // namespace comp6771
