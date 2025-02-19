/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2024
 *
 * @file    csc232.h
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Macros, libraries and definitions for use in csc232 assignments.
 * @version 0.1
 * @date    9/10/2021
 *
 * @copyright Copyright (c) 2021 James R. Daehn
 */

#ifndef CSC232_COMMON_H_
#define CSC232_COMMON_H_

#define FALSE 0
#define TRUE 1
#define EXECUTE_BLOCK FALSE

#define FINISHED_PART_1 TRUE
#define FINISHED_PART_2 TRUE
#define FINISHED_PART_3 TRUE

#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <stdexcept>
#include <utility>
#include <vector>

#include "expanded_templates.h"

/** Common iostream objects */
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

/** Common iomanip objects */
using std::left;
using std::right;
using std::setprecision;
using std::setw;

/**
 * @brief Common namespace for CSC232 identifiers.
 */
namespace csc232
{
#if FINISHED_PART_1

//declaring the dog interface.
class Dog
{
    public: 
//speak and sit methods followed by default constructor.
    virtual std::string speak() const = 0;
    virtual void sit() const = 0;
    virtual ~Dog() = default;
};
#endif // FINISHED_PART_1

#if FINISHED_PART_2
    //yorkie class referencing the dog interface.
    class Yorkie : public Dog
    {
        public:
        //public yorkie methods
        Yorkie(const std::string& dogs_name);
        std::string speak() const override;
        void sit() const override;

        private:
        //the private string that protects the name(s) of the dog(s)
        std::string name;
    };
 
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    //the following are the actual definitions of the methods for both yorkie and great daehn.
    Yorkie::Yorkie(const std::string& dogs_name) : name{ dogs_name }
    {
    std::cout << "A Yorkie named" << name << " was just created." << std::endl;
    }

    std::string Yorkie::speak() const
    {
    std::string response{ "DID YOU SAY SPEAK?" };
    //This return was needed in order to pass the tests as the method needed to return something. The same goes for great daehn.
    return response;
    }

    void Yorkie::sit() const
    {
    std::cout << "A Yorkie named " << name << " just sat down." << std::endl;
    }
   
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    //This is essentially a copy of yorkie but modified for the great daehn.
    class GreatDaehn : public Dog
    {
        public: 
        GreatDaehn(const std::string& dogs_name);
        std::string speak() const override;
        void sit() const override;

        private:
        std::string name;
    };
    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    GreatDaehn::GreatDaehn(const std::string& dogs_name) : name{dogs_name}
    {
        std::cout << "A GreatDaehn named" << name << "was just created. " << std::endl;
    }

    std::string GreatDaehn::speak() const
    {
        std::string response{ "What?" };
        return response;
    }

    void GreatDaehn::sit() const
    {
    std::cout << "A GreatDaehn named " << name << " just sat down." << std::endl;
    }
    
    
#endif // FINISHED_PART_2

    // DO NOT Modify anything below this line

    /**
     * @brief A string utility function that determines if some string ends with some other string.
     * @param main_str the string potentially end with to_match
     * @param to_match a substring sought at the end of main_str
     * @return true if main_str ends with to_match, false otherwise.
     */
    bool StringEndsWith ( const std::string& main_str, const std::string& to_match )
    {
        auto it = to_match.begin( );
        return main_str.size( ) >= to_match.size( ) &&
               std::all_of( std::next( main_str.begin( ), main_str.size( ) - to_match.size( ) ), main_str.end( ),
                            [ &it ] ( const char& c ) {
                                return c == *( it++ );
                            } );
    }
} // namespace csc232

#endif // CSC232_COMMON_H_
