#ifndef COMP6771_EUCLIDEAN_VECTOR_HPP
#define COMP6771_EUCLIDEAN_VECTOR_HPP

#include <cmath>
#include <list>
#include <memory>
#include <ostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace comp6771 {
	class euclidean_vector_error : public std::runtime_error {
	public:
		explicit euclidean_vector_error(std::string const& what)
		: std::runtime_error(what) {}
	};

	class euclidean_vector {
	public:
		// constructors:
		euclidean_vector() noexcept;
		euclidean_vector(const int) noexcept;
		euclidean_vector(const int, const double) noexcept;
		euclidean_vector(std::vector<double>::const_iterator,
		                 std::vector<double>::const_iterator) noexcept;
		euclidean_vector(std::initializer_list<double>) noexcept;
		euclidean_vector(const euclidean_vector&) noexcept;
		euclidean_vector(euclidean_vector&&) noexcept;

		// destructor:
		~euclidean_vector();

		// operations:
		euclidean_vector& operator=(const euclidean_vector&) noexcept;
		euclidean_vector& operator=(euclidean_vector&&) noexcept;
		double& operator[](const int&);
		double& operator[](const int&) const;
		euclidean_vector operator+() noexcept;
		euclidean_vector operator-() noexcept;
		euclidean_vector& operator+=(const euclidean_vector&);
		euclidean_vector& operator-=(const euclidean_vector&);
		euclidean_vector& operator*=(const double&) noexcept;
		euclidean_vector& operator/=(const double&);
		explicit operator std::vector<double>() const noexcept;
		explicit operator std::list<double>() const noexcept;

		// member functions:
		double at(const int) const;
		double& at(const int);
		int dimensions() const;

		// friends:
		friend bool operator==(euclidean_vector const&, euclidean_vector const&) noexcept;
		friend bool operator!=(euclidean_vector const&, euclidean_vector const&) noexcept;
		friend euclidean_vector operator+(euclidean_vector const&, euclidean_vector const&);
		friend euclidean_vector operator-(euclidean_vector const&, euclidean_vector const&);
		friend euclidean_vector operator*(euclidean_vector const&, double);
		friend euclidean_vector operator*(double, euclidean_vector const&);
		friend euclidean_vector operator/(euclidean_vector const&, double);
		friend std::ostream& operator<<(std::ostream&, euclidean_vector const&);

		// Getters:
		auto get_dim() const -> int;
		auto get_mag() const -> std::vector<double>;

	private:
		// ass2 spec requires we use std::unique_ptr<double[]>
		// NOLINTNEXTLINE(modernize-avoid-c-arrays)
		int dimensions_;
		std::unique_ptr<double[]> magnitudes_;
	};
	// utility functions:
	auto euclidean_norm(euclidean_vector const&) -> double;
	auto unit(euclidean_vector const&) -> euclidean_vector;
	auto dot(euclidean_vector const&, euclidean_vector const&) -> double;
} // namespace comp6771
// namespace comp6771
#endif // COMP6771_EUCLIDEAN_VECTOR_HPP
