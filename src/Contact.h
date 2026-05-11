#pragma once

#include <string>
#include <vector>
#include <iostream>

// Base Class
class Contact {
protected:
    std::string name;
    std::string phoneNumber;
    std::string email;
    std::string city;
    std::vector<std::string> tags;
    std::string group;

public:
    Contact(std::string n, std::string p, std::string e, std::string c);
    virtual ~Contact(); // polymorphism

    // Pure virtual function
    virtual void display() const = 0;

    // Getters
    std::string getName() const;
    std::string getEmail() const;
    std::string getPhoneNumber() const;
    std::string getCity() const;

    // Setters / Modifiers
    void setPhoneNumber(const std::string& p);
    void setGroup(const std::string& g);
    void addTag(const std::string& tag);
};

// --- Derived Classes ---

class Person : public Contact {
private:
    std::string birthday;
public:
    Person(std::string n, std::string p, std::string e, std::string c, std::string b);
    void display() const override;
};

class Business : public Contact {
private:
    std::string website;
public:
    Business(std::string n, std::string p, std::string e, std::string c, std::string w);
    void display() const override;
};

class Vendor : public Contact {
private:
    std::string serviceType;
public:
    Vendor(std::string n, std::string p, std::string e, std::string c, std::string s);
    void display() const override;
};

class Emergency : public Contact {
private:
    std::string relationship;
public:
    Emergency(std::string n, std::string p, std::string e, std::string c, std::string r);
    void display() const override;
};