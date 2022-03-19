#include "myheader.h"

struct Easy {
	string name, address;
	ll roll_no;

	bool operator < (Easy const &);
	bool operator > (Easy const &);
	bool operator == (Easy const &);
	void input_data();
	void print_data();
};

bool Easy::operator < (Easy const &obj) {
	if(roll_no != obj.roll_no) return roll_no < obj.roll_no;
	if(name.compare(obj.name) != 0) return -1 * name.compare(obj.name);
	return -1 * address.compare(obj.address);
}

bool Easy::operator > (Easy const &obj) {
	if(roll_no != obj.roll_no) return roll_no > obj.roll_no;
	if(name.compare(obj.name) != 0) return name.compare(obj.name);
	return address.compare(obj.address);
}

bool Easy::operator == (Easy const &obj) {
	return roll_no != obj.roll_no;
}

void Easy::input_data() {
	cout << "Name: ";
	cin >> name;

	cout << "Address: ";
	cin >> address;

	cout << "Roll Number: ";
	cin >> roll_no;
}

void Easy::print_data() {
	cout << "Name: " << name << endl;
	cout << "Address: " << address << endl;
	cout << "Roll Number: " << roll_no << endl;
}