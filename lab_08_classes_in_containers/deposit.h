#pragma once

#include <iostream>
#include <string>
#include <fstream>


class Deposit {
private:
    std::string _name;
    double _amount;
    std::string _currency;
    double _rate;

public:
    Deposit();
    Deposit(const std::string& name, double amount,
                const std::string& currency, double rate);
    Deposit(const Deposit& oth);
    Deposit(Deposit&& oth) noexcept;

    ~Deposit();

    Deposit& operator=(const Deposit& oth);
    Deposit& operator=(Deposit&& oth) noexcept;

    std::string getName() const;
    double getAmount() const;
    std::string getCurrency() const;
    double getRate() const;

    void setName(const std::string& name);
    void setAmount(double amount);
    void setCurrency(const std::string& currency);
    void setRate(double rate);

    bool operator<(const Deposit& oth) const;
    bool operator>(const Deposit& oth) const;

    bool operator==(const Deposit& oth) const;

    friend std::ostream& operator<<(std::ostream& os, const Deposit& dep);
    friend std::istream& operator>>(std::istream& is, Deposit& dep);
};

struct Hasher {
    std::hash<std::string> shash;
    std::hash<double> dhash;

    size_t operator()(const Deposit& ob) const {
        const size_t coef = 2946901;

        return (
            coef * coef * shash(ob.getName()) +
            coef * dhash(ob.getAmount()) +
            coef * shash(ob.getCurrency()) +
            dhash(ob.getRate())
        );
    }
};
