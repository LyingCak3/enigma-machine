
#include "Enigma.hpp"

#include <iostream>

const size_t ROTOR_1_VALUES[ 88 ] = { 57, 50, 61, 86, 48, 9, 31, 27, 34, 84, 76, 49, 51, 4, 2, 43, 22, 20, 36, 37, 69, 29, 63, 65, 28, 80, 19, 10, 81, 66, 21, 85, 41, 87, 53, 38, 32, 56, 77, 73, 14, 16, 6, 75, 15, 11, 74, 64, 18, 35, 7, 59, 8, 42, 40, 55, 39, 68, 52, 30, 23, 0, 1, 33, 70, 79, 12, 17, 72, 26, 82, 3, 54, 25, 71, 78, 67, 62, 47, 83, 45, 60, 5, 58, 24, 46, 44, 13 };
const size_t ROTOR_2_VALUES[ 88 ] = { 42, 21, 29, 17, 73, 47, 67, 85, 32, 24, 63, 13, 59, 23, 6, 25, 45, 60, 3, 33, 66, 51, 11, 39, 83, 65, 68, 27, 78, 54, 4, 48, 53, 40, 76, 72, 10, 70, 75, 41, 37, 16, 15, 38, 79, 8, 87, 82, 22, 14, 56, 64, 52, 18, 9, 71, 30, 74, 81, 55, 2, 43, 44, 12, 20, 77, 84, 58, 19, 62, 1, 86, 50, 5, 61, 28, 0, 80, 26, 49, 69, 57, 35, 7, 46, 36, 34, 31 };
const size_t ROTOR_3_VALUES[ 88 ] = { 10, 5, 39, 63, 59, 58, 80, 28, 0, 35, 25, 49, 55, 66, 26, 15, 2, 83, 27, 87, 57, 67, 38, 51, 82, 14, 79, 69, 23, 50, 31, 70, 40, 74, 22, 37, 11, 20, 6, 32, 73, 33, 17, 47, 9, 86, 36, 43, 4, 78, 72, 29, 77, 13, 34, 54, 75, 42, 53, 19, 60, 65, 85, 52, 84, 64, 48, 18, 61, 24, 62, 8, 16, 21, 45, 56, 44, 41, 12, 76, 46, 3, 1, 71, 30, 68, 81, 7 };

const size_t ROTOR_1_NOTCHES[ 10 ] = { 87, 22, 74, 56, 51, 23, 53, 34, 72, 39 };
const size_t ROTOR_2_NOTCHES[ 10 ] = { 61, 56, 57, 85, 63, 24, 39, 37, 52, 30 };
const size_t ROTOR_3_NOTCHES[ 10 ] = { 41, 78, 36, 73, 16, 51, 60, 42, 39, 27 };

const size_t REFLECTOR_VALUES[ 88 ] = { 13, 55, 53, 12, 50, 7, 49, 52, 26, 32, 39, 14, 15, 6, 3, 43, 1, 80, 61, 38, 71, 63, 82, 34, 60, 20, 0, 10, 70, 83, 23, 77, 18, 27, 79, 74, 87, 57, 5, 73, 54, 2, 81, 29, 86, 75, 62, 30, 59, 58, 48, 28, 72, 42, 19, 44, 76, 41, 33, 21, 67, 25, 56, 36, 68, 47, 37, 31, 9, 8, 64, 51, 66, 4, 11, 65, 78, 40, 24, 17, 46, 22, 84, 35, 45, 69, 85, 16 };

int main(int argc, char const *argv[])
{
    
    LyingCak3::Enigma::Enigma< 3 > enigma;
    LyingCak3::Enigma::Reflector reflector = { REFLECTOR_VALUES };

    enigma.InstallRotor( 0, new LyingCak3::Enigma::Rotor( &ROTOR_1_VALUES, &ROTOR_1_NOTCHES ) );
    enigma.InstallRotor( 1, new LyingCak3::Enigma::Rotor( &ROTOR_2_VALUES, &ROTOR_2_NOTCHES ) );
    enigma.InstallRotor( 2, new LyingCak3::Enigma::Rotor( &ROTOR_3_VALUES, &ROTOR_3_NOTCHES ) );
    enigma.InstallReflector( &reflector );

    size_t input[ 10 ] = { 67, 45, 36, 78, 27, 26, 10, 2, 50, 15 };

    size_t result = 0;
    for ( size_t i = 0; i < 10; ++i )
    {

        result = enigma.ProcessChiper( input[ i ] );
        std::cout << "Input: " << input[ i ] << ", Output: " << result << std::endl;

    }

    return 0;
}
