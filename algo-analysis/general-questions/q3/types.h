#include "../../myheader.h"

struct polynomial {
	ll degree;
	vector<ll> pol;

	void input_data();
	void print_data();
	polynomial operator + (polynomial const &);
	polynomial operator * (polynomial const &);
};

void polynomial::input_data() {
	cout << "Enter the degree of polynomial: ";
	cin >> degree;

	cout << "Enter the coeffs:" << endl;
	loop(i, 0, degree + 1) {
		ll temp;
		cout << "x^" << i << ": ";
		cin >> temp;
		pol.push_back(temp);
	}
}

void polynomial::print_data() {
	looprev(i, degree, 0) {
		if(pol[i] == 0)
			continue;

		cout << pol[i] << "x^" << i << " + ";
	}
	cout << endl;
}

polynomial polynomial::operator + (polynomial const & obj) {
	polynomial res;
	res.degree = max(degree, obj.degree);

	ll min_degree = min(degree, obj.degree);

	loop(i, 0, min_degree + 1) {
		res.pol.push_back(pol[i] + obj.pol[i]);
	}

	loop(i, min_degree + 2, res.degree + 1) {
		if(degree > obj.degree)
			res.pol.push_back(pol[i]);
		else
			res.pol.push_back(obj.pol[i]);
	}

	return res;
}

polynomial polynomial::operator * (polynomial const & obj) {
	polynomial res;
	res.degree = degree + obj.degree;

	loop(i, 0, res.degree + 1) {
		res.pol.push_back(0);
	}

	looprev(i, degree, 0) {
		looprev(j, obj.degree, 0) {
			res.pol[i+j] += pol[i] * obj.pol[j];
		}
	}

	return res;
}