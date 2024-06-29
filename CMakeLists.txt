cmake_minimum_required(VERSION 3.28)
project(untitled5)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled5 main.cpp
        Condiment.h
        Inventory.h
        Inventory.cpp
        Inventory.cpp
        main.cpp
        Feature.h
        KetchupFeature.h
        MustardFeature.h
        RelishFeature.h
        CondimentDecorator.h
        SpicyDecorator.h
        SweetDecorator.h
)
