//
// Created by Ge on 2023/3/29.
//

#ifndef CHAPTER6_1_INFORMATION_H
#define CHAPTER6_1_INFORMATION_H

#include <string>

class Information {
public:
private:
    ///> Integer class.
    enum IntegerDataType {
        age_,
        height_
    };

    ///> Bool class.
    enum class BoolDataType : short {
        gender_,  // female:1, male:0
        live_or_not_,  // alive:1; dead:0
        married_or_not_,  // married:1; unmarried:0; divorced:2; lost of couple: 3
    };

    ///> Relationship class.
    enum class Relationship{
        parent_,
        sibling,
        cousin
    };

    ///> String type data.
    std::string name_,
                birthday_,
                birth_place_,
                address_,
                education_,
                job_,
                death_date_;
};

#endif //CHAPTER6_1_INFORMATION_H
