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


float Weight::getWeight	()	const noexcept {
    return Weight::Weight();
}


















