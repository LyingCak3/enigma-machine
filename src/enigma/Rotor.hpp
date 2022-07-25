
#ifndef ENIGMA_ROTOR_HPP
#define ENIGMA_ROTOR_HPP

#include <stddef.h>

namespace LyingCak3
{

namespace Enigma
{

class Rotor
{

public:

    Rotor()
        : notchValues( 0 )
        , numValues( 0 )
        , numNotch( 0 )
        , notched( false )
        , rotated( false )
        , values_( 0 )
        , offset_( 0 )
        {};

    template< size_t N, size_t K >
    Rotor( const size_t v[][ N ], const size_t nv[][ K ] )
        : notchValues( *nv )
        , numValues( N )
        , numNotch( K )
        , notched( false )
        , rotated( false )
        , values_( *v )
        , offset_( 0 )
        {};

    void InitializeCycle();

    size_t GetCurrent();

    size_t GetValue( size_t index );

    size_t GetOffset() { return offset_; }

    void Rotate();

    const size_t*       notchValues;
    const size_t        numValues;
    const size_t        numNotch;
    bool                notched;
    bool                rotated;

protected:
    const size_t* values_;
    size_t        offset_;
};

}

}

#endif
