#include <iostream>

#include "Weight.h"

int main() {

    Weight defaultWeight = Weight();
    defaultWeight.dump();


    Weight weight1 = Weight(340, 350);
    weight1.validate();
    weight1.dump();

    Weight weight2 = Weight(2, Weight::SLUG, 20);
    weight2.dump();

    Weight weight3 = Weight(Weight::POUND);
    weight3.dump();
}
