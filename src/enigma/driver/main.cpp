
#include "Enigma.hpp"

#include <iostream>

const size_t ROTOR_1_VALUES[ 5 ] = { 0, 1, 2, 3, 4 };
const size_t ROTOR_2_VALUES[ 5 ] = { 3, 2, 1, 4, 0 };
const size_t ROTOR_3_VALUES[ 5 ] = { 2, 4, 0, 1, 3 };

const size_t ROTOR_1_NOTCHES[ 1 ] = { 3 };
const size_t ROTOR_2_NOTCHES[ 1 ] = { 4 };
const size_t ROTOR_3_NOTCHES[ 1 ] = { 1 };

const size_t REFLECTOR_VALUES[ 5 ] = { 4, 3, 1, 0, 2 };

int main(int argc, char const *argv[])
{
    
    LyingCak3::Enigma::Enigma< 3 > enigma;
    LyingCak3::Enigma::Reflector reflector = { REFLECTOR_VALUES };

    enigma.InstallRotor( 0, new LyingCak3::Enigma::Rotor( &ROTOR_1_VALUES, &ROTOR_1_NOTCHES ) );
    enigma.InstallRotor( 1, new LyingCak3::Enigma::Rotor( &ROTOR_2_VALUES, &ROTOR_2_NOTCHES ) );
    enigma.InstallRotor( 2, new LyingCak3::Enigma::Rotor( &ROTOR_3_VALUES, &ROTOR_3_NOTCHES ) );
    enigma.InstallReflector( &reflector );

    size_t input = 1;

    std::cout << "Input: " << input << ", Output: " << enigma.ProcessChiper( input ) << std::endl;

    return 0;
}
