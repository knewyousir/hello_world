#include <iostream>
#include <limits>
#include <fstream>
#include <string>
#include <set>
#include <cstdlib>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::string;
using std::set;
using std::ios;

struct classesUser{
    string netId, nameLast, nameFirst, acctType;
    
    friend bool operator<(const classesUser& lhs, const classesUser& rhs)
    {
        return lhs.netId < rhs.netId;
    }
    
    friend std::ifstream& operator>>(std::ifstream& str, classesUser& user)
    {
        string line;
        classesUser tmp;
        std::size_t pos;
        if (std::getline(str, line))
        {
            std::stringstream iss(line);
            if (iss.ignore(std::numeric_limits<std::streamsize>::max(), '"') &&
                std::getline(iss, tmp.nameLast, ',') &&
                iss.ignore(std::numeric_limits<std::streamsize>::max(), ' ') &&
                std::getline(iss, tmp.nameFirst, '"') &&
                iss.ignore(std::numeric_limits<std::streamsize>::max(), ',') &&
                std::getline(iss, tmp.netId, ',') &&
                iss.ignore(std::numeric_limits<std::streamsize>::max(), ',') &&
                std::getline(iss, tmp.acctType, '\n'))
            {
                // It all worked
                pos = tmp.nameFirst.find_first_of(" \"");
                tmp.nameFirst = tmp.nameFirst.substr(0, pos);
                user.swap(tmp);
            }
            else
            {
                str.setstate(std::ios::failbit);
            }
        }
        return str;
    }
    
    friend std::ofstream& operator<<(std::ofstream& str, const classesUser& user)
    {
        if ( user.acctType == "Student")
        {
            str << user.nameFirst << ',' << user.nameLast
            << ','<< user.netId << "@nyu.edu,,,,\n";
        }
        else
            ;
        return str;
    }
    
    friend std::ostream& operator<<(std::ostream& str, const classesUser& user)
    {
        if ( user.acctType == "Student")
        {
            str << user.netId << "@nyu.edu," << user.nameFirst << ',' << user.nameLast
            << ",,,,\n";
        }
        else
            ;
        return str;
    }
    
    void swap(classesUser& other)
    {
        std::swap(nameLast, other.nameLast);
        std::swap(nameFirst, other.nameFirst);
        std::swap(netId, other.netId);
        std::swap(acctType, other.acctType);
    };
};

int main ()
{
    
    // Declare some variables
    
    string temp;
    classesUser tempUser;;
    set<classesUser> setUsers;
    set<classesUser>::iterator setIt;
    
    // Open file streams
    
    ifstream readNames;
    readNames.open("nyuClsCsv.csv", ios::in);
    
    ofstream writeNames;
    writeNames.open("outputCsv.csv", ios::out);

    // Populate the string matrix

    for (int count(0); count < 4; count++)
        readNames.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (readNames >> tempUser)
    {
        setUsers.insert(tempUser);
    }

    // Print the output file

    writeNames << "Email (Required),First Name (Required),Last Name (Required),Password,Phone (Incl. country code),Responding As,Private Data\n";
    for (setIt = setUsers.begin(); setIt != setUsers.end(); setIt++){
        writeNames << *setIt;
    }
    writeNames.close();
    return 0;
    
}

