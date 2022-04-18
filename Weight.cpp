///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file Weight.cpp
/// @version 1.0
///
/// @author @Byron Soriano <@byrongs@hawaii.edu>
/// @date   16_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "Weight.h"



/////////// Weight Constructors //////////////////////////////////////////////


Weight::Weight	(	const Weight::UnitOfWeight 	newUnitOfWeight	) noexcept ;

Weight::Weight	( float newWeight, const Weight::UnitOfWeight 	newUnitOfWeight ) ;

Weight::Weight	( float newWeight, float newMaxWeight )	;

Weight::Weight	( const Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight ) ;

Weight::Weight	( float newWeight, const Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) ;

void Weight::dump()const ;



/////////////////// Weight Conversions //////////////////////

float Weight::fromKilogramToPound(const float kilogram) noexcept {
    return kilogram / KILOS_IN_A_POUND ;
}

float Weight::fromPoundToKilogram(const float pound) noexcept {
    return pound * KILOS_IN_A_POUND ;
}

float Weight::fromSlugToPound(const float slug) noexcept {
    return slug / SLUGS_IN_A_POUND ;
}

float Weight::fromPoundToSlug(const float pound) noexcept {
    return pound * SLUGS_IN_A_POUND ;
}

float fromWeight ;
char fromUnit ;
char toUnit ;

float Weight::convertWeight(float fromWeight, Weight::UnitOfWeight fromUnit, Weight::UnitOfWeight toUnit) noexcept {
    return fromWeight, fromUnit, toUnit ;
}


///////// Labels ///////////////////

const string Weight::KILO_LABEL = "Kilo" ;

const string Weight::POUND_LABEL = "Pound" ;

const string Weight::SLUG_LABEL = "Slug" ;

//////////////////////// Weight Setters //////////////////

Weight Weight::getWeight() const noexcept {
    return Weight();
}

Weight::Weight(float newWeight) {
    setWeight( newWeight ) ;
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight) noexcept {
    setWeight( newUnitOfWeight ) ;
}

Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight) {
    setWeight( newWeight ) ;
    setWeight( newUnitOfWeight ) ;
}

Weight::Weight(float newWeight, float newMaxWeight) {
    setWeight( newWeight ) ;
    setWeight( newMaxWeight ) ;
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    setWeight( newUnitOfWeight ) ;
    setWeight( newMaxWeight ) ;
}

Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) : Weight() {
    setWeight( newWeight );
    setWeight( newUnitOfWeight ) ;
    setWeight( newMaxWeight ) ;

    assert( validate() ) ;
}



