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


    Weight() noexcept; /// a default weight
    Weight (float newWeight); /// a weight with value
    Weight (UnitOfWeight newUnitOfWeight) noexcept ; /// a weight with unit of weight
    Weight (float newWeight, UnitOfWeight newUnitOfWeight) ; /// a weight with a value and new unit of weight
    Weight (float newWeight, float newMaxWeight) ; /// a weight with value and maximum weight
    Weight (UnitOfWeight newUnitOfWeight, float newMaxWeight) ; /// A weight with a UnitOfWeight and a maximum weight
    Weight (float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight) ; /// A weight with a value, UnitOfWeight and a maximum weight

public:

    bool isWeightKnown () const ;

    bool hasMaxWeight () const  ;

public: ////////////////// Getters and Setters //////////////////////

    float   getWeight () const noexcept ;

    float 	getWeight (UnitOfWeight weightUnits) const noexcept ;

    float 	getMaxWeight () const noexcept ;

    UnitOfWeight getWeightUnit () const noexcept ;

    void 	setWeight (float newWeight) ;

    void 	setWeight (float newWeight, UnitOfWeight weightUnits) ;

    bool 	isWeightValid (float checkWeight) const noexcept ;

    bool 	validate () ;

    void 	dump() const noexcept ;

    bool 	operator== (const Weight &rhs_Weight) const ;

    bool 	operator< (const Weight &rhs_Weight) const ;

    Weight &operator+=(float rhs_addToWeight) ;

public: /////////// Static Public Member Functions ////////////////////

    static float 	fromKilogramToPound (float kilogram) noexcept ;

    static float 	fromPoundToKilogram (float pound) noexcept ;

    static float 	fromSlugToPound (float slug) noexcept ;

    static float 	fromPoundToSlug (float pound) noexcept ;

    static float 	convertWeight (float fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit) ;


public: ////////// Static Public Attributes //////////////////////////

    static const float 	UNKNOWN_WEIGHT;
    static const float 	KILOS_IN_A_POUND;
    static const float 	SLUGS_IN_A_POUND;
    static const std::string POUND_LABEL;
    static const std::string KILO_LABEL;
    static const std::string SLUG_LABEL;

private: ///////////// Private Member Functions ////////////////////

    void 	setMaxWeight (float newMaxWeight) ;

private: //////////// Private Attributes //////////////////////////

    bool 	bIsKnown = false ;
    bool 	bHasMax = false ;

    enum UnitOfWeight 	unitOfWeight = POUND ;

    float 	weight {} ;
    float 	maxWeight {} ;



};

//Weight &Weight::operator+=(float rhs_addToWeight) {
    //return <#initializer#>;
//}






















































