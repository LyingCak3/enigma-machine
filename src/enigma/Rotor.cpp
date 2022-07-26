
#include "Rotor.hpp"

#include <algorithm>

void LyingCak3::Enigma::Rotor::InitializeCycle()
{

    rotated = false; 
    notched = std::find( notchValues, 
                                        notchValues + numNotch, 
                                        GetCurrent() 
                                    ) != notchValues + numNotch;

}

size_t LyingCak3::Enigma::Rotor::GetCurrent()
{

    return values_[ offset_ % numValues ];

}

size_t LyingCak3::Enigma::Rotor::GetValue( size_t index )
{
    index = index + offset_;

    index = index % numValues;

    return values_[ index ];

}

void LyingCak3::Enigma::Rotor::Rotate()
{

    if ( false == rotated )
    {

        rotated = true;
        offset_ = ( ++offset_ ) % ( numValues + 1 );

    }
}