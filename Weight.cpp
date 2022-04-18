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

using namespace std;

/////////// Weight Constructors //////////////////////////////////////////////

Weight::Weight() noexcept {
    unitOfWeight = POUND;
    weight = UNKNOWN_WEIGHT ;
    maxWeight = UNKNOWN_WEIGHT ;
}

Weight::Weight(float newWeight) {
    unitOfWeight = POUND ;
    weight = UNKNOWN_WEIGHT ;
    maxWeight = UNKNOWN_WEIGHT ;
    bIsKnown = true;
    if(!isWeightValid(newWeight)) {
        throw std::out_of_range("The weight cannot be less than or equal to zero");
    }
}

Weight::Weight(const Weight::UnitOfWeight newUnitOfWeight) noexcept {
    unitOfWeight= POUND ;
    weight = UNKNOWN_WEIGHT ;
    maxWeight = UNKNOWN_WEIGHT
}

Weight::Weight(float newWeight, const Weight::UnitOfWeight newUnitOfWeight) {
    unitOfWeight = POUND ;
    weight = UNKNOWN_WEIGHT ;
    bIsKnown = true;
    if(!isWeightValid(newWeight)) {
        throw std::out_of_range("The weight cannot be less than or equal to zero");
    }
}
Weight::Weight(float newWeight, float newMaxWeight) {
    unitOfWeight = POUND ;
    weight = UNKNOWN_WEIGHT ;
    maxWeight = newMaxWeight ;
    bIsKnown = true ;
    if(!isWeightValid(newWeight)) {
        throw std::out_of_range("The weight cannot be less than or equal to zero");
    }
    if(newMaxWeight <= 0) {
        throw std::out_of_range("The new max weight cannot be less than or equal to zero");
    }
}

Weight::Weight(const Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    unitOfWeight = POUND ;
    weight = UNKNOWN_WEIGHT ;
    newMaxWeight = newMaxWeight ;
    bHasMax = true;
    if(newMaxWeight <= 0) {
        throw std::out_of_range("The new max weight cannot be less than or equal to zero");
    }
}
Weight::Weight(float newWeight, const Weight::UnitOfWeight newUnitofWeight, float newMaxWeight) {
    unitOfWeight = POUND ;
    weight = UNKNOWN_WEIGHT ;
    maxWeight = newMaxWeight ;
    bIsKnown = true;
    bHasMax = true;
    if(!isWeightValid(newWeight)) {
        throw std::out_of_range("The weight cannot be less than or equal to zero");
    }
    if(newMaxWeight <= 0) {
        throw std::out_of_range("The max weight cannot be less than or equal to zero");
    }
}

/// Once UnitOfWeight is set, it can't be changed.
/// Once maxWeight is set, it can't be changed.
Weight::Weight( const Weight::UnitOfWeight newUnitOfWeight, const float newMaxWeight ) : Weight( newUnitOfWeight ) {
    setMaxWeight( newMaxWeight );
    assert( validate() );
}

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


float Weight::convertWeight(float fromWeight, Weight::UnitOfWeight fromUnit, Weight::UnitOfWeight toUnit) noexcept {
    if( toUnit == KILO ) {
        if( fromUnit == POUND ) {
            return fromPoundToKilogram(fromWeight) ;
        }
        if( fromUnit == SLUG ) {
            return fromPoundToKilogram(fromSlugToPound( fromWeight ) );
        }
    }
    if( toUnit == POUND ) {
        if( fromUnit == KILO ) {
            return fromKilogramToPound( fromWeight ) ;
        }
        if( fromUnit == SLUG ) {
            return fromSlugToPound( fromWeight) ;
        }
    }
    if( toUnit == SLUG ) {
        if( fromUnit == POUND ) {
            return fromPoundToSlug( fromWeight ) ;
        }
        if( fromUnit == KILO ) {
            return fromPoundToSlug(fromKilogramToPound(fromWeight) ) ;
        }
    }
}


///////// Labels ///////////////////

const string Weight::KILO_LABEL = "Kilo" ;

const string Weight::POUND_LABEL = "Pound" ;

const string Weight::SLUG_LABEL = "Slug" ;

//////////////////////// Weight Setters //////////////////

Weight Weight::getWeight() const noexcept {
    return Weight();
}

Weight::setWeight(float newWeight) {
    setWeight( newWeight ) ;
}

Weight::setWeight(Weight::UnitOfWeight newUnitOfWeight) noexcept {
    setWeight( newUnitOfWeight ) ;
}

Weight::setWeight(float newWeight, Weight::UnitOfWeight newUnitOfWeight) {
    setWeight( newWeight ) ;
    setWeight( newUnitOfWeight ) ;
}

Weight::setWeight(float newWeight, float newMaxWeight) {
    setWeight( newWeight ) ;
    setWeight( newMaxWeight ) ;
}

Weight::setWeight(Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    setWeight( newUnitOfWeight ) ;
    setWeight( newMaxWeight ) ;
}

Weight::setWeight(float newWeight, Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) : Weight() {
    setWeight( newWeight );
    setWeight( newUnitOfWeight ) ;
    setWeight( newMaxWeight ) ;

    assert( validate() ) ;
}

/////////// Booleans ///////////

bool Weight::isWeightKnown() const noexcept {
    if(!isWeightKnown() ) {
        throw invalid_argument(" The weight must be known")
    }
    return true;
}

bool Weight::hasMaxWeight() const noexcept {
    if(!hasMaxWeight() ) {
        throw invalid_argument(" The maximum weight must be known")
    }
    return true;
}

bool Weight::isWeightValid(float checkWeight) const noexcept {
    if( bHasMax ) {
        checkWeight <= maxWeight
    }
}

void Weight::dump() const noexcept {

}
///////////////// Operators /////////////////////////////////////////////
bool Weight::operator==( const Weight& rhs_Weight ) const {
    /// Remember to convert the two weight's units into a common unit!
    /// Treat unknown weights as 0 (so we can sort them without dealing
    /// with exceptions)
    float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.bIsKnown) ?
                       rhs_Weight.getWeight(Weight::POUND) : 0;

    return lhs_weight == rhs_weight;
}

bool Weight::operator<( const Weight& rhs_Weight ) const {

    float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.bIsKnown) ?
                       rhs_Weight.getWeight(Weight::POUND) : 0;

    return lhs_weight < rhs_weight ;
}







//////////////// Getters and Setters Defined //////////////////////////////////////

float Weight::getWeight(Weight::UnitOfWeight weightUnits) const noexcept {
    return weightUnits;
}

float Weight::getMaxWeight() const noexcept {
    if(newMaxWeight()) {
        return maxWeight ;
    }
    return UNKNOWN_WEIGHT ;
}

Weight::UnitOfWeight Weight::getWeightUnit() const noexcept {
    return Weight::POUND;
}

void Weight::setWeight(float newWeight) {
    validate( newWeight ) ;
    Weight:Weight = newWeight ;
}

void Weight::setWeight(float newWeight, Weight::UnitOfWeight weightUnits) {
    validate( newWeight ) ;
    Weight:Weight = newWeight ;

}


void Weight::setMaxWeight(float newMaxWeight) {
    if(newMaxWeight <= 0 ) {
        throw invalid_argument( "Max weight must be greater than zero")
    }
    Weight:Weight = newMaxWeight ;
}



bool Weight::validate() const noexcept {
    if( weight <= 0 ) {
        throw invalid_argument("The weight must be > 0");
    }
    return true ;
}

///////// Line Formatting //////////////////////////////////

#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) (member) <<setw(52)

///////////////// dump() //////////////////////////////////
void Weight::dump() const noexceppt {
    cout << "Weight test( 130, Weight::KILO, 29)" << endl;
    cout << setw(80) << setfill('=') << "" << endl;
    cout << setfill( ' ' );
    cout << left;
    cout << boolalpha;


FORMAT_LINE( "Weight", "isKnown" ) << isWeightKnown() << endl;
FORMAT_LINE( "Weight", "weight" ) << getWeight() << endl;
FORMAT_LINE( "Weight", "unitOfWeight" ) << getWeightUnit << endl;
FORMAT_LINE( "Weight", "hasMax" ) << hasMaxWeight() << endl;
FORMAT_LINE( "Weight", "maxWeight" ) << getMaxWeight() << endl;

}

///////////////////////////////
