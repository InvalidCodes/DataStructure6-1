//
// Created by Ge on 2023/3/29.
//

#ifndef CHAPTER6_1_INFORMATION_H
#define CHAPTER6_1_INFORMATION_H

#include <string>
#include "syntactic-sugar.h"

class Information {
public:
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
    enum class Relationship {
        parent_,
        sibling,
        cousin
    };

    ///> String type data.
    std::string address_,
            education_,
            job_;

    ///> Read only.
    attr_reader_val(name_, Name)

    attr_reader_val(birthday_, Birthday)

    attr_reader_ref(birth_place_, BirthPlace)

    attr_reader_ref(death_date_, DeathDate)

private:
    std::string name_,
            birthday_,
            birth_place_,
            death_date_;
};

#endif //CHAPTER6_1_INFORMATION_H
