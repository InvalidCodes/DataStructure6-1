//
// Created by Ge on 2023/3/29.
//

#ifndef CHAPTER6_1_INFORMATION_H
#define CHAPTER6_1_INFORMATION_H

#include <string>

class Information {
public:
private:
    ///> 整数数据类
    enum IntegerDataType {
        age_,
        height_,
    };

    ///> bool数据类
    enum class BoolDataType : bool {
        gender_,  // female:1, male:0
        live_or_not_,  // alive:1; dead:0
    };

    ///> string数据
    std::string name_,
                birthday_,
                birth_place_,
                education_,
                job_,
                death_date_;
};

#endif //CHAPTER6_1_INFORMATION_H
