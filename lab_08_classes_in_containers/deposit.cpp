#include "deposit.h"

#include <iomanip>
#include <sstream>

Deposit::Deposit()
    : _name(""), _amount(0.0), _currency(""), _rate(0.0) {}

Deposit::Deposit(const std::string& name, double amount, const std::string& currency, double rate)
    : _name(name), _amount(amount), _currency(currency), _rate(rate) {}

Deposit::Deposit(const Deposit& oth)
    : _name(oth._name), _amount(oth._amount), _currency(oth._currency), _rate(oth._rate) {}

Deposit::Deposit(Deposit&& oth) noexcept
    : _name(std::move(oth._name)), _amount(oth._amount), _currency(std::move(oth._currency)), _rate(oth._rate) {
        oth._name.clear();
        oth._amount = 0.0;
        oth._currency.clear();
        oth._rate = 0.0;
}

Deposit::~Deposit() {}


Deposit& Deposit::operator=(const Deposit& oth) {
    if (this != &oth) {
        _name = oth._name;
        _amount = oth._amount;
        _currency = oth._currency;
        _rate = oth._rate;
    }
    return *this;
}

Deposit& Deposit::operator=(Deposit&& oth) noexcept {
    if (this != &oth) {
        _name = std::move(oth._name);
        _amount = oth._amount;
        _currency = std::move(oth._currency);
        _rate = oth._rate
        ;
        oth._name.clear();
        oth._amount = 0.0;
        oth._currency.clear();
        oth._rate = 0.0;
    }
    return *this;
}

std::string Deposit::getName() const {return _name;}
double Deposit::getAmount() const {return _amount;}
std::string Deposit::getCurrency() const {return _currency;}
double Deposit::getRate() const {return _rate;}

void Deposit::setName(const std::string& name) {_name = name;}
void Deposit::setAmount(double amount) {_amount = amount;}
void Deposit::setCurrency(const std::string& currency) {_currency = currency;}
void Deposit::setRate(double rate) {_rate = rate;}

// sort by amount
bool Deposit::operator<(const Deposit& oth) const {
    return _amount < oth._amount;
}
bool Deposit::operator>(const Deposit& oth) const {
    return _amount > oth._amount;
}

bool Deposit::operator==(const Deposit& oth) const {
    return _name == oth._name &&
           _amount == oth._amount &&
           _currency == oth._currency &&
           _rate == oth._rate;
}

std::ostream& operator<<(std::ostream& os, const Deposit& dep) {
    os << dep._name << " | " << dep._amount << " | "
       << dep._currency << " | "  << dep._rate;
    return os;
}

std::istream& operator>>(std::istream& is, Deposit& dep) {
    std::string row;
    if (std::getline(is, row)) {
        if (row.empty()) return is;

        std::stringstream ss(row);

        std::getline(ss, dep._name, '|');
        dep._name.erase(dep._name.length() - 1);

        std::string temp;
        std::getline(ss, temp, '|');
        temp.erase(0, 1);
        temp.erase(temp.length() - 1);
        dep._amount = std::stod(temp);

        std::getline(ss, dep._currency, '|');
        dep._currency.erase(0, 1);
        dep._currency.erase(dep._currency.length() - 1);

        std::getline(ss, temp);
        temp.erase(0, 1);
        dep._rate = std::stod(temp);
    }
    return is;
}

