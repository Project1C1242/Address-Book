#pragma once

#include <string>
#include <vector>

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
    virtual ~Contact();

    virtual void display() const = 0; // Pure virtual

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