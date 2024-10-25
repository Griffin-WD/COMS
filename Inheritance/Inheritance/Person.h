#pragma once

#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

class Person {
public:

    void setfName(string text)
    {
        fName = text;
    }
    void setlName(string text)
    {
        lName = text;
    }
    void setAddress(string text)
    {
        address = text;
    }
    void setCity(string text)
    {
        city = text;
    }
    void setState(string text)
    {
        state = text;
    }
    void setZip(string text)
    {
        zip = text;
    }
    void setphoneNum(string text)
    {
        phoneNum = text;
    }
    string getfName()
    {
        return fName;
    }
    string getlName()
    {
        return lName;
    }
    string getAddress()
    {
        return address;
    }
    string getCity()
    {
        return city;
    }
    string getState()
    {
        return state;
    }
    string getphoneNum()
    {
        return phoneNum;
    }
    string getZip()
    {
        return zip;
    }
protected:
    string fName, lName, address, city, state, zip, phoneNum;
};

void fileCheck(ifstream& iFile)
{
    if (!iFile.is_open())
    {
        cout << "Input file not found" << endl;
        exit(1);
    }
}