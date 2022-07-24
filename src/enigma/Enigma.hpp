
#ifndef ENIGMA_HPP
#define ENIGMA_HPP

#include "Reflector.hpp"
#include "Rotor.hpp"

#include <algorithm>
#include <exception>
#include <iostream>
#include <stdexcept>

namespace LyingCak3
{

namespace Enigma
{

template< size_t N >
class Enigma
{

public:

    void InstallRotor( size_t index, Rotor* rotor )
    {
        rotors_[ index ] = rotor;
    }

    void InstallReflector( Reflector* reflector )
    {
        reflector_ = reflector;
    }

    size_t ProcessChiper( size_t input )
    {

        for ( size_t i = 0; i < N; ++i )
        {

            if ( 0 == rotors_[ i ] )
            {

                throw std::runtime_error( "Rotor(s) not defined." );
                
            }

        }

        size_t result = input;
        rotors_[ 0 ]->notched = true;
        rotors_[ 0 ]->rotated = false;
        for ( size_t i = 1; i < N; ++i )
        {

            rotors_[ i ]->rotated = false; 
            rotors_[ i ]->notched = std::find( rotors_[ i ]->notchValues, 
                                                rotors_[ i ]->notchValues + rotors_[ i ]->numNotch, 
                                                rotors_[ i ]->GetCurrent() 
                                            ) != rotors_[ i ]->notchValues + rotors_[ i ]->numNotch;
        }

        rotors_[ 0 ]->Rotate();

        for ( size_t i = 1; i < N; ++i )
        {
            if ( true ==  rotors_[ i ]->notched )
            {
                
                rotors_[ i ]->Rotate();
                rotors_[ i - 1 ]->Rotate();

            }
        }

        for ( size_t i = 0; i < N; ++i )
        {
            result = rotors_[ i ]->GetValue( result );
        }

        result = reflector_->subsitutions[ result ];

        for ( int i = (N - 1); i >= 0; --i )
        {
            result = rotors_[ i ]->GetValue( result );
        }

        return result;

    }

protected:

private:

    Rotor      *rotors_[ N ];
    Reflector*  reflector_;

};

}

}

#endif
