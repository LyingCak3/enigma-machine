
#ifndef ENIGMA_HPP
#define ENIGMA_HPP

#include "Reflector.hpp"
#include "Rotor.hpp"


namespace LyingCak3
{

namespace Enigma
{

template< size_t N >
class Enigma
{

public:

    Enigma()
        : reflector_( 0 )
        {

            for ( size_t i = 0; i < N; ++i )
            {
                rotors_[ i ] = 0;
            }

        }

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

                return 0;
                
            }

        }

        if ( 0 == reflector_ )
        {
            return 0;
        }

        size_t result = input;
        for ( size_t i = 0; i < N; ++i )
        {

            rotors_[ i ]->InitializeCycle();
        }

        rotors_[ 0 ]->Rotate();

        for ( size_t i = 1; i < N; ++i )
        {
            if ( true ==  rotors_[ i - 1 ]->notched )
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
