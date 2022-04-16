///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file Weight.h
/// @version 1.0
///
/// @author @Byron Soriano <@byrongs@hawaii.edu>
/// @date   16_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <cassert>
#include <stdexcept>

#ifndef EE205_LAB12A_FATCAT_WEIGHT_H
#define EE205_LAB12A_FATCAT_WEIGHT_H

#endif //EE205_LAB12A_FATCAT_WEIGHT_H

using namespace std;

class Weight {
//////////////////////// Public Types /////////////////////////////
public:
    enum UnitOfWeight {POUND , KILO , SLUG };


    Weight() noexcept;

    Weight (float newWeight);

    Weight (UnitOfWeight newUnitOfWeight) noexcept ;

    Weight (float newWeight, UnitOfWeight newUnitOfWeight) ;

    Weight (float newWeight, float newMaxWeight) ;

    Weight (UnitOfWeight newUnitOfWeight, float newMaxWeight) ;

    Weight (float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight) ;

public:

    bool isWeightKnown () const noexcept ;

    bool hasMaxWeight () const noexcept ;

public: ////////////////// Getters and Setters //////////////////////

    float 	getWeight () const noexcept ;

    float 	getWeight (UnitOfWeight weightUnits) const noexcept ;

    float 	getMaxWeight () const noexcept ;

    UnitOfWeight getWeightUnit () const noexcept ;

    void 	setWeight (float newWeight) ;

    void 	setWeight (float newWeight, UnitOfWeight weightUnits) ;

    bool 	isWeightValid (float checkWeight) const noexcept ;

    bool 	validate () const noexcept ;

    void 	dump () const noexcept ;

    bool 	operator== (const Weight &rhs_Weight) const ;

    bool 	operator< (const Weight &rhs_Weight) const ;

    Weight & 	operator+= (float rhs_addToWeight) ;

public: /////////// Static Public Member Functions ////////////////////

    static float 	fromKilogramToPound (float kilogram) noexcept ;

    static float 	fromPoundToKilogram (float pound) noexcept ;

    static float 	fromSlugToPound (float slug) noexcept ;

    static float 	fromPoundToSlug (float pound) noexcept ;

    static float 	convertWeight (float fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit) noexcept ;

public: ////////// Static Public Attributes //////////////////////////

    static const float 	UNKNOWN_WEIGHT = -1 ;
    static const float 	KILOS_IN_A_POUND = 0.453592 ;
    static const float 	SLUGS_IN_A_POUND = 0.031081 ;
    static const std::string POUND_LABEL = "Pound" ;
    static const std::string KILO_LABEL = "Kilo" ;
    static const std::string SLUG_LABEL = "Slug" ;

private: ///////////// Private Member Functions ////////////////////

    void 	setMaxWeight (float newMaxWeight) ;

private: //////////// Private Attributes //////////////////////////

    bool 	bIsKnown = false ;
    bool 	bHasMax = false ;

    enum UnitOfWeight 	unitOfWeight = POUND ;

    float 	weight {} ;
    float 	maxWeight {} ;










};

Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) : Weight() {
    setWeight( newWeight );
    setWeight( newUnitOfWeight ) ;
    setWeight( newMaxWeight ) ;

    assert( validate() ) ;


}


