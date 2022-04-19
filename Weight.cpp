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


#include <iostream>
#include <stdexcept>
#include <iomanip>



#include "Weight.h"

using namespace std;


/////////// Weight Values ///////////////////////////////////////////////
const float Weight::UNKNOWN_WEIGHT = -1 ;
const float Weight::KILOS_IN_A_POUND = 0.453592 ;
const float Weight::SLUGS_IN_A_POUND = 0.031081 ;




/////////// Weight Constructors //////////////////////////////////////////////

Weight::Weight() noexcept {
    unitOfWeight = POUND;
    weight = UNKNOWN_WEIGHT ;
    maxWeight = UNKNOWN_WEIGHT ;
    bIsKnown = false;
}

Weight::Weight(float newWeight) {
    setWeight( newWeight);
    bIsKnown = true; /// Weight is known
}

Weight::Weight( UnitOfWeight newUnitOfWeight) noexcept { ///// unit of weight
    unitOfWeight= newUnitOfWeight ;
}

Weight::Weight(float newWeight, const Weight::UnitOfWeight newUnitOfWeight): Weight( newUnitOfWeight ) {
    setWeight( newWeight ) ;
    setWeight( newUnitOfWeight );
}

Weight::Weight(float newWeight, float newMaxWeight) {
    setWeight( newWeight );
    setMaxWeight( newMaxWeight );
    bHasMax = true;
    }


Weight::Weight(const Weight::UnitOfWeight newUnitOfWeight, const float newMaxWeight):Weight ( newUnitOfWeight ) {
    setMaxWeight( newMaxWeight );
    if(newMaxWeight <= 0) {
        throw std::out_of_range("The new max weight cannot be less than or equal to zero");
    }
}

Weight::Weight(float newWeight, const Weight::UnitOfWeight newUnitOfWeight, const float newMaxWeight):Weight( newUnitOfWeight, newMaxWeight ) {
    setWeight(newWeight);
    setMaxWeight(newMaxWeight);
}


/// Once UnitOfWeight is set, it can't be changed.
/// Once maxWeight is set, it can't be changed.

/////////////// dump /////////////////

    void Weight::dump() const noexcept {

#define FORMAT_LINE(className, member) cout << setw(8) << (className) << setw(20) << (member) << setw(52)
        cout << setw(80) << setfill('=') << "" << endl;
        cout << setfill(' ');
        cout << left;
        cout << boolalpha;

        FORMAT_LINE("Weight", "isKnown") << isWeightKnown() << endl;
        FORMAT_LINE("Weight", "weight") << getWeight() << endl;
        FORMAT_LINE("Weight", "unitOfWeight") << getWeightUnit() << endl;
        FORMAT_LINE("Weight", "hasMax") << hasMaxWeight() << endl;
        FORMAT_LINE("Weight", "maxWeight") << getMaxWeight() << endl;

    }


/////////////////// Weight Conversions //////////////////////

    float Weight::fromKilogramToPound(const float kilogram) noexcept {
        return kilogram / KILOS_IN_A_POUND;
    }

    float Weight::fromPoundToKilogram(const float pound) noexcept {
        return pound * KILOS_IN_A_POUND;
    }

    float Weight::fromSlugToPound(const float slug) noexcept {
        return slug / SLUGS_IN_A_POUND;
    }

    float Weight::fromPoundToSlug(const float pound) noexcept {
        return pound * SLUGS_IN_A_POUND;
    }


    float Weight::convertWeight(float fromWeight, Weight::UnitOfWeight fromUnit, Weight::UnitOfWeight toUnit) {
        if (toUnit == KILO) {
            if (fromUnit == POUND) {
                return fromPoundToKilogram(fromWeight);
            }
            if (fromUnit == SLUG) {
                return fromPoundToKilogram(fromSlugToPound(fromWeight));
            }
        }
        if (toUnit == POUND) {
            if (fromUnit == KILO) {
                return fromKilogramToPound(fromWeight);
            }
            if (fromUnit == SLUG) {
                return fromSlugToPound(fromWeight);
            }
        }
        if (toUnit == SLUG) {
            if (fromUnit == POUND) {
                return fromPoundToSlug(fromWeight);
            }
            if (fromUnit == KILO) {
                return fromPoundToSlug(fromKilogramToPound(fromWeight));
            }
        }
        throw logic_error("Invalid Units");
    }


///////// Labels ///////////////////

    const string Weight::KILO_LABEL = "Kilo";

    const string Weight::POUND_LABEL = "Pound";

    const string Weight::SLUG_LABEL = "Slug";

/////////////////// Weight Getters //////////////////

    float Weight::getWeight() const noexcept {
        if (!bIsKnown) {
            return UNKNOWN_WEIGHT;
        }
        return weight;
    }

    float Weight::getWeight(UnitOfWeight weightUnits) const noexcept {
        if (bIsKnown) {
            cout << "Weight cannot be converted" << endl;
        }
        return convertWeight(getWeight(), getWeightUnit(), weightUnits);
    }


    float Weight::getMaxWeight() const noexcept {
        if (!bHasMax) {
            return UNKNOWN_WEIGHT;
        }
        return maxWeight;
    }

    Weight::UnitOfWeight Weight::getWeightUnit() const noexcept {
        return unitOfWeight;
    }


/////////// Booleans ///////////

    bool Weight::isWeightKnown() const {
        if (!bIsKnown) {
            return false;
        }
        return true;
    }

    bool Weight::hasMaxWeight() const {
        if (!bHasMax) {
            return false;
        }
        return true;
    }

    bool Weight::isWeightValid(float checkWeight) const noexcept {
        if (checkWeight <= 0 && checkWeight < maxWeight) {
            cout << "Weight is not valid" << endl;
        }
        return true;
    }

///////////////// Operators /////////////////////////////////////////////
    bool Weight::operator==(const Weight &rhs_Weight) const {
        /// Remember to convert the two weight's units into a common unit!
        /// Treat unknown weights as 0 (so we can sort them without dealing
        /// with exceptions)
        float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
        float rhs_weight = (rhs_Weight.bIsKnown) ?
                           rhs_Weight.getWeight(Weight::POUND) : 0;

        return lhs_weight == rhs_weight;
    }

    bool Weight::operator<(const Weight &rhs_Weight) const {

        float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
        float rhs_weight = (rhs_Weight.bIsKnown) ?
                           rhs_Weight.getWeight(Weight::POUND) : 0;

        return lhs_weight < rhs_weight;
    }
///////////////////// Ostream ///////////////////////
ostream &operator<<(ostream &lhs_stream, const Weight::UnitOfWeight rhs_UnitOfWeight) {
        switch (rhs_UnitOfWeight) {
            case Weight::KILO:
                return lhs_stream << Weight::KILO_LABEL;
            case Weight::POUND:
                return lhs_stream << Weight::POUND_LABEL;
            case Weight::SLUG:
                return lhs_stream << Weight::SLUG_LABEL;
            default:
                throw out_of_range(" Unit isn't mapped to any string");
        }
    }
////////////////// Voids ////////////////////////////////////


    void Weight::setWeight(float newWeight) {
        isWeightValid(newWeight);
        weight = newWeight;
        bIsKnown = true;
    }

    void Weight::setWeight(float newWeight, Weight::UnitOfWeight weightUnits) {
        isWeightValid(newWeight);
        Weight:
        weight = newWeight;
        Weight::unitOfWeight = weightUnits;
        bIsKnown = true;

    }


    void Weight::setMaxWeight(float newMaxWeight) {
        Weight:
        weight = newMaxWeight;
        bHasMax = true;
    }


    bool Weight::validate() {
        if (weight <= 0) {
            throw invalid_argument("The weight must be greater than 0");
        }
        return true;
    }











