#!/bin/bash

mkdir -p at_corder/$1
cp template.cpp at_corder/$1/$2.cpp
code at_corder/$1/$2.cpp
